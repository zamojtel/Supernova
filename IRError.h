
class IRError {
private:
	size_t m_line_number;
	std::string m_message;
public:
	IRError(size_t l_n, const std::string& msg);
	const std::string& get_message() const;
	size_t get_line_number() const;
};