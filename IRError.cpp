

IRError::IRError(size_t l_n, const std::string& msg) :m_line_number{ l_n }, m_message{ msg } {}
const std::string& IRError::get_message() const { return m_message; }
size_t IRError::get_line_number() const { return m_line_number; }