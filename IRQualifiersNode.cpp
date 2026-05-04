
IRDataTypeNodeType IRQualifiersNode::get_node_type() const { return IRDataTypeNodeType::QUALIFIER; }

IRQualifiersNode::IRQualifiersNode(const TypeRef& e, uint8_t mask) : m_element{e}, m_bit_mask{ mask } {
	set_size(e.get_size());
}
