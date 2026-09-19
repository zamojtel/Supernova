
class IRError {
private:
	size_t m_line_number;
	ErrorType m_type;
	std::string m_message;
public:
	IRError(size_t l_n, ErrorType type, const std::string& msg);
	const std::string& get_message() const;
	size_t get_line_number() const;
	ErrorType get_error_type() const;
};