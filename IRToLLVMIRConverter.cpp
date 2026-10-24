
void IRToLLVMIRConverter::create_llvm_basic_blocks(IRFunction *current_fn) {
	m_llvm_basic_blocks.clear();
	const std::vector<IRBasicBlock*>& blks = current_fn->get_basic_blocks();
	m_llvm_basic_blocks.clear();
	m_llvm_block_map.clear();
	for (size_t i = 0; i < blks.size();i++) {
		std::string block_name = blks[i]->get_basic_blk_name();
		llvm::BasicBlock* llvm_blk = llvm::BasicBlock::Create(
			*m_context,
			block_name,
			m_current_fn
		);

		m_llvm_basic_blocks.push_back(llvm_blk);
		m_llvm_block_map.emplace(blks[i],llvm_blk);
	}

}

llvm::Value* IRToLLVMIRConverter::get_operand_value(const IROperand& op)  {
	switch (op.m_operand_type)
	{
	case IROperandType::CONSTANT: {
		size_t index = op.get_constant()->get_index();
		return m_llvm_constants.at(op.get_constant()->get_index());
	}
	case IROperandType::VARIABLE: {
		IRVariable* variable = op.get_variable();
		if (variable->is_global()) {
			llvm::GlobalVariable* global_variable_address = m_global_variables[variable->get_index()];
			return m_builder->CreateLoad(global_variable_address->getValueType(),global_variable_address);
		}

		return m_builder->CreateLoad(get_llvm_type(variable->get_data_type()),m_variables[variable->get_index()]);
	}
	case IROperandType::TRIPLE:
		return m_triple_values.at(op.get_triple()->get_global_index());
	case IROperandType::FUNCTION:
		return m_llvm_functions.at(op.get_function()->get_index());
	default:
		break;
	}
}

llvm::Value* IRToLLVMIRConverter::get_operand_address(const IROperand& op) {
	switch (op.m_operand_type)
	{
	case IROperandType::VARIABLE: {
		IRVariable* variable = op.get_variable();

		if (variable->is_global())
			return m_global_variables[variable->get_index()];

		return m_variables[variable->get_index()];
	}
	case IROperandType::TRIPLE: {
		IRTriple * triple = op.get_triple();

		IROperation operation = triple->get_ir_operation();
		if (operation == IROperation::DEREFERENCE)
			return get_operand_value(triple->m_operands[0]);
		else if (operation == IROperation::ARRAY_ACCESS || operation == IROperation::MEMBER_ACCESS) {
			// these two operations store addresses as their results
			return m_triple_values[triple->get_global_index()];
		}
		else {
			// all the other operations store actual values
			// so in order to get their address we create temproary allocation 
			llvm::Value* value = m_triple_values[triple->get_global_index()];
			llvm::Value* temporary = m_builder->CreateAlloca(
				value->getType(),
				nullptr,
				"temporary_rvalue_address"
			);
			m_builder->CreateStore(value, temporary);
			return temporary;
		}
		break;
	}
	default:
		throw std::runtime_error("operand has no address");
		break;
	}
}


void IRToLLVMIRConverter::convert_arithmetic_operation(llvm::Instruction::BinaryOps op_code,IRTriple *triple) {
	llvm::Value* left_value = get_operand_value(triple->m_operands[0]);
	llvm::Value* right_value = get_operand_value(triple->m_operands[1]);
	llvm::Value* calc_value = nullptr;
	llvm::Value* left_value_loaded = nullptr;

	calc_value = m_builder->CreateBinOp(op_code, left_value, right_value);
	m_triple_values[triple->m_global_index] = calc_value;
}

llvm::Value* IRToLLVMIRConverter::auto_cast(llvm::Value* src,llvm::Type* dstTy,bool srcIsSigned, bool dstIsSigned) {
	auto op = llvm::CastInst::getCastOpcode(src,srcIsSigned,dstTy,dstIsSigned);
	return m_builder->CreateCast(op, src, dstTy);
}

//it uses the one below
llvm::Type* IRToLLVMIRConverter::get_llvm_type(const TypeRef& type) const {
	TypeRef normalized_type = type.remove_reference().remove_qualifiers();
	
	if (normalized_type.is_pointer()) {
		return llvm::PointerType::get(*m_context, 0);
	}

	if (normalized_type.is_array()) {
		const TypeRef element_type_ref = normalized_type.remove_array().remove_qualifiers();
		llvm::Type* element_type = get_llvm_type(element_type_ref);
		IRArrayNode *array_node = static_cast<IRArrayNode*>(normalized_type.get_data_type_node());

		if (element_type_ref.is_numeric() || element_type_ref.is_boolean()) {
			return llvm::FixedVectorType::get(element_type,array_node->get_count());
		}
		else {
			return llvm::ArrayType::get(element_type, array_node->get_count());
		}
	}

	if (normalized_type.is_struct()) {
		IRStruct* struct_node = static_cast<IRStruct*>(normalized_type.get_data_type_node());
		
		if (struct_node->m_cached_llvm_type)
			return struct_node->m_cached_llvm_type;

		const std::vector<IRMember*> members = struct_node->get_members();
		std::vector<llvm::Type*> llvm_field_types;

		for (size_t i = 0; i < members.size();i++)
			llvm_field_types.push_back(get_llvm_type(members[i]->get_data_type()));
		
		if (!struct_node->m_cached_llvm_type)
			struct_node->m_cached_llvm_type = llvm::StructType::create(*m_context,llvm_field_types,struct_node->get_name());

		return struct_node->m_cached_llvm_type;
	}

	if (normalized_type.is_union()) {
		IRUnion* union_node = static_cast<IRUnion*>(normalized_type.get_data_type_node());

		if (union_node->m_cached_llvm_type)
			return union_node->m_cached_llvm_type;

		size_t union_size = union_node->calculate_size();

		// table allocation for the largest field in the union
		llvm::Type* byte_type = llvm::Type::getInt8Ty(*m_context);
		llvm::ArrayType* array_type = llvm::ArrayType::get(byte_type, union_size);

		std::vector<llvm::Type*> llvm_field_types = { array_type };
		union_node->m_cached_llvm_type = llvm::StructType::create(*m_context,llvm_field_types,union_node->get_name());

		return union_node->m_cached_llvm_type;
	}

	return get_llvm_type(normalized_type.get_ir_basic_type());
}

