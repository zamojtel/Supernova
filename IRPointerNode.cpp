
IRPointerNode::IRPointerNode(IRDataTypeManager* dtm, const TypeRef& e) : IRDataTypeNode{dtm}, m_element { e } {
	// constant size for pointer
	set_size(8);
}

IRDataTypeNodeType IRPointerNode::get_node_type() const { return IRDataTypeNodeType::POINTER; }
