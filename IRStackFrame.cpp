
IRStackFrame::IRStackFrame(IRBasicBlock* blk, IRTriple* r_t, size_t triple_count, size_t l_var_count) 
	: m_return_blk{ blk }, m_return_triple{ r_t }, m_triple_values(triple_count), m_local_variables(l_var_count)
{}