llvm::Type* IRToLLVMIRConverter::get_llvm_type(IRBasicType type) const {
	switch (type)
	{
	case IRBasicType::CHAR:
	case IRBasicType::INT8:
		return llvm::Type::getInt8Ty(*m_context);
	case IRBasicType::INT16:
		return llvm::Type::getInt16Ty(*m_context);
	case IRBasicType::INT32:
		return llvm::Type::getInt32Ty(*m_context);
	case IRBasicType::INT64:
		return llvm::Type::getInt64Ty(*m_context);
	case IRBasicType::UINT8:
		return llvm::Type::getInt8Ty(*m_context);
	case IRBasicType::UINT16:
		return llvm::Type::getInt16Ty(*m_context);
	case IRBasicType::UINT32:
		return llvm::Type::getInt32Ty(*m_context);
	case IRBasicType::UINT64:
		return llvm::Type::getInt64Ty(*m_context);
	case IRBasicType::FLOAT:
		return llvm::Type::getFloatTy(*m_context);
	case IRBasicType::DOUBLE:
		return llvm::Type::getDoubleTy(*m_context);
	case IRBasicType::BOOL:
		return llvm::Type::getInt1Ty(*m_context);
	case IRBasicType::VOID:
		return llvm::Type::getVoidTy(*m_context);
	default:
		throw std::runtime_error("no suitable data type");
		break;
	}
}

void IRToLLVMIRConverter::create_llvm_function(IRBaseFunction* current_fn) {
	llvm::FunctionType* function_type = get_llvm_function_type(current_fn);

	llvm::Value* llvm_callee = nullptr;
	if (current_fn->m_kind==IRBaseFunction::Kind::INTERNAL) {
		std::string name = FunctionNames::get_internal_name(current_fn->get_name());
		std::cout << "Internal " << name << std::endl;
		llvm::Function* llvm_function = llvm::Function::Create(
			function_type,
			llvm::Function::ExternalLinkage,
			name,
			m_module.get()
		);

		m_llvm_functions.at(current_fn->get_index()) = llvm_function;
		llvm_callee = llvm_function;
	}
	else {
		IRExternalFunction* external_fn = static_cast<IRExternalFunction*>(current_fn);
		if (!external_fn->m_fn_ptr)
			throw std::runtime_error("external function address is nullptr");
		llvm::ConstantInt* address = llvm::ConstantInt::get(
			llvm::Type::getInt64Ty(*m_context),
			reinterpret_cast<std::uintptr_t>(external_fn->m_fn_ptr)
		);

		llvm_callee = llvm::ConstantExpr::getIntToPtr(
			address,
			llvm::PointerType::get(*m_context, 0)
		);
	}

	m_function_callees.at(current_fn->get_index()) = llvm::FunctionCallee(function_type, llvm_callee);
}

IRToLLVMIRConverter::IRToLLVMIRConverter(IRProgram* ir_program) : m_ir_program{ ir_program } {
	size_t counter = 0;
	auto& fn_map = m_ir_program->get_functions();
	for (const auto& [name, vec_fn] : m_ir_program->get_functions())
		counter += vec_fn.size();

	for (const auto& [name,vec_fn] : m_ir_program->get_external_functions())
		counter += vec_fn.size();


	m_llvm_functions.resize(counter);
	m_function_callees.resize(counter);
	int triples_count = 0;
}

llvm::orc::ThreadSafeModule IRToLLVMIRConverter::convert() {
	m_module.reset();
	m_context = std::make_unique<llvm::LLVMContext>();
	m_module = std::make_unique<llvm::Module>("MyModule",*m_context);

	llvm::IRBuilder<> builder{ *m_context };
	m_builder = &builder;

	auto &functions = m_ir_program->get_functions();

	for (auto &global_variable : m_ir_program->get_global_variables()) {
		std::string name = global_variable->get_variable_name();
		TypeRef type = global_variable->get_data_type();

		llvm::Type* llvm_type = get_llvm_type(type);
		llvm::GlobalVariable* llvm_global_variable = llvm::cast<llvm::GlobalVariable>(m_module->getOrInsertGlobal(name, llvm_type));
		llvm_global_variable->setInitializer(
			llvm::Constant::getNullValue(llvm_type)
		);
		m_global_variables.push_back(llvm_global_variable);
	}



	for (auto &[name,fn_vec] : functions) {
		for (auto *fn : fn_vec)
			create_llvm_function(fn);
	}

	for (auto &[name,ext_fn_vec] : m_ir_program->get_external_functions()) {
		for (auto *fn : ext_fn_vec)
			create_llvm_function(fn);
	}

	for (const auto& [name,functions] : m_ir_program->get_functions()) {
		for (size_t i = 0; i < functions.size(); i++) {
			convert_function(functions[i]);
		}
	}

	if (llvm::verifyModule(*m_module, &llvm::errs())) {
		llvm::errs() << "Module verification failed!\n";
	}

	m_module->print(llvm::outs(), nullptr);
	m_builder = nullptr;

	return llvm::orc::ThreadSafeModule(std::move(m_module),std::move(m_context));
}


void print_llvm_type(llvm::Type * type) {
	if (!type) {
		llvm::outs() << "<nullptr>\n";
		return;
	}

	type->print(llvm::outs());
	llvm::outs() << '\n';
}

//auto broadcast_to_res = [&](llvm::Value* val, const TypeRef& t, size_t count) -> llvm::Value* {
//	if (!t.is_array())
//		return m_builder->CreateVectorSplat(res_count, val);
//	if (count == res_count)
//		return val;
//	std::vector<int> mask(res_count);
//	for (size_t i = 0; i < res_count; i++)
//		mask[i] = static_cast<int>(i % count);
//	return m_builder->CreateShuffleVector(val, llvm::UndefValue::get(val->getType()), mask);
//	};

llvm::Value* IRToLLVMIRConverter::expand_vector(llvm::Value* value,const TypeRef& type,size_t count,size_t result_count) {
	if (!type.is_array())
		return m_builder->CreateVectorSplat(result_count,value);

	if (count == result_count)
		return value;
	std::vector<int> mask(result_count);

	for (size_t i = 0; i < result_count;i++)
		mask[i] = static_cast<int>(i%count);

	return m_builder->CreateShuffleVector(value,llvm::UndefValue::get(value->getType()),mask);
}

