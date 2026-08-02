
class IRInliner {
public:
	size_t m_inline_instance_counter;
	size_t m_inline_depth;
	IRInliner();
	IRInliner(size_t inline_depth);
	std::map<IRFunction*, int> m_active_depth;
	void expand_functions(IRFunction* main);
	void expand_function_call(IRTriple* function_call);
	size_t check_number_of_returns(IRFunction* fn);
private:
	struct InlineContext;
	IROperand get_remapped_operand(const IROperand& op, InlineContext& ctx);
};