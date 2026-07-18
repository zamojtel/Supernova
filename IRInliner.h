
class IRInliner {
public:
	friend class IRBasicBlock;
	size_t m_inlined_functions = 0;
	IRInliner();
	void expand_function_call(IRTriple* function_call);
private:
	struct InlineContext;
	IROperand get_remapped_operand(const IROperand& op, InlineContext& ctx);
};