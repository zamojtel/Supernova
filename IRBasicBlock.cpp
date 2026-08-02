

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

void IRBasicBlock::remove_triple(IRTriple* triple) {
	if (triple == nullptr)
		throw std::runtime_error("triple is nullptr");

	size_t removed_index = triple->get_local_index();

	if (removed_index >= m_triples.size() || m_triples[removed_index] != triple)
		throw std::runtime_error("triple does not belong to this block");

	if (triple->is_used())
		throw std::runtime_error("cannot remove a used triple");

	triple->clear();
	m_triples.erase(m_triples.begin() + triple->get_local_index());
	delete triple;

	m_current_function->reindex_triples();
}

void IRBasicBlock::add_successor(IRBasicBlock* blk) {
	// check later if it can be simplified
	if (m_successors.count(blk)>0 && blk->m_predecessors.count(this)>0) {
		m_successors.at(blk)++;
		blk->m_predecessors.at(this)++;
	}
	else {
		m_successors[blk] = 1;
		blk->m_predecessors[this] = 1;
	}
}

std::vector<IRBasicBlock*> IRBasicBlock::get_successors() const {
	std::vector<IRBasicBlock*> blks;
	for (const auto& [key, value] : m_successors) {
		blks.push_back(key);
	}

	return blks;
}

std::vector<IRBasicBlock*> IRBasicBlock::get_predecessors() const {
	std::vector<IRBasicBlock*> blks;
	for (const auto& [key, value] : m_predecessors)
		blks.push_back(key);

	return blks;
}

void IRBasicBlock::remove_successor(IRBasicBlock* blk) {
	if (m_successors.at(blk)>1 && blk->m_predecessors.at(this)>1) {
		m_successors.at(blk)--;
		blk->m_predecessors.at(this)--;
	}
	else {
		m_successors.erase(blk);
		blk->m_predecessors.erase(this);
	}
}

void IRBasicBlock::clear() {
	while(!m_triples.empty()) {
		IRTriple* triple = m_triples[m_triples.size() - 1];

		if (triple->is_used())
			throw std::runtime_error("cannot remove a used triple");

		triple->clear();
		m_triples.pop_back();
		delete triple;
	}
}


void IRBasicBlock::merge_blocks(IRBasicBlock* blk) {
	remove_triple(m_triples.back());
	auto& all_triples = blk->get_all_triples();

	for (IRTriple* triple : all_triples) {
		m_triples.push_back(triple);
	}

	blk->m_triples.clear();
	m_current_function->remove_blk(blk);

}

IROperandType IRBasicBlock::get_operand_type() const { return IROperandType::BASIC_BLOCK; }

IROperand IRBasicBlock::get_operand() { return this; }