
//void func() {
//	// 1. Kontekst i modu³
//	llvm::LLVMContext* context = new llvm::LLVMContext{};
//	auto module = std::make_unique<llvm::Module>("MyModule", *context);
//	llvm::IRBuilder<> builder(*context);
//
//	// 2. Typy: i32 (int32_t)
//	llvm::Type* i32Ty = llvm::Type::getInt32Ty(*context);
//
//	// 3. Sygnatura funkcji: i32 add(i32 a, i32 b)
//	std::vector<llvm::Type*> paramTypes{ i32Ty, i32Ty };
//	llvm::FunctionType* fnType =
//		llvm::FunctionType::get(
//			/*Result*/ i32Ty,
//			/*Params*/ paramTypes,
//			/*isVarArg*/ false);
//
//	llvm::Function* addFn = llvm::Function::Create(
//		fnType,
//		llvm::Function::ExternalLinkage,
//		"add",
//		module.get()
//	);
//
//	// 4. Nazwij argumenty (³adniejsze IR)
//	auto argsIter = addFn->arg_begin();
//	llvm::Argument* argA = argsIter++;
//	argA->setName("a");
//	llvm::Argument* argB = argsIter++;
//	argB->setName("b");
//
//	// 5. Stwórz blok podstawowy "entry" i ustaw tam buildera
//	llvm::BasicBlock* entryBB = llvm::BasicBlock::Create(*context, "entry", addFn);
//	builder.SetInsertPoint(entryBB);
//
//	// 6. a + b
//	llvm::Value* sum = builder.CreateAdd(argA, argB, "sum");
//
//	// 7. return a+b
//	builder.CreateRet(sum);
//
//	// 8. Wypisz ca³y modu³ jako tekstowe LLVM IR
//	module->print(llvm::outs(), nullptr);
//}

//llvm::BasicBlock* entryBB = llvm::BasicBlock::Create(*context, "entry", addFn);
//builder.SetInsertPoint(entryBB);


// program == one function
void IRToLLVMIRConverter::create_llvm_basic_blocks(IRFunction *current_fn) {
	for (int i = 0; i < current_fn->get_basic_blocks().size(); i++) {
		llvm::BasicBlock* entryBB = llvm::BasicBlock::Create(*m_context, "block"+i, m_current_fn);
		m_llvm_basic_blocks.push_back(entryBB);
	}
}

llvm::Value* IRToLLVMIRConverter::get_operand_value(const IROperand& op)  {
	switch (op.m_operand_type)
	{
	case IROperandType::CONSTANT:
		return m_llvm_constants.at(op.get_constant()->get_index());
	case IROperandType::VARIABLE:
		return m_variable_values.at(op.get_variable()->get_index());
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

	calc_value = m_builder->CreateBinOp(op_code, left_value, right_value);
	// here the global index will be passed
	m_triple_values[triple->m_global_index] = calc_value;
}

llvm::Value* IRToLLVMIRConverter::auto_cast(llvm::Value* src,llvm::Type* dstTy,bool srcIsSigned, bool dstIsSigned) {
	auto op = llvm::CastInst::getCastOpcode(src,srcIsSigned,dstTy,dstIsSigned);

	return m_builder->CreateCast(op, src, dstTy);
}

//auto llvm_type = llvm::Type::getInt8Ty(*m_context);
//llvm::Type* get_llvm_type(IRBasicType type);
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
	//case IRBasicType::STRING:
		//break;
	//case IRBasicType::ERROR:
	//	//break;
	default:
		throw std::runtime_error("no suitable data type");
		break;
	}

}

// nazwy pozmieniac bo az boli
void IRToLLVMIRConverter::create_llvm_function(IRFunction* current_fn) {
	// TODO UNCOMMENT AND REPAIR LATER
	
	//llvm::Type* fn_return_type = nullptr;
	//std::vector<llvm::Type*> param_types;

	//const std::vector<IRVariable*>& parameters = current_fn->get_parameters();
	//for (size_t i = 0; i < parameters.size(); i++) {
	//	param_types.push_back(get_llvm_type(parameters[i]->get_data_type()));
	//}

	//IRBasicType ir_type = current_fn->get_return_type();
	//fn_return_type = get_llvm_type(ir_type);

	//llvm::FunctionType* fnType =
	//	llvm::FunctionType::get(
	//		fn_return_type,
	//		param_types,
	//		false
	//	);

	//std::string fn_name = current_fn->get_name();
	//llvm::Function * llvm_current_fn = llvm::Function::Create(
	//	fnType,
	//	llvm::Function::ExternalLinkage,
	//	fn_name,
	//	m_module
	//);

	//m_llvm_functions[current_fn->get_index()] = llvm_current_fn;
}

void IRToLLVMIRConverter::convert() {

	m_context = new llvm::LLVMContext{};
	m_module = new llvm::Module{ "MyModule", *m_context };

	llvm::IRBuilder<> builder{ *m_context };
	m_builder = &builder;

	auto &functions = m_ir_program->get_functions();
	for (auto &[name,fn_vec] : functions) {
		for (auto *fn : fn_vec)
			create_llvm_function(fn);
	}

	for (const auto& [name,functions] : m_ir_program->get_functions()) {
		for (size_t i = 0; i < functions.size();i++)
			convert_function(functions[i]);
	}

	if (llvm::verifyModule(*m_module, &llvm::errs())) {
		llvm::errs() << "Module verification failed!\n";
	}

	m_module->print(llvm::outs(), nullptr);
}

void IRToLLVMIRConverter::convert_function(IRFunction * current_fn) {

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
	///*			auto dst_llvm_type = get_llvm_type(triple->m_op1.get_data_type());
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
}