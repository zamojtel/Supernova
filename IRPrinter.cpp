
std::string IRPrinter::ir_operation_to_string(const IROperation op) {
	switch (op)
	{
	case IROperation::ADD:
		return "ADD";
	case IROperation::ASSIGN:
		return "ASSIGN";
	case IROperation::DIV:
		return "DIV";
	case IROperation::MOD:
		return "MOD";
	case IROperation::MUL:
		return "MUL";
	case IROperation::SUB:
		return "SUB";
	case IROperation::RETURN:
		return "RETURN";
	case IROperation::CAST:
		return "CAST";
	case IROperation::GT:
		return ">";
	case IROperation::GE:
		return ">=";
	case IROperation::LT:
		return "<";
	case IROperation::LE:
		return "<=";
	case IROperation::EQ:
		return "==";
	case IROperation::NEQ:
		return "!=";
	case IROperation::JC:
		return "JC";
	case IROperation::JMP:
		return "JMP";
	case IROperation::REINTERPRET_CAST:
		return "REINTERPRET_CAST";
	case IROperation::FUNCTION_CALL:
		return "FUNCTION_CALL";
	case IROperation::COPY:
		return "COPY";
	case IROperation::INC:
		return "INC";
	case IROperation:: DEC:
		return "DEC";
	case IROperation::MEMBER_ACCESS:
		return "MEMBER_ACCESS";
	case IROperation::ARRAY_ACCESS: {
		return "ARRAY_ACCESS";
	}
	case IROperation::ASSERT: {
		return "ASSERT";
	}
	case IROperation::PRINT: {
		return "PRINT";
	}
	default:
		throw std::runtime_error("can't find such ir operation");
	}
}

void IRPrinter::print_variable(const IRVariable* v) {
	std::cout << "V" << v->m_index << " "<<v->m_identifier<<" "<< v->get_data_type().to_string() << std::endl;
}

void IRPrinter::print_variables(const IRFunction& p) {
	for (int i = 0; i < p.get_variables().size(); i++)
		print_variable(p.get_variable(i));
	std::cout << std::endl;
}

void IRPrinter::print_ir_representation(IRProgram& p) {
	const std::vector<IRGlobalVariable*>& global_variables = p.get_global_variables();
	std::cout << "Global Variables: " << std::endl;

	for (size_t i = 0; i < global_variables.size();i++) {
		std::string msg = std::format("Global_V{} with identifier: {} ",i,global_variables.at(i)->get_variable_name());
		std::cout << msg << std::endl;
	}

	for (const auto& [name,functions] : p.get_functions()) {
		for (auto *fn : functions) {
			std::cout << std::endl;
			std::cout << "Function name: " << fn->get_name() << std::endl;
			std::cout << "============================" << std::endl;
			std::cout << "Parameters: " << std::endl;
			for (auto *param : fn->get_parameters())
				//std::cout << IRDataTypeTraits::get_name(param->get_data_type()) << " " << param->get_variable_name() << " " << std::endl;
				std::cout << param->get_data_type().to_string() << " " << param->get_variable_name() << " " << std::endl;
			std::cout << "============================" << std::endl;

			std::cout << "Variables: " << std::endl;
			print_variables(*fn);

			for (size_t i = 0; i < fn->get_basic_blocks().size(); i++) {
				IRBasicBlock* current_blk = fn->get_basic_blk(i);
				std::cout << "Basic Block: " << i <<" "<<current_blk->get_basic_blk_name()<< std::endl;
				for (auto* t : current_blk->get_all_triples())
					print_triple(t);
			}
		}
	}
}

void IRPrinter::print_triple(IRTriple* triple) {
	// TODO remove get_name(...)
	std::string data_type_str = triple->get_data_type().to_string();
	size_t gl_index = triple->get_global_index();
	std::cout <<gl_index << " : "<< data_type_str << " T" << triple->m_index << " " << ir_operation_to_string(triple->m_operation) << " ";
	for (size_t i = 0; i < triple->m_operands.size();i++) {
		print_operand(triple->m_operands[i]);
		std::cout << " ";
	}

	std::cout << std::endl;
}

