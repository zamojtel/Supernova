
struct IRInliner::InlineContext {
	IRTriple* m_call = nullptr;

	IRFunction* m_caller = nullptr;
	IRFunction* m_callee = nullptr;
	IRBasicBlock* m_caller_blk = nullptr;
	IRBasicBlock* m_continuation_blk = nullptr;
	IRVariable* m_function_result = nullptr;

	//std::unordered_map<IRVariable*, IRVariable*> m_variables;
	//std::unordered_map<IRTriple*, IRTriple*> m_triples;
	//std::unordered_map<IRBasicBlock*, IRBasicBlock*> m_basic_blks;
	std::map<IRVariable*, IRVariable*> m_variables;
	std::map<IRTriple*, IRTriple*> m_triples;
	std::map<IRBasicBlock*, IRBasicBlock*> m_basic_blks;
};

IROperand IRInliner::get_remapped_operand(const IROperand& op, InlineContext& ctx) {
	switch (op.m_operand_type)
	{
	case IROperandType::BASIC_BLOCK: {
		return ctx.m_basic_blks.at(op.get_basic_block());
	}
	case IROperandType::VARIABLE: {
		if (!op.get_variable()->is_global()) {
			return ctx.m_variables.at(op.get_variable());
		}
	}
	case IROperandType::TRIPLE: {
		return ctx.m_triples.at(op.get_triple());
	}
							  // add more if neccessary 
	default:
		break;
	}
}
IRInliner::IRInliner() {}

void IRInliner::expand_function_call(IRTriple* function_call) {
	// Sprawdzic czy parametery s¹ modyfikowane czy nie
	// Nie zawsze trzeba tworzyc FunctionResult

	InlineContext ctx;
	ctx.m_caller = function_call->m_basic_blk->get_function();
	ctx.m_callee = function_call->m_operands[0].get_function();
	ctx.m_call = function_call;
	ctx.m_caller_blk = function_call->m_basic_blk;
	IRVariable* function_result = ctx.m_caller->add_variable("#function_result", ctx.m_callee->get_return_type());

	IRBasicBlock* continuation_blk = ctx.m_caller->add_basic_block("continuation");

	ctx.m_continuation_blk = continuation_blk;
	IRCoder coder{ ctx.m_caller->get_ir_prgram() };
	coder.set_basic_block(ctx.m_caller_blk);
	coder.set_position_after(ctx.m_call);
	/*coder.add_triple(ctx.m_call->m_line_number,IROperation::JMP,);*/
	auto parameters = ctx.m_callee->get_parameters();

	// zmienic zmienne na operandy zeby bylo complexowo 
	for (int i = 0; ctx.m_callee->get_parameters().size(); i++) {
		if (!parameters[i]->get_data_type().is_reference()) {
			std::string new_parameter_name = std::format("#inline{}.{}", m_inlined_functions, parameters[i]->get_variable_name());
			IRVariable* new_variable = ctx.m_caller->add_variable(new_parameter_name, parameters[i]->get_data_type());
			coder.add_triple(ctx.m_call->m_line_number, IROperation::INIT_ASSIGN, new_variable, ctx.m_call->m_operands[i + 1]);
			ctx.m_variables[parameters[i]] = new_variable;
		}
		else {
			ctx.m_variables[ctx.m_call->m_operands[i + 1].get_variable()] = ctx.m_call->m_operands[i + 1].get_variable();
		}
	}

	// kopiujemy funkcje 
	auto blks = ctx.m_callee->get_basic_blocks();
	// petla kopiuj¹ca basic bloki
	for (size_t i = 0; i < blks.size(); i++) {
		auto block_to_be_coppied = blks[i];

		IRBasicBlock* current_blk = ctx.m_caller->add_basic_block();
		auto all_triples_block_to_be_coppied = block_to_be_coppied->get_all_triples();
		std::string new_blk_name = std::format("#inline.{}", i);
		IRBasicBlock* new_basic_blk = ctx.m_caller->add_basic_block(new_blk_name);
		ctx.m_basic_blks[block_to_be_coppied] = new_basic_blk;
	}
	coder.add_triple(ctx.m_call->m_line_number, IROperation::JMP, get_remapped_operand(blks[0], ctx));

	for (size_t i = 0; i < blks.size(); i++) {
		auto block_to_be_coppied = blks[i];
		auto new_basic_blk = ctx.m_basic_blks.at(block_to_be_coppied);
		auto& all_triples_blk_to_be_coppied = block_to_be_coppied->get_all_triples();
		coder.set_basic_block(new_basic_blk);

		for (size_t i = 0; i < all_triples_blk_to_be_coppied.size(); i++) {
			auto triple_to_be_coppied = all_triples_blk_to_be_coppied[i];
			std::vector<IROperand> new_operands;
			for (const IROperand& op : triple_to_be_coppied->m_operands) {
				new_operands.push_back(get_remapped_operand(op, ctx));
			}

			IRTriple* new_triple = coder.add_triple(triple_to_be_coppied->m_line_number, triple_to_be_coppied->get_ir_operation(), new_operands);
			ctx.m_triples[triple_to_be_coppied] = new_triple;
		}
	}

	auto all_blk_triples = ctx.m_call->m_basic_blk->get_all_triples();
	int staring_index = ctx.m_call->get_local_index();
	// there's no need for that

	size_t current_index = 0;

	for (int i = staring_index + 1; i < all_blk_triples.size(); i++) {
		all_blk_triples[i]->m_index = current_index;
		current_index++;
		all_blk_triples[i]->m_basic_blk = ctx.m_continuation_blk;
		ctx.m_continuation_blk->m_triples.push_back(all_blk_triples[i]);
	}

}