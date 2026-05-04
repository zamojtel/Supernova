
IRCoder::IRCoder(IRProgram* ir_p) : m_checker{ ir_p->get_ir_checker()} {}

IRTriple* IRCoder::add_triple(size_t line_number, IROperation operation) {
	return add_triple(line_number, operation, std::vector<IROperand>{});
}

IRTriple* IRCoder::add_triple(size_t line_number, IROperation operation, const IROperand& op1) {
	return add_triple(line_number, operation, std::vector<IROperand>{ op1 });
}

IRTriple* IRCoder::add_triple(size_t line_number, IROperation operation, const IROperand& op1, const IROperand& op2) {
	return add_triple(line_number, operation, {op1,op2});
}

IRTriple* IRCoder::add_triple(size_t line_number, IROperation operation, const IROperand& op1, const IROperand& op2, const IROperand& op3) {
	return add_triple(line_number, operation, {op1,op2,op3});
}

IRTriple* IRCoder::add_triple(size_t line_number, IROperation operation, const std::vector<IROperand>& operands) {
	IRFunction* current_fn = m_current_basic_blk->get_function();
	IRTriple* triple = new IRTriple{ line_number,current_fn->get_triple_count(),m_current_basic_blk->m_triples.size(),operation,operands };

	insert_triple(triple);
	return triple;
}

void IRCoder::set_basic_block(IRBasicBlock* blk) {
	m_current_basic_blk = blk;
}

void IRCoder::insert_triple(IRTriple* triple) {
	m_checker->check_triple(triple);
	m_current_basic_blk->m_current_function->m_triple_count++;
	m_current_basic_blk->m_triples.push_back(triple);
}

IRBasicBlock* IRCoder::get_basic_block() const {
	return m_current_basic_blk;
}