void IRToLLVMIRConverter::convert_function(IRFunction* current_fn) {
	m_current_fn = m_llvm_functions.at(current_fn->get_index());
	m_llvm_constants.assign(current_fn->get_constants().size(),nullptr);
	m_variables.assign(current_fn->get_variables().size(), nullptr);
	m_triple_values.assign(current_fn->get_triple_count(), nullptr);

	create_llvm_basic_blocks(current_fn);

	m_builder->SetInsertPoint(m_llvm_basic_blocks[0]);

	const std::vector<IRVariable*> variables = current_fn->get_variables();
	for (size_t i = 0; i < variables.size();i++) {
		m_variables[variables[i]->get_index()] = m_builder->CreateAlloca(get_llvm_type(variables[i]->get_data_type()), nullptr, variables[i]->get_variable_name());
	}

	const std::vector<IRVariable*> parameters = current_fn->get_parameters();
	for (size_t i = 0; i < parameters.size();i++) {
		llvm::Value* argument_r_value = m_current_fn->getArg(i);
		m_builder->CreateStore(argument_r_value,m_variables[parameters[i]->get_index()]);
	}

	auto constants = current_fn->get_constants();
	for (IRConstant* constant : current_fn->get_constants()) {
		TypeRef type = constant->get_data_type().remove_reference().remove_qualifiers();
		if (type.is_string()) {
			const StringRef& ref = constant->get_string_ref();
			size_t length = ref.get_bytes_length();

			llvm::Type* byte_type = llvm::Type::getInt8Ty(*m_context);
			llvm::ArrayType* array_type = llvm::ArrayType::get(byte_type,length);
			llvm::StringRef bytes(
				reinterpret_cast<const char *>(ref.get_data()),
				ref.get_bytes_length()
			);

			llvm::Constant* string_address = m_builder->CreateGlobalStringPtr(
				bytes,
				".str",
				0,
				m_module.get()
			);

			m_llvm_constants.at(constant->get_index()) = string_address;
		}
		else {
			switch (type.get_ir_basic_type())
			{
			case IRBasicType::CHAR: {
				char value = constant->get_value().get_value<char>();
				m_llvm_constants.at(constant->get_index()) = llvm::ConstantInt::getSigned(get_llvm_type(type), value);
				break;
			}
			case IRBasicType::INT8: {
				int8_t value = constant->get_value().get_value<int8_t>();
				m_llvm_constants.at(constant->get_index()) = llvm::ConstantInt::getSigned(get_llvm_type(type), value);
				break;
			}
			case IRBasicType::INT16:
			{
				int16_t value = constant->get_value().get_value<int16_t>();
				m_llvm_constants.at(constant->get_index()) = llvm::ConstantInt::getSigned(get_llvm_type(type), value);
				break;
			}
			case IRBasicType::INT32: {
				int32_t value = constant->get_value().get_value<int32_t>();
				m_llvm_constants.at(constant->get_index()) = llvm::ConstantInt::getSigned(get_llvm_type(type),value);
				break;
			}
			case IRBasicType::INT64: {
				int64_t value = constant->get_value().get_value<int64_t>();
				m_llvm_constants.at(constant->get_index()) = llvm::ConstantInt::getSigned(get_llvm_type(type), value);
				break;
			}
			case IRBasicType::UINT8: {
				uint8_t value = constant->get_value().get_value<uint8_t>();
				m_llvm_constants.at(constant->get_index()) = llvm::ConstantInt::get(get_llvm_type(type), value, false);
				break;
			}
			case IRBasicType::UINT16: {
				uint16_t value = constant->get_value().get_value<uint16_t>();
				m_llvm_constants.at(constant->get_index()) = llvm::ConstantInt::get(get_llvm_type(type), value, false);
				break;
			}
			case IRBasicType::UINT32: {
				uint32_t value = constant->get_value().get_value<uint32_t>();
				m_llvm_constants[constant->get_index()] = llvm::ConstantInt::get(get_llvm_type(type), value, false);
				break;
			}
			case IRBasicType::UINT64: {
				uint64_t value = constant->get_value().get_value<uint64_t>();
				m_llvm_constants.at(constant->get_index()) = llvm::ConstantInt::get(get_llvm_type(type), value, false);
				break;
			}
			case IRBasicType::FLOAT: {
				float value = constant->get_value().get_value<float>();
				m_llvm_constants.at(constant->get_index()) = llvm::ConstantFP::get(get_llvm_type(type), value);
				break;
			}
			case IRBasicType::DOUBLE: {
				double value = constant->get_value().get_value<double>();
				m_llvm_constants.at(constant->get_index()) = llvm::ConstantFP::get(get_llvm_type(type), value);
				break;
			}
			case IRBasicType::BOOL: {
				bool value = constant->get_value().get_value<bool>();
				m_llvm_constants.at(constant->get_index()) =
					llvm::ConstantInt::get(
						llvm::Type::getInt8Ty(*m_context),
						value
					);
				break;
			}
			case IRBasicType::VOID:
				break;
			default:
				throw std::runtime_error("unknown type");
			}

		}
	}

	const std::vector<IRBasicBlock*>& blks = current_fn->get_basic_blocks();
	
	for (size_t i = 0; i < blks.size(); ++i) {
		m_llvm_block_map.emplace(blks[i], m_llvm_basic_blocks.at(i));
	}

	for (size_t i = 0; i < blks.size();i++) {
		m_builder->SetInsertPoint(m_llvm_basic_blocks.at(i));
		for (IRTriple * triple : blks[i]->get_all_triples()) {
			switch (triple->get_ir_operation())
			{
			case IROperation::INIT_ASSIGN:
			case IROperation::ASSIGN: {
				IRVariable* variable = triple->m_operands[0].get_variable();
				llvm::Value* value = get_operand_value(triple->m_operands[1]);

				if (variable->is_global()) {
					llvm::GlobalVariable* global_variable_address = m_global_variables[variable->get_index()];
					m_builder->CreateStore(value, global_variable_address);
				}
				else
					m_builder->CreateStore(value, m_variables[variable->get_index()]);

				break;
			}
			case IROperation::ADD:
			case IROperation::MUL:
			case IROperation::SUB: {
				const TypeRef left_type = triple->m_operands[0].get_data_type().remove_reference().remove_qualifiers();
				const TypeRef right_type = triple->m_operands[1].get_data_type().remove_reference().remove_qualifiers();

				//if (left_type.is_array()) {
				//	// NOT FOR VECTOR
				//	//IRArrayNode* left_array_node = static_cast<IRArrayNode*>(left_type.get_data_type_node());
				//	//size_t count = left_array_node->get_count();
				//	//llvm::Value* left_array_value = get_operand_value(triple->m_operands[0]);
				//	//llvm::Value* right_array_value = get_operand_value(triple->m_operands[1]);
				//	//// destination is the same as the left type
				//	//llvm::Value* result_array = llvm::UndefValue::get(get_llvm_type(left_type));
				//	//const TypeRef element_type = left_type.remove_array().remove_reference().remove_qualifiers();

				//	//for (size_t i = 0; i < count;i++) {
				//	//	llvm::Value* left_array_element = m_builder->CreateExtractValue(left_array_value, { static_cast<unsigned>(i) });
				//	//	llvm::Value* right_array_element = m_builder->CreateExtractValue(right_array_value, { static_cast<unsigned>(i) });
				//	//	
				//	//	bool integer = element_type.is_integer();
				//	//	auto op_code = integer ? llvm::Instruction::BinaryOps::Add : llvm::Instruction::BinaryOps::FAdd;

				//	//	if (triple->get_ir_operation() == IROperation::SUB)
				//	//		op_code = integer ? llvm::Instruction::BinaryOps::Sub : llvm::Instruction::BinaryOps::FSub;

				//	//	if (triple->get_ir_operation() == IROperation::MUL)
				//	//		op_code = integer ? llvm::Instruction::BinaryOps::Mul : llvm::Instruction::BinaryOps::FMul;

				//	//	llvm::Value* calc_value = m_builder->CreateBinOp(op_code, left_array_element , right_array_element);
				//	//	result_array = m_builder->CreateInsertValue(result_array,calc_value, { static_cast<unsigned>(i) });
				//	//}

				//	//m_triple_values[triple->get_global_index()] = result_array;
				//}
				if (left_type.is_array() || right_type.is_array()) {
					const TypeRef res_type = triple->get_data_type().remove_reference().remove_qualifiers();
					size_t res_count = static_cast<IRArrayNode*>(res_type.get_data_type_node())->get_count();
					size_t left_count = left_type.is_array() ? static_cast<IRArrayNode*>(left_type.get_data_type_node())->get_count() : 1;
					size_t right_count = right_type.is_array() ? static_cast<IRArrayNode*>(right_type.get_data_type_node())->get_count() : 1;
					llvm::Value* left_val = get_operand_value(triple->m_operands[0]);
					llvm::Value* right_val = get_operand_value(triple->m_operands[1]);

					auto broadcast_to_res = [&](llvm::Value* val, const TypeRef& t, size_t count) -> llvm::Value* {
						if (!t.is_array())
							return m_builder->CreateVectorSplat(res_count, val);
						if (count == res_count)
							return val;
						std::vector<int> mask(res_count);
						for (size_t i = 0; i < res_count; i++)
							mask[i] = static_cast<int>(i % count);
						return m_builder->CreateShuffleVector(val, llvm::UndefValue::get(val->getType()), mask);
					};

					left_val = broadcast_to_res(left_val, left_type, left_count);
					right_val = broadcast_to_res(right_val, right_type, right_count);
					
					const TypeRef element_type = res_type.remove_array().remove_reference().remove_qualifiers();
					bool integer = element_type.is_integer();
					auto op_code = integer ? llvm::Instruction::BinaryOps::Add : llvm::Instruction::BinaryOps::FAdd;
					if (triple->get_ir_operation() == IROperation::SUB)
						op_code = integer ? llvm::Instruction::BinaryOps::Sub : llvm::Instruction::BinaryOps::FSub;
					if (triple->get_ir_operation() == IROperation::MUL)
						op_code = integer ? llvm::Instruction::BinaryOps::Mul : llvm::Instruction::BinaryOps::FMul;

					m_triple_values[triple->get_global_index()] = m_builder->CreateBinOp(op_code, left_val, right_val);
				}
				else {
					// for basic types
					auto type = triple->get_data_type();
					bool integer = type.is_integer();
					auto op_code = integer ? llvm::Instruction::BinaryOps::Add : llvm::Instruction::BinaryOps::FAdd;

					if (triple->get_ir_operation() == IROperation::SUB)
						op_code = integer ? llvm::Instruction::BinaryOps::Sub : llvm::Instruction::BinaryOps::FSub;

					if (triple->get_ir_operation() == IROperation::MUL)
						op_code = integer ? llvm::Instruction::BinaryOps::Mul : llvm::Instruction::BinaryOps::FMul;

					convert_arithmetic_operation(op_code, triple);
				}
				break;
			}
			case IROperation::SELECT: {
				const TypeRef cond_type = triple->m_operands[0].get_data_type().remove_reference().remove_qualifiers();
				const TypeRef true_type = triple->m_operands[1].get_data_type().remove_reference().remove_qualifiers();
				const TypeRef false_type = triple->m_operands[2].get_data_type().remove_reference().remove_qualifiers();
				const TypeRef result_type = triple->get_data_type().remove_reference().remove_qualifiers();

				size_t result_count = result_type.is_array() ? static_cast<IRArrayNode*>(result_type.get_data_type_node())->get_count() : 1;
				size_t cond_count = cond_type.is_array() ? static_cast<IRArrayNode*>(cond_type.get_data_type_node())->get_count() : 1;
				size_t true_count = true_type.is_array() ? static_cast<IRArrayNode*>(true_type.get_data_type_node())->get_count() : 1;
				size_t false_count = false_type.is_array() ? static_cast<IRArrayNode*>(false_type.get_data_type_node())->get_count() : 1;

				llvm::Value* cond_value = get_operand_value(triple->m_operands[0]);
				llvm::Value* true_value = get_operand_value(triple->m_operands[1]);
				llvm::Value* false_value = get_operand_value(triple->m_operands[2]);

				if (result_type.is_array()) {
					cond_value = expand_vector(cond_value,cond_type,cond_count,result_count);
					true_value = expand_vector(true_value,true_type,true_count,result_count);
					false_value = expand_vector(false_value,false_type,false_count,result_count);
				}

				m_triple_values[triple->get_global_index()] = m_builder->CreateSelect(cond_value,true_value,false_value);

				break;
			}
			case IROperation::CAST: {
				llvm::Type* dst_llvm_type = get_llvm_type(triple->m_operands[0].get_data_type());
				const TypeRef src_type = triple->m_operands[1].get_data_type().remove_reference().remove_qualifiers();
				const TypeRef dst_type = triple->m_operands[0].get_data_type().remove_reference().remove_qualifiers();
				llvm::Value* src_value = get_operand_value(triple->m_operands[1]);

				// ogarnac ten fragment
				if (src_type.is_array()) {
					IRArrayNode* array_node = static_cast<IRArrayNode*>(src_type.get_data_type_node());
					size_t count = array_node->get_count();
					TypeRef src_element_type = src_type.remove_array().remove_qualifiers();
					TypeRef dst_element_type = dst_type.remove_array().remove_qualifiers();
					llvm::Type* dst_element_llvm_type = get_llvm_type(dst_element_type);


					llvm::Value* result_array = llvm::UndefValue::get(dst_llvm_type);
					for (size_t i = 0; i < count; i++) {
						llvm::Value* element = m_builder->CreateExtractValue(src_value, { static_cast<unsigned>(i) });
						llvm::Value* casted_element = auto_cast(element, dst_element_llvm_type, src_element_type.is_signed(), dst_element_type.is_signed());
						result_array = m_builder->CreateInsertValue(result_array, casted_element, { static_cast<unsigned>(i) });
					}

					m_triple_values[triple->get_global_index()] = result_array;
				}
				else {
					auto casted_value = auto_cast(src_value, dst_llvm_type, src_type.is_signed(), dst_type.is_signed());
					m_triple_values[triple->get_global_index()] = casted_value;
				}
				break;
			}
			case IROperation::REINTERPRET_CAST: {
				llvm::Type* dst_llvm_type = get_llvm_type(triple->m_operands[0].get_data_type());
				const TypeRef src_type = triple->m_operands[1].get_data_type().remove_reference().remove_qualifiers();
				const TypeRef dst_type = triple->m_operands[0].get_data_type().remove_reference().remove_qualifiers();

				llvm::Value* src_value = get_operand_value(triple->m_operands[1]);

				llvm::Value* temp = m_builder->CreateAlloca(src_value->getType(),nullptr,"reinterpretcast_temp");
				m_builder->CreateStore(src_value,temp);
				llvm::Value* result = m_builder->CreateLoad(dst_llvm_type,temp,"reinterpretcast_value");
				m_triple_values[triple->get_global_index()] = result;
				break;
			}
			case IROperation::ADDRESS_OF: {
				m_triple_values[triple->get_global_index()] = get_operand_address(triple->m_operands[0]);
				break;
			}
			case IROperation::DEREFERENCE: {
				llvm::Value* address_stored_under_pointer = get_operand_value(triple->m_operands[0]);
				m_triple_values[triple->get_global_index()] = m_builder->CreateLoad(get_llvm_type(triple->get_data_type()), address_stored_under_pointer);
				break;
			}
			case IROperation::ARRAY_ACCESS: {
				const IROperand& base = triple->m_operands[0];

				TypeRef base_type = base.get_data_type().remove_reference().remove_qualifiers();

				llvm::Value* index = get_operand_value(triple->m_operands[1]);
				llvm::Value* element_address = nullptr;

				if (base_type.is_array()) {
					element_address = m_builder->CreateGEP(
						get_llvm_type(base_type),
						get_operand_address(base),
						{m_builder->getInt32(0),index}
					);
				}
				else if (base_type.is_pointer()) {
					element_address = m_builder->CreateGEP(
						get_llvm_type(base_type.remove_pointer()),
						get_operand_value(base),
						{index}
					);
				}
				else
					throw std::runtime_error("array access requires an array or pointer");

				m_triple_values.at(triple->get_global_index()) = element_address;
				break;
			}
			case IROperation::WRITE_TO_POINTER: {
				llvm::Value* variable_address = get_operand_value(triple->m_operands[0]);
				llvm::Value* value = get_operand_value(triple->m_operands[1]);
				print_llvm_type(variable_address->getType());
				print_llvm_type(value->getType());

				m_builder->CreateStore(value,variable_address);
				break;
			}
			case IROperation::MEMBER_ACCESS: {
				IROperand object = triple->m_operands[0];
				TypeRef object_type = object.get_data_type().remove_reference().remove_qualifiers();

				llvm::Value* base_address = nullptr;
				if (object_type.is_pointer()) {
					base_address = get_operand_value(object);
					object_type = object_type.remove_pointer().remove_qualifiers();
				}
				else
					base_address = get_operand_address(object);

				if (object_type.is_union())
					m_triple_values[triple->get_global_index()] = base_address;
				else {
					llvm::Type* struct_llvm_type = get_llvm_type(object_type);
					// second argument is a member
					IRMember* member = triple->m_operands[1].get_member();
					size_t field_index = member->get_index();
				
					llvm::Value* zero = m_builder->getInt32(0);
					llvm::Value* field_index_value = m_builder->getInt32(field_index);

					llvm::Value* field_ptr = m_builder->CreateGEP(
							struct_llvm_type,
							base_address,
							{ zero, field_index_value }
					);

					m_triple_values[triple->get_global_index()] = field_ptr;				
				}

				break;
			}
			case IROperation::RETURN: {
				if (triple->m_operands.empty())
					m_builder->CreateRetVoid();
				else {
					llvm::Value* return_value = get_operand_value(triple->m_operands[0]);
					m_builder->CreateRet(return_value);
				}
				break;
			}
			case IROperation::FUNCTION_CALL:
			case IROperation::EXTERNAL_FUNCTION_CALL:
			{
				size_t called_fn_index = triple->m_operands[0].get_base_function()->get_index();
				llvm::FunctionCallee callee = m_function_callees.at(called_fn_index);

				std::vector<llvm::Value*> args;
				for (size_t i = 1; i < triple->m_operands.size();i++)
					args.push_back(get_operand_value(triple->m_operands[i]));

				m_triple_values[triple->get_global_index()] = m_builder->CreateCall(callee,args);
				break;
			}
			case IROperation::PRINT: {
				const TypeRef type = triple->m_operands[0].get_data_type().remove_reference().remove_qualifiers();
				TypeRef normalized_type = type.remove_reference().remove_qualifiers();

				if (normalized_type.is_basic_data_type()) {
					switch (normalized_type.get_ir_basic_type())
					{
					case IRBasicType::CHAR: {
						m_triple_values[triple->m_global_index] = get_function_call_instance(triple,print<char>);
						break;
					}
					case IRBasicType::INT8: {
						m_triple_values[triple->m_global_index] = get_function_call_instance(triple, print<int8_t>);
						break;
					}
					case IRBasicType::INT16: {
						m_triple_values[triple->m_global_index] = get_function_call_instance(triple, print<int16_t>);
						break;
					}
					case IRBasicType::INT32:
					{
						m_triple_values[triple->m_global_index] = get_function_call_instance(triple, print<int>);
						break;
					}
					case IRBasicType::INT64: {
						m_triple_values[triple->m_global_index] = get_function_call_instance(triple, print<int64_t>);
						break;
					}
					case IRBasicType::FLOAT: {
						m_triple_values[triple->m_global_index] = get_function_call_instance(triple, print<float>);
						break;
					}
					case IRBasicType::DOUBLE: {
						m_triple_values[triple->m_global_index] = get_function_call_instance(triple, print<double>);
						break;
					}
					case IRBasicType::BOOL: {
						m_triple_values[triple->m_global_index] = get_function_call_instance(triple, print<bool>);
						break;
					}
					case IRBasicType::UINT8: {
						m_triple_values[triple->get_global_index()] = get_function_call_instance(triple, print<uint8_t>);
						break;
					}
					case IRBasicType::UINT16: {
						m_triple_values[triple->get_global_index()] = get_function_call_instance(triple, print<uint16_t>);
						break;
					}
					case IRBasicType::UINT32: {
						m_triple_values[triple->get_global_index()] = get_function_call_instance(triple, print<uint32_t>);
						break;
					}
					case IRBasicType::UINT64: {
						m_triple_values[triple->get_global_index()] = get_function_call_instance(triple, print<uint64_t>);
						break;
					}
					default:
						break;
					}
				}
				else if (normalized_type.is_string()) {
					m_triple_values[triple->get_global_index()] = get_function_call_instance(triple, print_string);
					break;
				}
				else if (normalized_type.is_array()) {
					TypeRef element_type = normalized_type.remove_array().remove_qualifiers();

					if (!element_type.is_basic_data_type())
						throw std::runtime_error("unsupported array element type for print");

					switch (element_type.get_ir_basic_type())
					{
					case IRBasicType::INT8: {
						m_triple_values[triple->m_global_index] = get_function_call_instance_array(triple, print_array<int8_t>);
						break;
					}
					case IRBasicType::INT16: {
						m_triple_values[triple->m_global_index] = get_function_call_instance_array(triple, print_array<int16_t>);
						break;
					}
					case IRBasicType::INT32:
					{
						m_triple_values[triple->m_global_index] = get_function_call_instance_array(triple, print_array<int>);
						break;
					}
					case IRBasicType::INT64: {
						m_triple_values[triple->m_global_index] = get_function_call_instance_array(triple, print_array<int64_t>);
						break;
					}
					case IRBasicType::FLOAT: {
						m_triple_values[triple->m_global_index] = get_function_call_instance_array(triple, print_array<float>);
						break;
					}
					case IRBasicType::DOUBLE: {
						m_triple_values[triple->m_global_index] = get_function_call_instance_array(triple, print_array<double>);
						break;
					}
					case IRBasicType::CHAR: {
						m_triple_values[triple->m_global_index] = get_function_call_instance_array(triple,print_char_array);
						break;
					}
					default:
						break;
					}
				}

				break;
			}
			case IROperation::PRINT_TYPE: {
				// This part should be rewritten 
				std::string type_name = triple->m_operands[0].get_data_type().to_string();
				llvm::Constant* string_address = m_builder->CreateGlobalStringPtr(
					type_name,
					".type_str",
					0,
					m_module.get()
				);

				llvm::ConstantInt* address = llvm::ConstantInt::get(
					llvm::Type::getInt64Ty(*m_context),
					reinterpret_cast<std::uintptr_t>(&print_string)
				);

				auto* llvm_callee = llvm::ConstantExpr::getIntToPtr(
					address,
					llvm::PointerType::get(*m_context, 0)
				);

				llvm::FunctionType* function_type = llvm::FunctionType::get(
					m_builder->getVoidTy(),
					{ llvm::PointerType::get(*m_context, 0) },
					false
				);

				m_triple_values[triple->get_global_index()] = m_builder->CreateCall(
					function_type,
					llvm_callee,
					{ string_address }
				);

				break;
			}
			case IROperation::GE: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);

				TypeRef left_operand_type_ref = triple->m_operands[0].get_data_type().remove_reference().remove_qualifiers();

				llvm::Value* result = nullptr;

				if (left->getType()->isIntegerTy()) {
					result = left_operand_type_ref.is_signed() ? 
						m_builder->CreateICmpSGE(left, right, "ge") : 
						m_builder->CreateICmpUGE(left,right,"ge") ;
				}
				else if (left->getType()->isFloatingPointTy()) {
					result = m_builder->CreateFCmpOGE(left,right,"ge");
				}else {
					throw std::runtime_error("unsupported operand type for GE");
				}

				m_triple_values[triple->get_global_index()] = result;
				break;
			}
			case IROperation::LE: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);

				TypeRef left_operand_type_ref = triple->m_operands[0].get_data_type().remove_reference().remove_qualifiers();

				llvm::Value* result = nullptr;

				if (left->getType()->isIntegerTy()) {
					result = left_operand_type_ref.is_signed() ?
						m_builder->CreateICmpSLE(left, right, "le") :
						m_builder->CreateICmpULE(left, right, "le");
				}
				else if (left->getType()->isFloatingPointTy())
					result = m_builder->CreateFCmpOLE(left, right, "le");
				else
					throw std::runtime_error("unsupported operand type for LE");

				m_triple_values[triple->get_global_index()] = result;
				break;
			}
			case IROperation::GT: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);

				TypeRef operand_type = triple->m_operands[0].get_data_type()
					.remove_reference()
					.remove_qualifiers();

				llvm::Value* result = nullptr;

				if (left->getType()->isIntegerTy()) {
					result = operand_type.is_signed()
						? m_builder->CreateICmpSGT(left, right, "gt")
						: m_builder->CreateICmpUGT(left, right, "gt");
				}
				else if (left->getType()->isFloatingPointTy())
					result = m_builder->CreateFCmpOGT(left, right, "gt");
				else 
					throw std::runtime_error("unsupported operand type for GT");

				m_triple_values.at(triple->get_global_index()) = result;
				break;
			}
			case IROperation::LT: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);

				TypeRef operand_type = triple->m_operands[0].get_data_type()
					.remove_reference()
					.remove_qualifiers();

				llvm::Value* result = nullptr;

				if (left->getType()->isIntegerTy()) {
					result = operand_type.is_signed()
						? m_builder->CreateICmpSLT(left, right, "lt")
						: m_builder->CreateICmpULT(left, right, "lt");
				}
				else if (left->getType()->isFloatingPointTy())
					result = m_builder->CreateFCmpOLT(left, right, "lt");
				else
					throw std::runtime_error("unsupported operand type for LT");

				m_triple_values.at(triple->get_global_index()) = result;
				break;
			}
			case IROperation::EQ:{
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);
				TypeRef left_operand_type_ref = triple->m_operands[0].get_data_type().remove_reference().remove_qualifiers();

				llvm::Value* result = nullptr;
				if (left->getType()->isIntegerTy())
					result = m_builder->CreateICmpEQ(left, right, "eq");
				else if (left->getType()->isFloatingPointTy())
					result = m_builder->CreateFCmpOEQ(left, right, "eq");
				else
					throw std::runtime_error("unsupported operand type for EQ");

				m_triple_values[triple->get_global_index()] = result;
				break;
			}
			case IROperation::NEQ: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);
				TypeRef left_operand_type_ref = triple->m_operands[0].get_data_type().remove_reference().remove_qualifiers();

				llvm::Value* result = nullptr;
				if (left->getType()->isIntegerTy())
					result = m_builder->CreateICmpNE(left, right, "neq");
				else if (left->getType()->isFloatingPointTy())
					result = m_builder->CreateFCmpONE(left, right, "neq");
				else
					throw std::runtime_error("unsupported operand type for NEQ");

				m_triple_values[triple->get_global_index()] = result;
				break;
			}
			case IROperation::JC: {
				llvm::Value* condition = get_operand_value(triple->m_operands[0]);

				if (!condition || !condition->getType()->isIntegerTy(1))
					throw std::runtime_error("JC requires an i1 type");

				llvm::BasicBlock* true_block = m_llvm_block_map.at(triple->m_operands[1].get_basic_block());
				llvm::BasicBlock* false_block = m_llvm_block_map.at(triple->m_operands[2].get_basic_block());

				m_builder->CreateCondBr(condition,true_block,false_block);

				break;
			}
			case IROperation::JMP: {
				llvm::BasicBlock* target = m_llvm_block_map.at(triple->m_operands[0].get_basic_block());

				m_builder->CreateBr(target);
				break;
			}
			case IROperation::BITWISE_AND: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);

				m_triple_values[triple->get_global_index()] = m_builder->CreateAnd(left,right);
				break;
			}
			case IROperation::BITWISE_OR: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);

				m_triple_values[triple->get_global_index()] = m_builder->CreateOr(left, right);
				break;
			}
			case IROperation::BITWISE_NOT: {
				llvm::Value* value = get_operand_value(triple->m_operands[0]);

				m_triple_values[triple->get_global_index()] = m_builder->CreateNot(value);
				break;
			}
			case IROperation::BITWISE_XOR: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);

				m_triple_values[triple->get_global_index()] = m_builder->CreateXor(left, right);
				break;
			}
			case IROperation::COPY: {
				llvm::Value* value = get_operand_value(triple->m_operands[0]);

				m_triple_values[triple->get_global_index()] = value;
				break;
			}
			case IROperation::INC: {
				IRVariable* variable = triple->m_operands[0].get_variable();
				llvm::Value* ptr = nullptr;

				if (variable->is_global())
					ptr = m_global_variables[variable->get_index()];
				else 
					ptr = m_variables[variable->get_index()];

				llvm::Value* old_value = get_operand_value(triple->m_operands[0]);
				llvm::Value* new_value = nullptr;
				llvm::Value* one = nullptr;

				if (old_value->getType()->isFloatingPointTy()) {
					one = llvm::ConstantFP::get(old_value->getType(), 1.0);
					new_value = m_builder->CreateFAdd(old_value, one);
				}
				else if (old_value->getType()->isIntegerTy()) {
					one = llvm::ConstantInt::get(old_value->getType(), 1);
					new_value = m_builder->CreateAdd(old_value, one);
				}

				m_builder->CreateStore(new_value, ptr);
				m_triple_values[triple->get_global_index()] = new_value;
				break;
			}
			case IROperation::DEC:
			{
				IRVariable* variable = triple->m_operands[0].get_variable();
				llvm::Value* ptr = nullptr;

				if (variable->is_global())
					ptr = m_global_variables[variable->get_index()];
				else
					ptr = m_variables[variable->get_index()];

				llvm::Value* old_value = get_operand_value(triple->m_operands[0]);
				llvm::Value* new_value = nullptr;
				llvm::Value* one = nullptr;

				if (old_value->getType()->isFloatingPointTy()) {
					one = llvm::ConstantFP::get(old_value->getType(), 1.0);
					new_value = m_builder->CreateFSub(old_value, one);
				}
				else if (old_value->getType()->isIntegerTy()) {
					one = llvm::ConstantInt::get(old_value->getType(), 1);
					new_value = m_builder->CreateSub(old_value, one);
				}

				m_builder->CreateStore(new_value,ptr);
				m_triple_values[triple->get_global_index()] = new_value;

				break;
			}
			case IROperation::DIV: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);
				
				if (left->getType()->isFloatingPointTy())
					m_triple_values[triple->get_global_index()] = m_builder->CreateFDiv(left,right);
				else {
					if (triple->m_data_type.is_signed())
						m_triple_values[triple->get_global_index()] = m_builder->CreateSDiv(left,right);
					else
						m_triple_values[triple->get_global_index()] = m_builder->CreateUDiv(left, right);
				}
				break;
			}
			case IROperation::MOD: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);
				
				if (left->getType()->isFloatingPointTy())
					m_triple_values[triple->get_global_index()] = m_builder->CreateFRem(left, right);
				else {
					if (triple->m_data_type.is_signed())
						m_triple_values[triple->get_global_index()] = m_builder->CreateSRem(left, right);
					else
						m_triple_values[triple->get_global_index()] = m_builder->CreateURem(left, right);
				}

				break;
			}
			case IROperation::UNARY_MINUS: {
				llvm::Value* value = get_operand_value(triple->m_operands[0]);
				
				if (value->getType()->isFloatingPointTy())
					m_triple_values[triple->get_global_index()] = m_builder->CreateFNeg(value);
				else
					m_triple_values[triple->get_global_index()] = m_builder->CreateNeg(value);

				break;
			}
			case IROperation::LEFT_SHIFT: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);

				m_triple_values[triple->get_global_index()] = m_builder->CreateShl(left, right);
				break;
			}
			case IROperation::RIGHT_SHIFT: {
				llvm::Value* left = get_operand_value(triple->m_operands[0]);
				llvm::Value* right = get_operand_value(triple->m_operands[1]);

				const TypeRef type = triple->m_operands[0].get_data_type().remove_reference().remove_qualifiers();

				if (type.is_signed())
					m_triple_values[triple->get_global_index()] = m_builder->CreateAShr(left, right);
				else
					m_triple_values[triple->get_global_index()] = m_builder->CreateLShr(left, right);

				break;
			}
			case IROperation::ARRAY_TO_POINTER: {
				const IROperand& array = triple->m_operands[1];
				
				TypeRef array_type = array.get_data_type().remove_reference().remove_qualifiers();

				if (!array_type.is_array())
					throw std::runtime_error("array_to_pointer requires an array");

				llvm::Value* array_address = get_operand_address(array);
				llvm::Value* zero = m_builder->getInt32(0);

				llvm::Value* first_element_address = m_builder->CreateGEP(
					get_llvm_type(array_type),
					array_address,
					{ zero, zero },
					"array_to_pointer"
				);

				m_triple_values.at(triple->get_global_index()) = first_element_address;

				break;
			}
			default:
				throw std::runtime_error("operation is not supported");
				break;
			}
		}
	}
}

