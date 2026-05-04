
//IRTriple* IRBasicBlock::add_triple(size_t line_number, IROperation operation, const IROperand& op1) {
//	IRTriple* triple = new IRTriple{line_number,m_ir_program->get_triple_count(),m_triples.size(),operation,op1};
//	m_ir_program->m_triple_count++;
//
//	//check triple with checker 
//	
//
//	//deduce_triple_data_type();
//	m_triples.push_back(triple);
//
//	return triple;
//}
//
//IRTriple* IRBasicBlock::add_triple(size_t line_number, IROperation operation, const IROperand& op1, const IROperand& op2) {
//	IRTriple* triple = new IRTriple{line_number,m_ir_program->get_triple_count(),m_triples.size(),operation,op1,op2};
//	m_ir_program->m_triple_count++;
//	m_triples.push_back(triple);
//
//	return triple;
//}
//
//IRTriple* IRBasicBlock::add_triple(size_t line_number, IROperation operation, const IROperand& op1, const IROperand& op2, const IROperand& op3) {
//	IRTriple* triple = new IRTriple{ line_number,m_ir_program->get_triple_count(),m_triples.size(),operation,op1,op2,op3 };
//	// deduce type 
//	
//	m_ir_program->m_triple_count++;
//	m_triples.push_back(triple);
//
//	return triple;
//}
//
//IRTriple* IRBasicBlock::add_triple(size_t line_number, IROperation operation,const std::vector<IROperand> &operands) {
//	IRTriple* triple = new IRTriple{line_number,m_ir_program->get_triple_count(),m_triples.size(),operation,operands};
//	m_ir_program->m_triple_count++;
//	m_triples.push_back(triple);
//
//	return triple;
//}

IRFunction* IRBasicBlock::get_function() const {
	return m_current_function;
}

const std::vector<IRTriple*>& IRBasicBlock::get_all_triples() {
	return m_triples;
}

size_t IRBasicBlock::get_number_of_triples() { return m_triples.size(); }

std::string IRBasicBlock::get_basic_blk_name() {
	return m_name;
}