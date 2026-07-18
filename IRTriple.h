
class IROperand;

class IRTriple {
private:
public:
	IRBasicBlock* m_basic_blk;
	TypeRef m_data_type;
	size_t m_line_number;
	size_t m_global_index;
	size_t m_index;
	std::vector<IROperand> m_operands;
	IROperation m_operation;
	// arguments for function call
	size_t m_local_mem_offset;

	IRTriple(IRBasicBlock* blk, size_t l_n,size_t g_i, size_t i,IROperation o,const IROperand& op1);
	IRTriple(IRBasicBlock* blk, size_t l_n,size_t g_i, size_t i,IROperation o,const IROperand& op1, const IROperand& op2);
	IRTriple(IRBasicBlock* blk, size_t l_n,size_t g_i, size_t i,IROperation o,const IROperand& op1, const IROperand& op2,const IROperand& op3);
	IRTriple(IRBasicBlock* blk, size_t l_n, size_t g_i, size_t i, IROperation operation, const std::vector<IROperand>& operands);

	size_t get_local_index();
	size_t get_global_index();
	const TypeRef& get_data_type() const;
	IROperation get_ir_operation() const;
	std::vector<IROperand> get_function_call_arguments() const;
	size_t get_local_mem_offset() const;

};
