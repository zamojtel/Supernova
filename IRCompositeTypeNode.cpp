
void IRCompositeTypeNode::add_field(const TypeRef &ref_type,const std::string &f_name) {
	m_field_list.push_back(new IRMember{ref_type,f_name});
}

IRCompositeTypeNode::IRCompositeTypeNode(const std::string& name) : m_name{ name }, m_is_finished{false} {}

std::string IRCompositeTypeNode::get_name() const {
	return m_name;
}

size_t IRCompositeTypeNode::calculate_size() {
	size_t total_size = 0;

	for (auto *element : m_field_list) {
		TypeRef ref = element->get_data_type();
		if(ref.has_size()) {
			size_t size = ref.get_size();
			total_size += size;
		}
		else
			throw std::runtime_error("field size is not set");
	}

	std::string msg = std::format("\n{} size {}",m_name,total_size);
	std::cout << msg << std::endl;

	return total_size;
}

void IRCompositeTypeNode::close() {
	m_is_finished = true;
	get_size();
}

IRMember* IRCompositeTypeNode::get_member(const std::string& field_name) const {
	for (size_t i = 0; i < m_field_list.size();i++) {
		if (m_field_list[i]->get_field_name() == field_name)
			return m_field_list[i];
	}

	return nullptr;
}