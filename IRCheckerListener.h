
class IRCheckerListener {
public:
	virtual void add_error(size_t line_number,ErrorType type, const std::string& error_msg) {}
};