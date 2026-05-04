
IRArrayNode::IRArrayNode(const TypeRef& ref, size_t s) : m_element_type{ ref }, m_size{s} {
	set_size(ref.get_size()*s);
}

IRDataTypeNodeType IRArrayNode::get_node_type() const { return IRDataTypeNodeType::ARRAY; }

size_t IRArrayNode::calculate_size() {
	// DOKONCZYC #TUTAJ
	try {
		size_t element_size = m_element_type.get_size();
		return element_size * m_size;
	}
	catch (std::runtime_error e) {
		throw e;
	}

}