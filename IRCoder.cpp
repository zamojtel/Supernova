
IRCoder::IRCoder(IRProgram* ir_p) : m_checker{ ir_p->get_ir_checker() }, m_position{0} {}

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
	IRTriple* triple = new IRTriple{m_current_basic_blk,line_number,current_fn->get_triple_count(),m_position};

	triple->set_data(operation,operands);

	insert_triple(triple);
	return triple;
}

void IRCoder::set_basic_block(IRBasicBlock* blk) {
	m_position = blk->get_number_of_triples();
	m_current_basic_blk = blk;
}

void IRCoder::set_position_after(IRTriple* triple) {
	m_current_basic_blk = triple->m_basic_blk;
	m_position = triple->m_index + 1;
}

void IRCoder::insert_triple(IRTriple* triple) {
	m_checker->check_triple(triple);
	m_current_basic_blk->m_current_function->m_triple_count++;
	m_current_basic_blk->m_triples.insert(m_current_basic_blk->m_triples.begin()+m_position,triple);
	int index = triple->get_local_index()+1;

	for (size_t j = index; j < m_current_basic_blk->m_triples.size();j++)
		m_current_basic_blk->m_triples[j]->m_index = j;
	m_position++;
}

IRBasicBlock* IRCoder::get_basic_block() const {
	return m_current_basic_blk;
}