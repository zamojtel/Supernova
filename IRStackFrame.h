

class IRStackFrame {
private:
	friend class Interpreter;
	//std::vector<IROperand> m_arguments;
	std::vector<ConstantValue> m_triple_values;
	std::vector<ConstantValue> m_local_variables;
	std::vector<uint8_t> m_meomory_stack;

	IRBasicBlock* m_return_blk = nullptr;
	IRTriple* m_return_triple = nullptr; // it's returning address after a fucntion is called
public:
	//IRStackFrame(IRBasicBlock * blk,IRTriple *r_t,size_t triple_count,size_t l_var_count);
	IRStackFrame(IRBasicBlock* blk, IRTriple* r_t, size_t triple_count, size_t l_var_count, size_t total_size_in_bytes);
};