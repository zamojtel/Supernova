
IRDataTypeNode::IRDataTypeNode() :m_reference_count{ 0 } {}

void IRDataTypeNode::set_size(size_t size_in_bytes) {
	m_size = size_in_bytes;
}

std::optional<size_t> IRDataTypeNode::get_size(){
	if (m_size.has_value())
		return *m_size;
	else {
		try {
			IRDataTypeNodeType type = get_node_type();

			size_t size = calculate_size();
			set_size(size);
		}
		catch (std::runtime_error& e) {
			throw e;
		}
	}
}

size_t IRDataTypeNode::calculate_size() {
	throw std::runtime_error("can't calculate size for ");
}

bool IRDataTypeNode::has_size() const {
	return m_size.has_value();
}