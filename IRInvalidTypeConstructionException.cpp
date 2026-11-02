
IRInvalidTypeConstructionException::IRInvalidTypeConstructionException() {}

IRInvalidTypeConstructionException::IRInvalidTypeConstructionException(const std::string& msg) : m_msg{msg} {}

std::string IRInvalidTypeConstructionException::get_message() {
	return m_msg;
}