
class IRErrorCollector : public IRCheckerListener {
private:
	std::vector<IRError*> m_errors;
public:
	void add_error(size_t line_number, const std::string& error_msg);
	const std::vector<IRError*>& get_errors() const;
};