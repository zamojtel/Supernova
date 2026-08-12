

UselessControlFlowEliminator::UselessControlFlowEliminator(IRFunction* fn) : m_current_fn{fn} {}

void UselessControlFlowEliminator::run() {
	bool change = true;
	//m_current_fn
	while (change) {
		change = false;
		bool res1 = fold_redundant_branch(m_current_fn);
		bool res2 = find_and_remove_blocks_with_one_jmp(m_current_fn);
		bool res3 = combine_blocks(m_current_fn);
		change = res1 || res2 || res3;
	}
}

bool UselessControlFlowEliminator::fold_redundant_branch(IRFunction* fn) {
	auto& blks = fn->get_basic_blocks();
	bool change = false;

	for (IRBasicBlock* blk : blks) {
		const std::vector<IRTriple*>& all_triples = blk->get_all_triples();
		if (all_triples.size() > 0 && all_triples.back()->get_ir_operation() == IROperation::JC) {
			IRTriple* triple = all_triples.back();
			// jc condition blk1 blk2
			if (triple->m_operands[1].get_basic_block() == triple->m_operands[2].get_basic_block()) {
				triple->set_data(IROperation::JMP, { triple->m_operands[1] });
				change = true;
			}
		}
	}

	return change;
}

bool UselessControlFlowEliminator::find_and_remove_blocks_with_one_jmp(IRFunction* fn) {

	auto& blks = fn->get_basic_blocks();
	std::vector<IRBasicBlock*> r_blks;
	bool change = false;
	for (IRBasicBlock* blk : blks) {
		const std::vector<IRTriple*>& all_triples = blk->get_all_triples();
		if (all_triples.size() == 1 && all_triples.back()->get_ir_operation() == IROperation::JMP) {
			blk->replace_all_usages(all_triples.back()->m_operands[0].get_basic_block());
			r_blks.push_back(blk);
			change = true;
		}
	}

	for (size_t i = 0; i < r_blks.size(); i++)
		fn->remove_blk(r_blks[i]);

	fn->reindex_triples();
	return change;
}

bool UselessControlFlowEliminator::combine_blocks(IRFunction* fn) {
	auto& blks = fn->get_basic_blocks();
	bool change = false;

	for (IRBasicBlock* blk : blks) {
		const std::vector<IRTriple*>& all_triples = blk->get_all_triples();
		const auto& successors = blk->get_successors();
		for (auto& successor : successors) {
			const auto& predecessors = successor->get_predecessors();
			if (predecessors.size() == 1) {
				blk->merge_blocks(successor);
				change = true;
			}
		}
	}

	return change;
}
