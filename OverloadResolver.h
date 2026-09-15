
class OverloadResolver {
private:
	IRProgram* m_ir_program = nullptr;
public:
	OverloadResolver(IRProgram* program);
	//IRFunction* run(size_t line_number, const std::string& fn_name, const std::vector<IROperand>& arguments);
	OverloadMatch run(size_t line_number, const std::string& fn_name, const std::vector<IROperand>& arguments);
	bool is_better(const IRFunction* fn_1, const IRFunction* fn_2,const std::vector<IROperand>& arguments);
	std::vector<IRFunction*> find_matching_functions(size_t line_number, const std::string& fn_name, const std::vector<IROperand>& arguments);
};