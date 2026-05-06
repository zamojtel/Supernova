
IRTriple::IRTriple(size_t l_n, size_t g_i, size_t i, IROperation operation, const IROperand& op1, const IROperand& op2, const IROperand& op3) :m_line_number{ l_n }, m_global_index{ g_i }, m_index{ i }, m_operation{ operation }, m_operands{op1,op2,op3} {
}

IRTriple::IRTriple(size_t l_n, size_t g_i, size_t i, IROperation operation, const IROperand& op1, const IROperand& op2) :m_line_number{ l_n }, m_global_index{ g_i }, m_index{ i }, m_operation{ operation }, m_operands{op1,op2} {
}

IRTriple::IRTriple(size_t l_n, size_t g_i, size_t i, IROperation operation, const IROperand& op1) :m_line_number{ l_n }, m_global_index{ g_i }, m_index{ i }, m_operation{ operation }, m_operands{op1} {
}

IRTriple::IRTriple(size_t l_n, size_t g_i, size_t i, IROperation operation, const std::vector<IROperand>& operands) :m_line_number{ l_n }, m_global_index{ g_i }, m_index{ i }, m_operation{ operation }, m_operands{operands} {
	
}

size_t IRTriple::get_local_index() { return m_index; }

size_t IRTriple::get_global_index() { return m_global_index; };

const TypeRef& IRTriple::get_data_type() const { return m_data_type; }

IROperation IRTriple::get_ir_operation() const { return m_operation; }

std::vector<IROperand> IRTriple::get_function_call_arguments() const { 
	std::vector<IROperand> fn_call_args;
	for (size_t i = 1; i < m_operands.size();i++) {
		fn_call_args.push_back(m_operands[i]);
	}

	return fn_call_args;
}

size_t IRTriple::get_local_mem_offset() const {
	return m_local_mem_offset;
}