llvm::FunctionType* IRToLLVMIRConverter::get_llvm_function_type(IRBaseFunction* base_fn) {
	llvm::Type* return_type = get_llvm_type(base_fn->get_return_type());
	const std::vector<TypeRef> parameter_types = base_fn->get_parameter_types();
	std::vector<llvm::Type*> llvm_parameter_types(parameter_types.size());

	for (size_t i = 0; i < parameter_types.size();i++)
		llvm_parameter_types[i] = get_llvm_type(parameter_types[i]);

	llvm::FunctionType* function_type = llvm::FunctionType::get(
		return_type,
		llvm_parameter_types,
		false
	);

	return function_type;
}

llvm::CallInst* IRToLLVMIRConverter::get_function_call_instance(IRTriple* triple, void* fn_address) {
	llvm::ConstantInt* address = llvm::ConstantInt::get(
		llvm::Type::getInt64Ty(*m_context),
		reinterpret_cast<std::uintptr_t>(fn_address)
	);

	if (!address)
		throw std::runtime_error("address not found");

	auto* llvm_callee = llvm::ConstantExpr::getIntToPtr(
		address,
		llvm::PointerType::get(*m_context, 0)
	);

	std::vector<llvm::Value*> args;
	IROperand op = triple->m_operands[0];
	llvm::Value* arg = get_operand_value(op);
	args.push_back(arg);

	llvm::Type* return_type = get_llvm_type(m_ir_program->get_dtm_manager()->get_void());
	std::vector<llvm::Type*> parameter_types;
	parameter_types.push_back(get_llvm_type(triple->m_operands[0].get_data_type()));

	llvm::FunctionType* function_type = llvm::FunctionType::get(
		return_type,
		parameter_types,
		false
	);

	llvm::CallInst* call_inst = m_builder->CreateCall(
		function_type,
		llvm_callee,
		args
	);

	return call_inst;
}