void IRPrinter::print_constant(IRConstant* c) {

	IRBasicType type = c->get_value().get_basic_type();


	switch (type)
	{
	case IRBasicType::INT8:
	{
		std::cout << "CONSTANT " <<(int) c->get_value().get_value<int8_t>();
		break;
	}
	case IRBasicType::INT16: {
		std::cout << "CONSTANT " << c->get_value().get_value<int16_t>();
		break;
	}
	case IRBasicType::INT32: {
		std::cout << "CONSTANT " << c->get_value().get_value<int32_t>();
		break;
	}
	case IRBasicType::INT64: {
		std::cout << "CONSTANT " << c->get_value().get_value<int64_t>();
		break;
	}
	case IRBasicType::UINT8:
	{
		std::cout << "CONSTANT " <<(int) c->get_value().get_value<uint8_t>();
		break;
	}
	case IRBasicType::UINT16: {
		std::cout << "CONSTANT " << c->get_value().get_value<uint16_t>();
		break;
	}
	case IRBasicType::UINT32: {
		std::cout << "CONSTANT " << c->get_value().get_value<uint32_t>();
		break;
	}
	case IRBasicType::UINT64: {
		std::cout << "CONSTANT " << c->get_value().get_value<uint64_t>();
		break;
	}
	case IRBasicType::FLOAT: {
		std::cout << "CONSTANT " << c->get_value().get_value<float>();
		break;
	}
	case IRBasicType::DOUBLE: {
		std::cout << "CONSTANT " << c->get_value().get_value<double>();
		break;
	}
	//case IRBasicType::STRING: {
	//	std::cout << "CONSTANT EMPTY";
	//	break;
	//}
	case IRBasicType::BOOL: {
		bool value = c->get_value().get_value<bool>();
		if (value)
			std::cout << "CONSTANT True";
		else
			std::cout << "CONSTANT False";
		break;
	}
	}

}

void IRPrinter::print_operand(const IROperand& op) {

	switch (op.m_operand_type)
	{
	case IROperandType::CONSTANT: {
		IRConstant* c = op.get_constant();
		print_constant(c);
		break;
	}
	case IROperandType::TRIPLE: {
		IRTriple* triple = op.get_triple();
		std::cout << "T" << triple->m_index;
		break;
	}
	case IROperandType::VARIABLE: {
		IRVariable* v = op.get_variable();
		std::cout << "[V"<< v->m_index<<","<<v->get_variable_name()<<"]";
		break;
	}
	case IROperandType::NO_OPERAND: {
		std::cout << "NO OPERAND";
		break;
	}
	case IROperandType::DATA_TYPE: {
		std::string type_ref_str = op.get_data_type().to_string();
		std::cout << type_ref_str;
		break;
	}
	case IROperandType::BASIC_BLOCK: {
		std::cout << "BASIC BLOCK " << op.get_basic_block()->get_index();
		break;
	}
	case IROperandType::FUNCTION: {
		std::cout << "FUNCTION " << op.get_function()->get_name();
		break;
	}
	case IROperandType::MEMBER: {
		std::cout << "MEMBER " << op.get_member()->get_field_name();
		break;
	}
	default:
		break;
	}
}

void IRPrinter::print_errors(const IRErrorCollector& c) {
	for (auto error : c.get_errors())
		std::cout << "Line: " << error->get_line_number() << " Error: " << error->get_message() << std::endl;
	std::cout << std::endl;
}

void IRPrinter::print_all_data_types_with_size(IRProgram& p) {
	IRDataTypeManager * dtm = p.get_dtm_manager();
	std::vector<IRDataTypeNode*> all_types = dtm->get_all_data_types();
	std::cout << "All data types with sizes: " << std::endl;
	for (auto *type : all_types) {
		std::string data_type_name = TypeRef{ type }.to_string();
		//if (data_type_name == "A") {
		//	int x = 123;
		//}

		if (type->has_size()) {
			size_t data_type_size = type->get_size().value();
			std::cout << data_type_name <<" "<< data_type_size << std::endl;
		}
		else
			std::cout << data_type_name << " no size has been set " << std::endl;
	}

}