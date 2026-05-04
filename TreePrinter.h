
class TreePrinter {
public:
	TreePrinter(){}
	void print_tree(const ReferencePtr<AbstractSyntaxTreeNode>& node,int space_between);
	void print_node(const ReferencePtr<AbstractSyntaxTreeNode>& node, int spaces_between);
	std::string get_binary_operator_symbol(OperationType op);
	std::string get_unary_operator_symbol(OperationType op);
};

std::string TreePrinter::get_binary_operator_symbol(OperationType op) {
	switch (op)
	{
	case OperationType::ADD: {
		return "+";
	}
	case OperationType::SUB: {
		return "-";
	}
	case OperationType::DIV: {
		return "/";
	}
	case OperationType::MUL: {
		return "*";
	}
	case OperationType::MOD: {
		return "%";
	}
	case OperationType::GT: {
		return ">=";
	}
	case OperationType::GE: {
		return ">=";
	}
	case OperationType::LT: {
		return "<";
	}
	case OperationType::LE: {
		return "<=";
	}
	case OperationType::EQ: {
		return "==";
	}
	case OperationType::NEQ: {
		return "!=";
	}
	default:
		break;
	}
}
std::string get_string_bool(bool value) {
	if (value)
		return "true";
	else
		return "false";
}

void TreePrinter::print_node(const ReferencePtr<AbstractSyntaxTreeNode> &node,int indentation) {

	int spaces = 0;
	std::string space_str = "";

	while (spaces < indentation) {
		space_str += " ";
		spaces++;
	}

	std::cout << space_str;
	TreeNodeType type = node->get_type();
	switch (type)
	{
	case TreeNodeType::PROG:{
		ReferencePtr<FunctionNode> casted_node = node.cast<FunctionNode>();
		std::cout << "PROG: " << std::endl;
		break;
	}
	case TreeNodeType::DECLARATION: {
		ReferencePtr<DeclarationNode> casted_node = node.cast<DeclarationNode>();
		std::cout << "DECLARATION: " << std::endl;
		break;
	}
	case TreeNodeType::ASSIGNMENT: {
		ReferencePtr<AssignmentNode> casted_node = node.cast<AssignmentNode>();
		std::cout << "ASSIGNMENT: " << std::endl;
		break;
	}
	case TreeNodeType::LIST: {
		std::cout << "LIST: " << std::endl;
		break;
	}
	case TreeNodeType::BIN_OPERATION: {
		ReferencePtr<BinaryOperatorNode> casted_node = node.cast<BinaryOperatorNode>();
		std::cout << "BINARY_OPERATION: " <<get_binary_operator_symbol(casted_node->m_op)<< std::endl;
		break;
	}
	case TreeNodeType::BOOLEAN_NOT: {
		ReferencePtr<BooleanNotNode> casted_node = node.cast<BooleanNotNode>();
		std::cout << "BOOLEAN_NOT: " << std::endl;
		break;
	}
	case TreeNodeType::AND: {
		ReferencePtr<AndNode> and_node = node.cast<AndNode>();
		std::cout << "AND: " << std::endl;
		break;
	}
	case TreeNodeType::OR: {
		ReferencePtr<AndNode> and_node = node.cast<AndNode>();
		std::cout << "OR: " << std::endl;
		break;
	}
	case TreeNodeType::IDENTIFIER: {
		ReferencePtr<IdentifierNode> casted_node = node.cast<IdentifierNode>();
		std::cout << "ID: " << casted_node->m_identifier << std::endl;
		break;
	}
	case TreeNodeType::CONSTANT: {
		ReferencePtr<ConstantNode> casted_node = node.cast<ConstantNode>();
		IRBasicType type = casted_node->m_constant_value.get_basic_type();
		ConstantValue c_value = casted_node->m_constant_value;
 
		switch (type)
		{
		case IRBasicType::INT8:
		{
			std::cout << "CONSTANT INT8:" << c_value.get_value<int8_t>() << std::endl;
			break;
		}
		case IRBasicType::INT16:
		{
			std::cout << "CONSTANT INT16:" << c_value.get_value<int16_t>() << std::endl;
			break;
		}
		case IRBasicType::INT32: {
			std::cout << "CONSTANT INT32:" << c_value.get_value<int32_t>() << std::endl;
			break;
		}
		case IRBasicType::INT64: {
			std::cout << "CONSTANT INT64:" << c_value.get_value<int64_t>() << std::endl;
			break;
		}
		case IRBasicType::UINT8:
		{
			std::cout << "CONSTANT UINT8:" << c_value.get_value<uint8_t>()<< std::endl;
			break;
		}
		case IRBasicType::UINT16:
		{
			std::cout << "CONSTANT UINT16:" << c_value.get_value<uint16_t>() << std::endl;
			break;
		}
		case IRBasicType::UINT32: {
			std::cout << "CONSTANT UINT32:" << c_value.get_value<uint32_t>() << std::endl;
			break;
		}
		case IRBasicType::UINT64:{
			std::cout << "CONSTANT UINT64:" << c_value.get_value<uint64_t>() << std::endl;
			break;
		}
		case IRBasicType::FLOAT: {
			std::cout << "CONSTANT FLOAT:" << c_value.get_value<float>() << std::endl;
			break;
		}
		case IRBasicType::DOUBLE: {
			std::cout << "CONSTANT DOUBLE:" << c_value.get_value<double>() << std::endl;
			break;
		}
		case IRBasicType::BOOL: {
			std::cout << "CONSTANT BOOL:" << c_value.get_value<bool>() << std::endl;
			break;
		}
		default:
			break;
		}

		break;
	}
	case TreeNodeType::BASIC_TYPE: {
		ReferencePtr<BasicTypeNode> casted_node = node.cast<BasicTypeNode>();
	
		switch (casted_node->m_basic_type)
		{
		case IRBasicType::UINT8:
		{
			std::cout << "Type: UINT8 " << std::endl;
			break;
		}
		case IRBasicType::UINT16:
		{
			std::cout << "Type: UINT16 " << std::endl;
			break;
		}
		case IRBasicType::UINT32:
		{
			std::cout << "Type: UINT32 " << std::endl;
			break;
		}
		case IRBasicType::UINT64:
		{
			std::cout << "Type: UINT64 " << std::endl;
			break;
		}
		case IRBasicType::INT8:
		{
			std::cout << "Type: INT8 " << std::endl;
			break;
		}
		case IRBasicType::INT16:
		{
			std::cout << "Type: INT16 " << std::endl;
			break;
		}
		case IRBasicType::INT32:
		{
			std::cout << "Type: INT32 " << std::endl;
			break;
		}
		case IRBasicType::INT64:
		{
			std::cout << "Type: INT64 " << std::endl;
			break;
		}
		case IRBasicType::FLOAT: {
			std::cout << "Type: FLOAT "<< std::endl;
			break;
		}
		case IRBasicType::DOUBLE: {
			std::cout << "Type: DOUBLE "<< std::endl;
			break;
		}
		default:
			break;
		}
		break;
	}
	case TreeNodeType::CAST: {
		ReferencePtr<CastNode> cast_node = node.cast<CastNode>();
		std::cout << "Cast: " << std::endl;
		break;
	}
	case TreeNodeType::BLOCK:{
		ReferencePtr<BlockNode> cast_node = node.cast<BlockNode>();
		std::cout << "Block: " << std::endl;
		break;
	}
	case TreeNodeType::IF: {
		ReferencePtr<IfNode> cast_node = node.cast<IfNode>();
		std::cout << "IF: " << std::endl;
		break;
	}
	case TreeNodeType::WHILE: {
		ReferencePtr<WhileNode> while_node = node.cast<WhileNode>();
		std::cout << "WHILE: " << std::endl;
		break;
	}
	case TreeNodeType::DO_WHILE: {
		ReferencePtr<DoWhileNode> do_while_node = node.cast<DoWhileNode>();
		std::cout << "DO_WHILE: " << std::endl;
		break;
	}
	case TreeNodeType::FOR: {
		ReferencePtr<ForNode> for_node = node.cast<ForNode>();
		std::cout << "FOR: " << std::endl;
		break;
	}
	case TreeNodeType::BREAK: {
		std::cout << "BREAK: " << std::endl;
		break;
	}
	case TreeNodeType::CONTINUE: {
		std::cout << "CONTINUE: " << std::endl;
		break;
	}
	case TreeNodeType::RETURN: {
		ReferencePtr<ReturnNode> return_node = node.cast<ReturnNode>();
		std::cout << "RETURN: " << std::endl;
		break;
	}
	case TreeNodeType::REINTERPRET_CAST: {
		ReferencePtr<ReinterpretNode> reinterpret_cast_node = node.cast<ReinterpretNode>();
		std::cout << "REINTERPRET_CAST: " << std::endl;
		break;
	}
	case TreeNodeType::FUNCTION: {
		ReferencePtr<FunctionNode> function_node = node.cast<FunctionNode>();
		std::cout << "FUNCTION: " << std::endl;
		break;
	}

	case TreeNodeType::FUNCTION_CALL: {
		ReferencePtr<FunctionCallNode> function_call_node = node.cast<FunctionCallNode>();
		std::cout << "FUNCTION_CALL: " << std::endl;
		break;
	}
	case TreeNodeType::PARAMETER: {
		ReferencePtr<FunctionParameterNode> parameter_node = node.cast<FunctionParameterNode>();
		std::cout << "PARAMETER: " << std::endl;
		break;
	}
	case TreeNodeType::INC: {
		ReferencePtr<IncrementationNode> inc_node = node.cast<IncrementationNode>();
		std::cout << "INC: " << std::endl;
		break;
	}
	case TreeNodeType::DEC: {
		ReferencePtr<DecrementationNode> dec_node = node.cast<DecrementationNode>();
		std::cout << "DEC:  " << std::endl;
		break;
	}
	case TreeNodeType::TYPE_MODIFIER: {
		ReferencePtr<TypeModifierNode> mod_node = node.cast<TypeModifierNode>();
		std::cout << "MOD: " << std::endl;
		break;
	}
	case TreeNodeType::ARRAY: {
		ReferencePtr<ArrayNode> arr_node = node.cast<ArrayNode>();
		std::cout << "ARRAY: " << std::endl;
		break;
	}
	case TreeNodeType::POINTER: {
		ReferencePtr<PointerNode> ptr_node = node.cast<PointerNode>();
		std::cout << "POINTER: " << std::endl;
		break;
	}
	case TreeNodeType::REFERENCE: {
		ReferencePtr<ReferenceNode> ref_node = node.cast<ReferenceNode>();
		std::cout << "REFERENCE: " << std::endl;
		break;
	}
	case TreeNodeType::DATA_TYPE: {
		ReferencePtr<DataTypeNode> ref_node = node.cast<DataTypeNode>();
		std::cout << "DATA_TYPE: " << std::endl;
		break;
	}
	case TreeNodeType::QUALIFIER: {
		ReferencePtr<QualifierNode> qualifier_node = node.cast<QualifierNode>();

		if (qualifier_node->get_mask() & IRQualifiersNode::CONST)
			std::cout << "CONST " << std::endl;
		else if (qualifier_node->get_mask() & IRQualifiersNode::VOLATILE)
			std::cout << "VOLATILE " << std::endl;
		else if (qualifier_node->get_mask() & (IRQualifiersNode::CONST | IRQualifiersNode::VOLATILE))
			std::cout << "CONST VOLATILE " << std::endl;

		break;
	}
	case TreeNodeType::STRUCT: {
		std::cout << "STRUCT " << std::endl;
		break;
	}
	case TreeNodeType::UNION: {
		std::cout << "UNION " << std::endl;
		break;
	}
	case TreeNodeType::MEMBER_DECLARATION: {
		std::cout << "MEMBER_DECLARATION " << std::endl;
		break;
	}
	case TreeNodeType::MEMBER_ACCESS: {
		std::cout << "MEMBER_ACCESS " << std::endl;
		break;
	}
	case TreeNodeType::ARRAY_ACCESS: {
		std::cout << "ARRAY_ACCESS " << std::endl;
		break;
	}
	case TreeNodeType::SIZE_OF: {
		std::cout << "SIZE_OF " << std::endl;
		break;
	}
	case TreeNodeType::ASSERT: {
		std::cout << "ASSERT " << std::endl;
		break;
	}
	case TreeNodeType::PRINT: {
		std::cout << "PRINT " << std::endl;
		break;
	}
	default:
		throw std::runtime_error("unknown tree node type");
		break;
	}
}

void TreePrinter::print_tree(const ReferencePtr<AbstractSyntaxTreeNode> &node,int space_between) {
	print_node(node,space_between);
	for (size_t i = 0; i < node->get_child_count();i++) {
		print_tree(node->get_child(i),space_between+1);
	}
}