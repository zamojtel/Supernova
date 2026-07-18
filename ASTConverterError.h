
class ASTConverterError {
private:
	ErrorType m_error_type;
	size_t m_line_number;
	std::string m_error_msg;
public:
	ASTConverterError(ErrorType e_t, size_t l_n, const std::string& msg) : m_error_type{e_t}, m_line_number { l_n }, m_error_msg{ msg } {}
	ErrorType get_error_type() const { return m_error_type; }
	const std::string get_msg() const { return m_error_msg; }
	const size_t get_line_number() const { return m_line_number; }
};