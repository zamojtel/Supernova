
IRVariable::IRVariable(const std::string& i,const TypeRef& t, size_t in) : m_identifier{ i }, m_data_type{ t }, m_index{ in } {}

std::string IRVariable::get_variable_name() const { return m_identifier; }

const TypeRef& IRVariable::get_data_type() const { return m_data_type; }

size_t IRVariable::get_index() const { return m_index;  }