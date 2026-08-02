
FunctionReturnChecker::FunctionReturnChecker() {}

std::vector<IRBasicBlock*> FunctionReturnChecker::check_all_paths(IRFunction* fn) {
	TypeRef return_type = fn->get_return_type();
	std::vector<IRBasicBlock*> blks_without_terminator_stmts;
	IRProgram* p = fn->get_ir_prgram();
	auto dtm = p->get_dtm_manager();
	IRCoder coder(p);

	for (IRBasicBlock *blk : fn->get_basic_blocks()) {
		auto& triples = blk->get_all_triples();
		bool is_return = false;

		if (triples.size() != 0) {
			IROperation operation = triples.back()->get_ir_operation();

			if (operation == IROperation::JMP || operation == IROperation::JC || operation == IROperation::RETURN)
				continue;
		}

		blks_without_terminator_stmts.push_back(blk);
	}

	return blks_without_terminator_stmts;
}