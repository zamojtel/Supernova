
IRChecker::IRChecker(IRProgram* p) : m_ir_program{ p }, m_dtm{p->get_dtm_manager()} {}

// TODO: NAPRAWIC ten check_triple();
void IRChecker::check_function(IRFunction* fn) {
	for (int i = 0; i < fn->m_basic_blocks.size(); i++) {
		auto& triples = fn->m_basic_blocks[i]->get_all_triples();
		//for (int j = 0; j < triples.size(); j++)
			//check_triple(triples[j]);
	}
}

// TODO CORRECT THIS CHECKER
void IRChecker::check_triple(IRTriple* triple)
{
	IROperandType left_op_type = IROperandType::NO_OPERAND;
	IROperandType right_op_type = IROperandType::NO_OPERAND;
	IROperand* op1 = nullptr;
	IROperand* op2 = nullptr;
	IROperand* op3 = nullptr;
	if (triple->m_operands.size() == 1) {
		//left_op_type = triple->m_operands[0].m_operand_type;
		op1 = &triple->m_operands[0];
	}
	else if(triple->m_operands.size()==2) {
		//left_op_type = triple->m_operands[0].m_operand_type;
		//right_op_type = triple->m_operands[1].m_operand_type;
		op1 = &triple->m_operands[0];
		op2 = &triple->m_operands[1];
	}
	else if (triple->m_operands.size() > 2) {
		op1 = &triple->m_operands[0];
		op2 = &triple->m_operands[1];
		op3 = &triple->m_operands[2];
	}

	IROperation operation = triple->m_operation;
	size_t number_of_operands = get_number_of_operands_for_operation(operation);

	switch (operation)
	{
	case IROperation::ADD:
	case IROperation::DIV:
	case IROperation::MUL:
	case IROperation::MOD:
	case IROperation::SUB:
	case IROperation::BITWISE_AND:
	case IROperation::BITWISE_OR:
	case IROperation::BITWISE_XOR:
	{
		TypeRef data_type_ref = check_arithmetic_operation_possible(triple);
		triple->m_data_type = data_type_ref;
		break;
	}
	case IROperation::ASSIGN: {
		if (!check_operand_types(*op1, *op2)) {
			m_listener->add_error(triple->m_line_number, "can't assign value of different types");
		}
		break;
	}
	case IROperation::INC:
	case IROperation::DEC: {
		triple->m_data_type = op1->get_data_type();
		break;
	}
	case IROperation::JC: {
		if (op1->get_data_type().is_basic_data_type()) {
			if(!op1->get_data_type().is_boolean())
				m_listener->add_error(triple->m_line_number,"expected bool type as a condition");
			break;
		}
	}
	case IROperation::COPY: {
		triple->m_data_type = op1->get_data_type();
		break;
	}
	case IROperation::CAST: {
		// TODO ADD CHECKS
		triple->m_data_type = op1->get_data_type();
		break;
	}
	case IROperation::REINTERPRET_CAST: {
		TypeRef type_ref = op1->get_data_type();
		TypeRef expr_type_ref = op2->get_data_type();

		if (!check_data_type_size(type_ref, expr_type_ref)) {
			m_listener->add_error(triple->m_line_number,"can't reinterpret cast to type of different size");
		}

		triple->m_data_type = op1->get_data_type();

		break;
	}
	case IROperation::RETURN: {
		break;
	}
	case IROperation::LT:
	case IROperation::LE:
	case IROperation::GT:
	case IROperation::GE:
	case IROperation::EQ:
	case IROperation::NEQ:
	{
		TypeRef type1 = op1->get_data_type().remove_reference();
		TypeRef type2 = op2->get_data_type().remove_reference();
		
		// zrobic to bez iteratora 
		// sprawdzic size wybrac wiekszy 

		if (type1.is_array() || type2.is_array()) {
			size_t arr1_size = type1.is_array() ? static_cast<IRArrayNode*>(type1.get_data_type_node())->m_count : 0;
			size_t arr2_size = type2.is_array() ? static_cast<IRArrayNode*>(type2.get_data_type_node())->m_count : 0;
			
			size_t size = std::max(arr1_size,arr2_size);
			TypeRef type = m_dtm->add_array(m_dtm->get_basic_type_node(IRBasicType::BOOL),size);

			triple->m_data_type = type;
		}
		else {
			triple->m_data_type = m_dtm->get_basic_type_node(IRBasicType::BOOL);
		}

		break;
	}
	case IROperation::FUNCTION_CALL:{
		triple->m_data_type = op1->get_function()->get_return_type();
		break;
	}
	case IROperation::JMP:
	{
		break;
	}
	case IROperation::MEMBER_ACCESS: {
		triple->m_data_type = op2->get_data_type();
		break;
	}
	case IROperation::ARRAY_ACCESS: {
		TypeRef data_type_index_ref = op2->get_data_type();

		if (!data_type_index_ref.is_integer()) {
			m_listener->add_error(triple->m_line_number,"index must be of integer type");
		}

		TypeRef data_type_ref = op1->get_data_type();
		if (data_type_ref.is_array())
			triple->m_data_type = op1->get_data_type().remove_array();
		else if (data_type_ref.is_pointer_with_qualifiers())
			triple->m_data_type = op1->get_data_type().remove_pointer_with_qualifiers();
		else
			m_listener->add_error(triple->m_line_number, "expected pointer or array type");
		break;
	}
	case IROperation::ASSERT: {
		TypeRef data_type = op1->get_data_type();
		if (!data_type.is_boolean()) {
			m_listener->add_error(triple->m_line_number, "expected boolean value");
		}
		
		break;
	}
	case IROperation::PRINT: {
		// checking 
		TypeRef data_type = op1->get_data_type();
		if (!data_type.is_numeric())
			m_listener->add_error(triple->m_line_number	,"expected numeric type value");

		break;
	}
	case IROperation::ADREESS_OF: {
		TypeRef dataType = op1->get_data_type();
		dataType = m_dtm->add_pointer(dataType);

		triple->m_data_type = dataType;
		break;
	}
	case IROperation::DEREFERENCE: {
		TypeRef dataType = op1->get_data_type();

		triple->m_data_type = dataType.remove_pointer_with_qualifiers();
		break;
	}
	case IROperation::INIT_ASSIGN: {
		TypeRef dataType = op1->get_data_type();

		triple->m_data_type = dataType;
		break;
	}
	case IROperation::SELECT: {
		TypeRef type1 = op1->get_data_type();
		TypeRef type2 = op2->get_data_type();
		TypeRef type3 = op3->get_data_type();

		size_t condition_arr_size = type1.is_array() ? static_cast<IRArrayNode*>(type1.get_data_type_node())->m_count : 1;
		size_t expr_true_arr_size = type2.is_array() ? static_cast<IRArrayNode*>(type2.get_data_type_node())->m_count : 1;
		size_t expr_false_arr_size = type3.is_array() ? static_cast<IRArrayNode*>(type3.get_data_type_node())->m_count : 1;
		
		if (condition_arr_size % expr_true_arr_size != 0 || condition_arr_size% expr_false_arr_size != 0 ) {
			m_listener->add_error(triple->m_line_number, "can't execute broadcasting");
		}

		TypeRef op2_element_type = type2.remove_all_extents();
		TypeRef op3_element_type = type2.remove_all_extents();
		if (op2_element_type!=op3_element_type) {
			m_listener->add_error(triple->m_line_number, "can't execute select on different value types");
		}

		TypeRef element_type = type2.remove_all_extents();
		TypeRef result_type = m_dtm->add_array(element_type, condition_arr_size);

		triple->m_data_type = result_type;
		break;
	}
	case IROperation::LEFT_SHIFT: {
		if (!op2->get_data_type().is_integer()) {
			m_listener->add_error(triple->m_line_number, "right operand must be integer");
		}

		triple->m_data_type = op1->get_data_type();
		break;
	}
	case IROperation::RIGHT_SHIFT: {
		if (!op2->get_data_type().is_integer()) {
			m_listener->add_error(triple->m_line_number, "right operand must be integer");
		}

		triple->m_data_type = op1->get_data_type();
		break;
	}
	case IROperation::UNARY_MINUS: {

		if (!op1->get_data_type().is_numeric()) {
			m_listener->add_error(triple->m_line_number, "operand must be a number");
		}

		triple->m_data_type = op1->get_data_type();
		break;
	}
	case IROperation::MALLOC: {
		if (op1->get_data_type().is_integer()) {
			m_listener->add_error(triple->m_line_number,"can't allocate non-integral number of bytes");
		}

		triple->m_data_type = op1->get_data_type();
		break;
	}
	case IROperation::FREE: {

		if (!op1->get_data_type().remove_qualifiers().remove_reference().is_pointer()) {
			m_listener->add_error(triple->m_line_number, "can't free non-pointer variables");
		}

		triple->m_data_type = op1->get_data_type();
		break;
	}

	default:
		throw std::runtime_error("unknow operation while checking triple");
	}
}

