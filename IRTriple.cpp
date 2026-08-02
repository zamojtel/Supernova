
IRTriple::IRTriple(IRBasicBlock* block, size_t line_number, size_t global_index, size_t local_index) : m_basic_blk{block}, m_line_number { line_number }, m_global_index{ global_index }, m_index{ local_index } {}

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

size_t IRTriple::get_line() const { return m_line_number; }

size_t IRTriple::get_local_mem_offset() const {
	return m_local_mem_offset;
}

void IRTriple::set_data(IROperation operation, const std::vector<IROperand>& operands) {
	std::vector<IROperand> new_operands = operands;
	for (size_t i = 0; i < m_operands.size();i++)
		set_operand(i,IROperand{});

	m_operands.resize(new_operands.size());
	m_operation = operation;

	for (size_t i = 0; i < new_operands.size();i++)
		set_operand(i,new_operands[i]);
}


void IRTriple::clear() {
	for (int i = 0; i < m_operands.size(); i++)
		set_operand(i, IROperand{});
	m_operation = IROperation::NO_OPERATION;
	m_operands.clear();
}

IROperandType IRTriple::get_operand_type() const { return IROperandType::TRIPLE; }

IROperand IRTriple::get_operand() { return this; }

void IRTriple::set_operand(size_t index,IROperand op) {
	if (index >= m_operands.size())
		throw std::runtime_error("index out of range");

	if (m_operands[index].m_operand_type==IROperandType::BASIC_BLOCK)
		m_basic_blk->remove_successor(m_operands[index].get_basic_block());

	if (op.m_operand_type==IROperandType::BASIC_BLOCK) {
		IRBasicBlock* blk = op.get_basic_block();
		// it adds connections both ways
		m_basic_blk->add_successor(blk);
	}

	IRUsedObject* old_obj = m_operands[index].get_used_object();
	if (old_obj)
		old_obj->remove_use_site(this,index);

	m_operands[index] = op;

	IRUsedObject* obj = op.get_used_object();

	if (obj)
		obj->add_use_site(this,index);
}
