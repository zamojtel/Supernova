
class IRInterpreterListener {
public:
	virtual void assertion_failed(size_t line_number, const std::string& error_msg) {}
	virtual void assertion_succeded() {}
	//virtual void print_called(const ConstantValue& v) {};
	virtual void print_called(const std::string& v) {};
	virtual void function_call_start(const std::vector<ConstantValue>& args, IRFunction* fn) {};
	virtual void function_call_end(IRFunction* fn,const ConstantValue& r_value) {};
	std::vector<bool>& get_results();
	size_t get_asserts_passed() const;
	size_t get_asserts_failed() const;
	// and more ...
	std::vector<std::string> get_messages();
};