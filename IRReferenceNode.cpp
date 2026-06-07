
IRReferenceNode::IRReferenceNode(const TypeRef& r) : m_element{ r } {
	//set_size(r.get_size());
	set_size(8);
}

IRDataTypeNodeType IRReferenceNode::get_node_type() const { return IRDataTypeNodeType::REFERENCE; }

size_t IRReferenceNode::calculate_size() const { return m_element.get_size(); }
