
IRError::IRError(size_t l_n,ErrorType type, const std::string& msg) : m_line_number{ l_n }, m_type{type}, m_message{ msg } {}

const std::string& IRError::get_message() const { return m_message; }

size_t IRError::get_line_number() const { return m_line_number; }

ErrorType IRError::get_error_type() const { return m_type; }
