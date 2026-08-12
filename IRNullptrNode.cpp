
IRNullptrNode::IRNullptrNode() {
	// constant size for pointer
	set_size(8);
}

IRDataTypeNodeType IRNullptrNode::get_node_type() const { return IRDataTypeNodeType::NULLPTR; }