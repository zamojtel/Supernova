
IRBasicTypeNode::IRBasicTypeNode(IRDataTypeManager* dtm,IRBasicType t) : IRDataTypeNode{dtm}, m_ir_data_type { t } {
	size_t size = 0;
	// size given in bytes
	switch (t)
	{
	case IRBasicType::CHAR:
	case IRBasicType::UINT8:
	case IRBasicType::INT8:
	case IRBasicType::BOOL: {
		size = 1;
		break;
	}
	case IRBasicType::UINT16:
	case IRBasicType::INT16: {
		size = 2;
		break;
	}
	case IRBasicType::FLOAT:
	case IRBasicType::UINT32:
	case IRBasicType::INT32: {
		size = 4;
		break;
	}
	case IRBasicType::DOUBLE:
	case IRBasicType::INT64:
	case IRBasicType::UINT64:
	case IRBasicType::STRING: {
		size = 8;
		break;
	}
	case IRBasicType::VOID: {
		size = 0;
		break;
	}
	default:
		throw std::runtime_error("unknown size for a given type");
		break;
	}
	set_size(size);
}

IRDataTypeNodeType IRBasicTypeNode::get_node_type() const { return IRDataTypeNodeType::BASIC_TYPE; };