// 
bool IRChecker::check_data_type_size(const TypeRef& type1,const TypeRef& type2) const {
	//return ir_data_type_traits[(int)type1].size == ir_data_type_traits[(int)type2].size;
	return true;
}


bool IRChecker::check_operand_types(const IROperand& op1, const IROperand& op2) const {
	std::string type1 = op1.get_data_type().to_string();
	std::string type2 = op2.get_data_type().to_string();
	TypeRef type_ref_op1 = op1.get_data_type();
	TypeRef type_ref_op2 = op2.get_data_type();

	if (type_ref_op1.is_error() || type_ref_op2.is_error())
		return true;

	if (type_ref_op1 == type_ref_op2)
		return true;
	else
		return false;

}

size_t IRChecker::get_number_of_operands_for_operation(IROperation op) {
	switch (op)
	{
	case IROperation::ADD:
	case IROperation::DIV:
	case IROperation::MOD:
	case IROperation::MUL:
	case IROperation::SUB:
	case IROperation::ASSIGN:
		return 2;
	case IROperation::RETURN:
		return 1;
	default:
		break;
	}
}

void IRChecker::set_listener(IRCheckerListener* listener) { m_listener = listener; }

TypeRef IRChecker::check_arithmetic_operation_possible(IRTriple *triple) const {
	TypeRef r1 = triple->m_operands[0].get_data_type();
	TypeRef r2 = triple->m_operands[1].get_data_type();
	IROperation operation = triple->get_ir_operation();

	if (r1.is_pointer_with_qualifiers() && r2.is_pointer_with_qualifiers()) {

		if (r1.remove_pointer_with_qualifiers() == r2.remove_pointer_with_qualifiers() && operation == IROperation::SUB)
			return m_dtm->get_basic_type_node(IRBasicType::INT64);
		else {
			std::string msg{ "invalid operation on pointers" };
			m_listener->add_error(triple->m_line_number,msg);
			IRDataTypeManager* dtm = m_ir_program->get_dtm_manager();
			return dtm->get_error();
		}
	}

	if (r1.is_pointer_with_qualifiers()) {
		if (r2.is_integer() && (operation == IROperation::ADD || operation == IROperation::SUB))
			return r1.get_data_type_node();
		else if (r2.is_integer() && !(operation == IROperation::ADD || operation == IROperation::SUB))
			return m_dtm->get_error();
		else
			return m_dtm->get_error();
	}

	if (r2.is_pointer_with_qualifiers()) {
		if (r1.is_integer() && (operation == IROperation::ADD || operation == IROperation::SUB))
			return r2.get_data_type_node();
		else if (r1.is_integer() && !(operation == IROperation::ADD || operation == IROperation::SUB))
			return m_dtm->get_error();
		else
			return m_dtm->get_error();
	}

	// dobra tutaj trzeba rozpatrzeæ CONST int [] arr;
	if (r1.is_array() && r2.is_array()) {
		std::vector<size_t> arr1_dimensions = r1.get_all_extents_size();
		std::vector<size_t> arr2_dimensions = r2.get_all_extents_size();
		
		if (arr1_dimensions.size() == 1 && arr2_dimensions.size() == 1) {
			size_t arr1_size = static_cast<IRArrayNode*>(r1.get_data_type_node())->m_count;
			size_t arr2_size = static_cast<IRArrayNode*>(r2.get_data_type_node())->m_count;
			size_t max_size = std::max(arr1_size, arr2_size);
			size_t min_size = std::max(arr1_size, arr2_size);
			if (arr1_size >= arr2_size) {
				if (max_size % min_size == 0)
					// mozemy robic broadcasting
					return r1.get_data_type_node();
				else
					// nie mozemy robic broadcastingu
					return m_dtm->get_error();
			}
			else {
				if (max_size % min_size == 0)
					return r2.get_data_type_node();
				else
					// nie mozemy robic broadcastingu
					return m_dtm->get_error();
			}
		}
		else if (arr1_dimensions == arr2_dimensions) {
			TypeRef array_content_ref1 = r1.remove_all_extents();
			TypeRef array_content_ref2 = r2.remove_all_extents();

			// DO PRZEMYSLENIA 
			return r1.get_data_type_node();
		}
		else
			return m_dtm->get_error();
	}
	else if (r1.is_array() && r2.is_numeric())
		return r1.get_data_type_node();
	else if (r1.is_numeric() && r2.is_array())
		return r2.get_data_type_node();

	if (r1.is_composite() || r2.is_composite())
		return m_dtm->get_error();

	if (r1.is_numeric() && r2.is_numeric())
		return r1.get_data_type_node();

}

