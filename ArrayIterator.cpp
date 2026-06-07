
ArrayIterator::ArrayIterator(uint8_t* start, TypeRef type) : m_start{ start }, m_current_address{start}, m_current_index { 0 } {
	m_element_type = type.remove_reference().remove_all_extents();
	m_element_size = m_element_type.get_size();
	if (type.is_array()) {
		//m_element_size = m_element_type.get_size();
		IRArrayNode *arr_node = static_cast<IRArrayNode*>(type.get_data_type_node());
		m_count = arr_node->m_count;
	}
	else {
		// it's scalar value
		//m_element_size = type.get_size();
		m_count = 1;
	}
}

void ArrayIterator::next() {
	m_current_index=(m_current_index+1)%m_count;
	uint8_t	* target_address = m_start + m_current_index * m_element_size;
	m_current_address = target_address;
}

size_t ArrayIterator::get_count() {
	return m_count;
}

uint8_t* ArrayIterator::operator*() const {
	return m_current_address;
}

TypeRef ArrayIterator::get_element_type() {
	return m_element_type;
}