llvm::CallInst* IRToLLVMIRConverter::get_function_call_instance_array(IRTriple* triple, void* fn_address) {

	if (!fn_address)
		throw std::runtime_error("address not found");


	IROperand array_operand = triple->m_operands[0];
	TypeRef array_type = array_operand.get_data_type().remove_reference().remove_qualifiers();
	
	if (!array_type.is_array())
		throw std::runtime_error("array operand required");

	IRArrayNode* array_node = (IRArrayNode*) array_operand.get_data_type().get_data_type_node();

	llvm::Value* base_array_address = nullptr;
	if (array_operand.m_operand_type == IROperandType::TRIPLE &&  array_operand.get_triple()->get_ir_operation() == IROperation::FUNCTION_CALL) {
		llvm::Value* temporary = m_builder->CreateAlloca(
			get_llvm_type(array_type),
			nullptr,
			"returned_array"
		);

		m_builder->CreateStore(
			get_operand_value(array_operand),
			temporary
		);

		base_array_address = temporary;
	}
	else
		base_array_address = get_operand_address(array_operand);

	size_t array_size = array_node->get_count();
	llvm::Value* size_value = m_builder->getInt64(array_size);
	llvm::ConstantInt* function_address = m_builder->getInt64(
		reinterpret_cast<std::uintptr_t>(fn_address)
	);
	auto* llvm_callee = llvm::ConstantExpr::getIntToPtr(
		function_address,
		llvm::PointerType::get(*m_context, 0)
	);

	std::vector<llvm::Value*> args{
		base_array_address,
		size_value
	};

	std::vector<llvm::Type*> parameter_types{
		llvm::PointerType::get(*m_context,0),
		m_builder->getInt64Ty()
	};

	llvm::Type* return_type = get_llvm_type(m_ir_program->get_dtm_manager()->get_void());

	llvm::FunctionType* function_type = llvm::FunctionType::get(
		m_builder->getVoidTy(),
		parameter_types,
		false
	);

	return m_builder->CreateCall(function_type,llvm_callee,args);
}