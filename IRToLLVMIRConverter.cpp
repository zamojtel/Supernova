
void IRToLLVMIRConverter::create_llvm_basic_blocks(IRFunction *current_fn) {
	m_llvm_basic_blocks.clear();
	const std::vector<IRBasicBlock*>& blks = current_fn->get_basic_blocks();

	for (size_t i = 0; i < blks.size();i++) {
		std::string block_name = blks[i]->get_basic_blk_name();
		auto llvm_blk = llvm::BasicBlock::Create(
			*m_context,
			block_name,
			m_current_fn
		);
		m_llvm_basic_blocks.push_back(llvm_blk);
	}

}

llvm::Value* IRToLLVMIRConverter::get_operand_value(const IROperand& op)  {
	switch (op.m_operand_type)
	{
	case IROperandType::CONSTANT:
		return m_llvm_constants.at(op.get_constant()->get_index());
	case IROperandType::VARIABLE: {
		if (op.get_variable()->is_global()) {
			llvm::GlobalVariable* global_variable_address = m_global_variables[op.get_variable()->get_index()];
			return m_builder->CreateLoad(global_variable_address->getValueType(),global_variable_address);
		}

		return m_variables.at(op.get_variable()->get_index());
	}
	case IROperandType::TRIPLE:
		return m_triple_values.at(op.get_triple()->get_local_index());
	case IROperandType::FUNCTION:
		return m_llvm_functions.at(op.get_function()->get_index());
	default:
		break;
	}
}

void IRToLLVMIRConverter::convert_arithmetic_operation(llvm::Instruction::BinaryOps op_code,IRTriple *triple) {
	llvm::Value* left_value = get_operand_value(triple->m_operands[0]);
	llvm::Value* right_value = get_operand_value(triple->m_operands[1]);
	llvm::Value* calc_value = nullptr;
	llvm::Value* left_value_loaded = nullptr;
	if (left_value->getType() ) {

	}

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
	if (!normalized_type.is_basic_data_type())
		throw std::runtime_error("LLVM conversion currently supports only basic types");

	return get_llvm_type(normalized_type.get_ir_basic_type());
}

