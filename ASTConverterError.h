
class ASTConverterError {
private:
	size_t m_line_number;
	std::string m_error_msg;
public:
	ASTConverterError(size_t l_n, const std::string& msg) :m_line_number{l_n},m_error_msg { msg } {}
	const std::string get_msg() const { return m_error_msg; }
	const size_t get_line_number() const { return m_line_number; }
};