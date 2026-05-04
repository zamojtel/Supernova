
class IRCoder {
private:
	IRChecker *m_checker;
	IRBasicBlock* m_current_basic_blk;
public:
	IRCoder(IRProgram* ir_p);
	IRTriple* add_triple(size_t line_number, IROperation operation);
	IRTriple* add_triple(size_t line_number, IROperation operation, const IROperand& op1);
	IRTriple* add_triple(size_t line_number, IROperation operation, const IROperand& op1, const IROperand& op2);
	IRTriple* add_triple(size_t line_number, IROperation operation, const IROperand& op1, const IROperand& op2, const IROperand& op3);
	IRTriple* add_triple(size_t line_number, IROperation operation, const std::vector<IROperand>& operands);
	IRBasicBlock* get_basic_block() const;
	void set_basic_block(IRBasicBlock* blk);
	void insert_triple(IRTriple* triple);
};