void IRChecker::deduce_triple_data_type(IRTriple* triple) {
	IROperation operation = triple->get_ir_operation();
	IROperand* op1 = nullptr;
	IROperand* op2 = nullptr;

	if (triple->m_operands.size() == 1)
		op1 = &triple->m_operands[0];
	else if(triple->m_operands.size() == 2) {
		op1 = &triple->m_operands[0];
		op2 = &triple->m_operands[1];
	}

	switch (operation)
	{
	case IROperation::ASSIGN: {
		if (!check_operand_types(*op1, *op2)) {
			triple->m_data_type = m_dtm->get_error();
			return;
		}

		triple->m_data_type = op1->get_data_type();
		return;
	}
	// OK!
	case IROperation::LE:
	case IROperation::LT:
	case IROperation::GE:
	case IROperation::GT:
	case IROperation::EQ:
	case IROperation::NEQ:
	{ 
		if (!check_operand_types(*op1, *op2)) {
			triple->m_data_type = m_dtm->get_error();
			return;
		}
		
		triple->m_data_type = m_dtm->get_bool();
		return;
	}
	case IROperation::ADD:
	case IROperation::SUB:
	case IROperation::MUL:
	case IROperation::DIV:
	case IROperation::MOD:
	case IROperation::BITWISE_AND:
	case IROperation::BITWISE_OR:
	{
		if (!check_operand_types(*op1,*op2)) {
			triple->m_data_type = m_dtm->get_error();
			return;
		}

		TypeRef data_type_ref = check_arithmetic_operation_possible(triple);
		triple->m_data_type = data_type_ref;
		//if (op1->m_operand_type == IROperandType::DATA_TYPE && op2->m_operand_type == IROperandType::DATA_TYPE) {
		//	TypeRef ref1 = op1->get_data_type();
		//	TypeRef ref2 = op2->get_data_type();
		//	if (ref1.is_array() && ref2.is_array()) {

		//		if (ref1 == ref2) {
		//			// without broadcasting 
		//			triple->m_data_type = op1->get_data_type();
		//		}
		//		else {
		//			//if () {

		//			//}
		//			// broadcast 
		//			// wiêkszy rozmiar tablicy powinien zostac zwrócony 
		//			size_t size_1 = static_cast<IRArrayNode*>(ref1.get_data_type_node())->m_size;
		//			size_t size_2 = static_cast<IRArrayNode*>(ref2.get_data_type_node())->m_size;
		//			if (size_1 > size_2)
		//				triple->m_data_type = op1->get_data_type();
		//			else
		//				triple->m_data_type = op2->get_data_type();
		//		}
		//	}
		//}

		//if (op1->m_operand_type != IROperandType::BASIC_BLOCK && op1->m_operand_type != IROperandType::NO_OPERAND)
		//	triple->m_data_type = op1->get_data_type();
		return;
	}
	case IROperation::RETURN: {
		//triple->m_data_type = m_ir_program->get_dtm_manager()->get_error();
		triple->m_data_type = m_dtm->get_error();
		return;
	}
	case IROperation::CAST: {
		//triple->m_data_type = op1->get_data_type();
		return;
	}
	case IROperation::REINTERPRET_CAST: {
		//triple->m_data_type = op1->get_data_type();
		return;
	}
	case IROperation::INC: {
		//triple->m_data_type = 
		return;
	}
	case IROperation::DEC: {
		
		return;
	}
	case IROperation::FUNCTION_CALL: {
		
		return;
	}
	default:
		break;
	}
}