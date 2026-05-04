
class IRCheckerListener {
public:
	virtual void add_error(size_t line_number, const std::string& error_msg) {}
};