
class OverloadResolver {
private:
	IRProgram* m_ir_program = nullptr;
public:
	OverloadResolver(IRProgram* program);
	OverloadMatch run(size_t line_number, const std::string& fn_name, const std::vector<IROperand>& arguments);
	bool is_better(const IRBaseFunction* fn_1, const IRBaseFunction* fn_2,const std::vector<IROperand>& arguments);
	std::vector<IRBaseFunction*> find_matching_functions(size_t line_number, const std::string& fn_name, const std::vector<IROperand>& arguments);
};