llvm::Type* IRToLLVMIRConverter::get_llvm_type(IRBasicType type) const {
	switch (type)
	{
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

void IRToLLVMIRConverter::create_llvm_function(IRFunction* current_fn) {
	std::vector<llvm::Type*> parameter_types;
	llvm::Type* return_type = get_llvm_type(current_fn->get_return_type());
	
	for (IRVariable* parameter : current_fn->get_parameters())
		parameter_types.push_back(get_llvm_type(parameter->get_data_type()));

	llvm::FunctionType* function_type = llvm::FunctionType::get(
		return_type,
		parameter_types,
		false
	);

	llvm::Function* llvm_function = nullptr;
	if (current_fn->m_kind==IRBaseFunction::Kind::INTERNAL) {
		llvm_function = llvm::Function::Create(
			function_type,
			llvm::Function::ExternalLinkage,
			FunctionNames::get_internal_name(current_fn->get_name()),
			m_module.get()
		);
	}
	else {
		llvm_function = llvm::Function::Create(
			function_type,
			llvm::Function::ExternalLinkage,
			current_fn->get_name(),
			m_module.get()
		);
	}

	m_llvm_functions.at(current_fn->get_index()) = llvm_function;
}

IRToLLVMIRConverter::IRToLLVMIRConverter(IRProgram* ir_program) : m_ir_program{ ir_program } {
	size_t counter = 0;
	auto& fn_map = m_ir_program->get_functions();
	for (auto& [name, vec_fn] : fn_map)
		counter += vec_fn.size();

	m_llvm_functions.resize(counter);

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

void IRToLLVMIRConverter::convert_function(IRFunction* current_fn) {
	m_current_fn = m_llvm_functions.at(current_fn->get_index());
	m_llvm_constants.assign(current_fn->get_constants().size(),nullptr);
	m_variables.assign(current_fn->get_variables().size(), nullptr);
	m_triple_values.assign(current_fn->get_triple_count(), nullptr);

	auto parameters = current_fn->get_parameters();
	for (size_t i = 0; i < parameters.size();i++) {
		auto variable = m_current_fn->getArg(i);
		m_variables[i] = variable;
	}

	create_llvm_basic_blocks(current_fn);

	auto constants = current_fn->get_constants();
	for (IRConstant* constant : current_fn->get_constants()) {
		TypeRef type = constant->get_data_type().remove_reference().remove_qualifiers();

		switch (type.get_ir_basic_type())
		{
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
		case IRBasicType::BOOL:
			break;
		case IRBasicType::STRING:
			break;
		case IRBasicType::VOID:
			break;
		default:
			throw std::runtime_error("unknown type");
		}
	}

	const std::vector<IRBasicBlock*>& blks = current_fn->get_basic_blocks();
	for (size_t i = 0; i < blks.size();i++) {
		m_builder->SetInsertPoint(m_llvm_basic_blocks.at(i));
		for (IRTriple * triple : blks[i]->get_all_triples()) {
			switch (triple->get_ir_operation())
			{
			case IROperation::INIT_ASSIGN: {
				auto variable = triple->m_operands[0].get_variable();
				llvm::Value* value = get_operand_value(triple->m_operands[1]);
				m_variables[variable->get_index()] = value;
				if (variable->is_global()) {
					llvm::GlobalVariable* global_variable_address = m_global_variables[variable->get_index()];
					m_builder->CreateStore(value,global_variable_address);
				}
				else
					m_variables[variable->get_index()] = value;
				break;
			}
			case IROperation::ASSIGN: {
				auto variable = triple->m_operands[0].get_variable();
				llvm::Value* value = get_operand_value(triple->m_operands[1]);
				if (variable->is_global()) {
					llvm::GlobalVariable* global_variable_address = m_global_variables[variable->get_index()];
					m_builder->CreateStore(value, global_variable_address);
				}
				else
					m_variables[variable->get_index()] = value;

				break;
			}
			case IROperation::ADD:
			case IROperation::MUL:
			case IROperation::SUB: {
				auto type = triple->get_data_type();
				bool integer = type.is_integer();
				auto op_code = integer ? llvm::Instruction::BinaryOps::Add : llvm::Instruction::BinaryOps::FAdd;

				if (triple->get_ir_operation() == IROperation::SUB)
					op_code = integer ? llvm::Instruction::BinaryOps::Sub : llvm::Instruction::BinaryOps::FSub;

				if (triple->get_ir_operation() == IROperation::MUL)
					op_code = integer ? llvm::Instruction::BinaryOps::Mul : llvm::Instruction::BinaryOps::FMul;

				convert_arithmetic_operation(op_code,triple);
				break;
			}
			case IROperation::CAST: {
				llvm::Type* dst_llvm_type = get_llvm_type(triple->m_operands[0].get_data_type());
				const TypeRef src_type = triple->m_operands[1].get_data_type();
				const TypeRef dst_type = triple->m_operands[0].get_data_type();
				llvm::Value* value = get_operand_value(triple->m_operands[1]);

				auto casted_value = auto_cast(value, dst_llvm_type, src_type.is_signed(), dst_type.is_signed());
				m_triple_values[triple->m_global_index] = casted_value;

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
			case IROperation::FUNCTION_CALL: {
				llvm::CallInst* call_inst = nullptr;

				size_t called_function_index = triple->m_operands[0].get_function()->get_index();
				llvm::Function* called_fn = m_llvm_functions[called_function_index];
				llvm::FunctionType* fn_type = called_fn->getFunctionType();

				std::vector<llvm::Value*> args;
				for (size_t i = 1; i < triple->m_operands.size();i++) {
					IROperand op = triple->m_operands[i];
					llvm::Value* arg = get_operand_value(op);
					args.push_back(arg);
				}

				call_inst = m_builder->CreateCall(fn_type,
					called_fn,
					args
				);

				m_triple_values[triple->m_global_index] = call_inst;
				break;
			}
			case IROperation::EXTERNAL_FUNCTION_CALL: {
				IRBaseFunction* base_function = triple->m_operands[0].get_base_function();
				llvm::Type* return_type = get_llvm_type(base_function->get_return_type());
				std::vector<llvm::Type*> parameter_types;
				for (const TypeRef& parameter_type : base_function->get_parameter_types())
					parameter_types.push_back(get_llvm_type(parameter_type));

				llvm::FunctionType* function_type = llvm::FunctionType::get(
					return_type,
					parameter_types,
					false
				);

				llvm::Function* llvm_callee = m_module->getFunction(base_function->get_name());
				if (!llvm_callee) {
					llvm_callee = llvm::Function::Create(
						function_type,
						llvm::Function::ExternalLinkage,
						base_function->get_name(),
						*m_module
					);

				}

				std::vector<llvm::Value*> args;
				for (size_t i = 1; i < triple->m_operands.size(); i++) {
					IROperand op = triple->m_operands[i];
					llvm::Value* arg = get_operand_value(op);
					args.push_back(arg);
				}

				llvm::CallInst* call_inst = m_builder->CreateCall(
					function_type,
					llvm_callee,
					args
				);

				m_triple_values[triple->m_global_index] = call_inst;
				break;
			}
			case IROperation::PRINT: {
				IRBaseFunction* base_function = m_ir_program->get_external_function("print_float", {m_ir_program->get_dtm_manager()->get_float()});
				llvm::Type* return_type = get_llvm_type(base_function->get_return_type());
				std::vector<llvm::Type*> parameter_types;
				for (const TypeRef& parameter_type : base_function->get_parameter_types())
					parameter_types.push_back(get_llvm_type(parameter_type));

				llvm::FunctionType* function_type = llvm::FunctionType::get(
					return_type,
					parameter_types,
					false
				);

				llvm::Function* llvm_callee = m_module->getFunction(base_function->get_name());
				if (!llvm_callee) {
					llvm_callee = llvm::Function::Create(
						function_type,
						llvm::Function::ExternalLinkage,
						base_function->get_name(),
						*m_module
					);
				}

				std::vector<llvm::Value*> args;
				IROperand op = triple->m_operands[0];
				llvm::Value* arg = get_operand_value(op);
				args.push_back(arg);

				llvm::CallInst* call_inst = m_builder->CreateCall(
					function_type,
					llvm_callee,
					args
				);

				m_triple_values[triple->m_global_index] = call_inst;
				break;
			}
			default:
				throw std::runtime_error("operation is not supported");
				break;
			}
		}
	}
}

//void IRToLLVMIRConverter::convert_function(IRFunction * current_fn) {
	// TODO UNCOMMENT AND REPAIR LATER
	//m_llvm_constants.resize(current_fn->get_constants().size());
	//m_variable_values.resize(current_fn->get_variables().size());
	//m_triple_values.resize(current_fn->get_triple_count());

	//m_current_fn = m_llvm_functions[current_fn->get_index()];
	//
	//int number_of_parameters = current_fn->get_parameters().size();
	//for (size_t i = 0; i < number_of_parameters; i++) {
	//	auto variable = m_current_fn->getArg(i);
	//	m_variable_values[i] = variable;
	//}

	//create_llvm_basic_blocks(current_fn);

	//// #TODO ogarnac ten switch 
	//auto constants = current_fn->get_constants();
	//for (size_t i = 0; i < constants.size(); i++) {
	//	auto type = constants[i]->get_data_type();
	//	auto llvm_type = get_llvm_type(type);
	//	switch (type)
	//	{
	//	case IRBasicType::INT8: {
	//		int8_t value = constants[i]->get_value().get_value<int8_t>();

	//		llvm::Constant* llvm_constant = llvm::ConstantInt::getSigned(llvm_type, value);
	//		m_llvm_constants[i] = llvm_constant;
	//		break;
	//	}
	//	case IRBasicType::INT16:
	//	{
	//		int16_t value = constants[i]->get_value().get_value<int16_t>();
	//		llvm::Constant* llvm_constant = llvm::ConstantInt::getSigned(llvm_type, value);
	//		m_llvm_constants[i] = llvm_constant;
	//		break;
	//	}
	//	case IRBasicType::INT32: {
	//		int32_t value = constants[i]->get_value().get_value<int32_t>();
	//		llvm::Constant* llvm_constant = llvm::ConstantInt::getSigned(llvm_type, value);

	//		m_llvm_constants[i] = llvm_constant;
	//		break;
	//	}
	//	case IRBasicType::INT64: {
	//		int64_t value = constants[i]->get_value().get_value<int64_t>();
	//		llvm::Constant* llvm_constant = llvm::ConstantInt::getSigned(llvm_type, value);
	//		m_llvm_constants[i] = llvm_constant;
	//		break;
	//	}
	//						  // TODO REDUCE NUMBER OF LINES!
	//	case IRBasicType::UINT8: {
	//		uint8_t value = constants[i]->get_value().get_value<uint8_t>();
	//		llvm::Constant* llvm_constant = llvm::ConstantInt::get(llvm_type, value, false);
	//		m_llvm_constants[i] = llvm_constant;
	//		break;
	//	}
	//	case IRBasicType::UINT16: {
	//		uint16_t value = constants[i]->get_value().get_value<uint8_t>();
	//		auto llvm_type = llvm::Type::getInt16Ty(*m_context);
	//		llvm::ConstantInt* llvm_constant = llvm::ConstantInt::get(llvm_type, value, false);
	//		m_llvm_constants[i] = llvm_constant;
	//		break;
	//	}
	//	case IRBasicType::UINT32: {
	//		uint32_t value = constants[i]->get_value().get_value<uint8_t>();
	//		llvm::Constant* llvm_constant = llvm::ConstantInt::get(llvm_type, value, false);
	//		m_llvm_constants[i] = llvm_constant;
	//		break;
	//	}
	//	case IRBasicType::UINT64: {
	//		uint64_t value = constants[i]->get_value().get_value<uint8_t>();
	//		llvm::Constant* llvm_constant = llvm::ConstantInt::get(llvm_type, value, false);
	//		m_llvm_constants[i] = llvm_constant;
	//		break;
	//	}
	//	case IRBasicType::FLOAT: {
	//		float value = constants[i]->get_value().get_value<float>();
	//		llvm::Constant* llvm_constant = llvm::ConstantFP::get(llvm_type, value);

	//		m_llvm_constants[i] = llvm_constant;
	//		break;
	//	}
	//	case IRBasicType::DOUBLE: {
	//		double value = constants[i]->get_value().get_value<double>();
	//		llvm::Constant* llvm_constant = llvm::ConstantFP::get(llvm_type, value);
	//		m_llvm_constants[i] = llvm_constant;
	//		break;
	//	}
	//	case IRBasicType::BOOL:
	//		break;
	//	case IRBasicType::STRING:
	//		break;
	//	case IRBasicType::ERROR:
	//		break;
	//	case IRBasicType::VOID:
	//		break;
	//	default:
	//		break;
	//	}
	//}
	//
	////m_current_fn
	//m_module->functions();

	//// #TODO ogarnac ten switch 
	//auto blocks = current_fn->get_basic_blocks();
	//for (size_t i = 0; i < blocks.size(); i++) {
	//	auto current_blk = blocks[i];
	//	m_builder->SetInsertPoint(m_llvm_basic_blocks[i]);

	//	for (auto* triple : current_blk->get_all_triples()) {
	//		IROperation operation = triple->get_ir_operation();
	//		IRBasicType type = triple->get_data_type();
	//		switch (operation)
	//		{
	//		case IROperation::ADD: {
	//			IRBasicType type = triple->get_data_type();
	//			convert_arithmetic_operation(IRDataTypeTraits::is_integer(type) ? llvm::Instruction::BinaryOps::Add : llvm::Instruction::BinaryOps::FAdd, triple);
	//			break;
	//		}
	//		case IROperation::SUB: {
	//			IRBasicType type = triple->get_data_type();
	//			convert_arithmetic_operation(IRDataTypeTraits::is_integer(type) ? llvm::Instruction::BinaryOps::Sub : llvm::Instruction::BinaryOps::FSub, triple);
	//			break;
	//		}
	//		case IROperation::MUL: {
	//			IRBasicType type = triple->get_data_type();
	//			convert_arithmetic_operation(IRDataTypeTraits::is_integer(type) ? llvm::Instruction::BinaryOps::Mul : llvm::Instruction::BinaryOps::FMul, triple);
	//			break;
	//		}
	//		case IROperation::DIV: {
	//			IRBasicType type = triple->get_data_type();
	//			if (IRDataTypeTraits::is_integer(type))
	//				convert_arithmetic_operation(IRDataTypeTraits::is_unsigned(type) ? llvm::Instruction::BinaryOps::UDiv : llvm::Instruction::BinaryOps::SDiv, triple);
	//			else
	//				convert_arithmetic_operation(llvm::Instruction::BinaryOps::FDiv, triple);
	//			break;
	//		}
	//		case IROperation::MOD: {
	//			IRBasicType type = triple->get_data_type();
	//			if (IRDataTypeTraits::is_integer(type))
	//				convert_arithmetic_operation(IRDataTypeTraits::is_unsigned(type) ? llvm::Instruction::BinaryOps::URem : llvm::Instruction::BinaryOps::SRem, triple);
	//			else
	//				convert_arithmetic_operation(llvm::Instruction::BinaryOps::FRem, triple);
	//			break;
	//		}
	//		case IROperation::ASSIGN: {
	//			//auto variable = triple->m_op1.get_variable();
	//			auto variable = triple->m_operands[0].get_variable();
	//			//llvm::Value* value = get_operand_value(triple->m_op2);
	//			llvm::Value* value = get_operand_value(triple->m_operands[1]);
	//			m_variable_values[variable->m_index] = value;
	//			break;
	//		}
	//		case IROperation::CAST: {
	///*		auto dst_llvm_type = get_llvm_type(triple->m_op1.get_data_type());
	//			auto src_type = triple->m_op2.get_data_type();
	//			auto dst_type = triple->m_op1.get_data_type();
	//			auto value = get_operand_value(triple->m_op2);*/
	//			auto dst_llvm_type = get_llvm_type(triple->m_operands[0].get_data_type());
	//			auto src_type = triple->m_operands[1].get_data_type();
	//			auto dst_type = triple->m_operands[0].get_data_type();
	//			auto value = get_operand_value(triple->m_operands[1]);

	//			auto casted_value = auto_cast(value, dst_llvm_type, IRDataTypeTraits::is_signed(src_type), IRDataTypeTraits::is_signed(dst_type));
	//			// change to set_operand_value();
	//			m_triple_values[triple->m_global_index] = casted_value;
	//			break;
	//		}
	//		case IROperation::FUNCTION_CALL: {
	//			llvm::CallInst* call_inst = nullptr;
	//			
	//			size_t called_function_index = triple->m_operands[0].get_function()->get_index();
	//			llvm::Function* called_fn = m_llvm_functions[called_function_index];
	//			llvm::FunctionType* fn_type = called_fn->getFunctionType();
	//			
	//			std::vector<llvm::Value*> args;
	//			for (size_t i = 1; i < triple->m_operands.size();i++) {
	//				IROperand op = triple->m_operands[i];
	//				llvm::Value* arg = get_operand_value(op);
	//				args.push_back(arg);
	//			}

	//			call_inst = m_builder->CreateCall(fn_type,
	//				called_fn,
	//				args);

	//			m_triple_values[triple->m_global_index] = call_inst;
	//			break;
	//		}
	//		case IROperation::RETURN: {
	//			if (triple->m_operands.size()>0) {
	//				llvm::Value* ret_value = get_operand_value(triple->m_operands[0]);
	//				m_builder->CreateRet(ret_value);
	//			}
	//			else
	//				m_builder->CreateRetVoid();
	//			break;
	//		}
	//		default:
	//			break;
	//		}
	//	}
	//}

	//if (llvm::verifyModule(*m_module, &llvm::errs())) {
	//	llvm::errs() << "Module verification failed!\n";
	//}

	//m_llvm_basic_blocks.clear();
//}