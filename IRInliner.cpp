
struct IRInliner::InlineContext {
	IRTriple* m_call = nullptr;

	IRFunction* m_caller = nullptr;
	IRFunction* m_callee = nullptr;
	IRBasicBlock* m_caller_blk = nullptr;
	IRBasicBlock* m_continuation_blk = nullptr;
	IRVariable* m_function_result = nullptr;
	// this handles the case when there's only one return in a function
	IROperand m_function_result_one_return;
	std::map<IROperand,IROperand> m_operands;
};

IROperand IRInliner::get_remapped_operand(const IROperand& op, InlineContext& ctx) {
	if (ctx.m_operands.count(op)>0)
		return ctx.m_operands.at(op);
	else if (
		op.m_operand_type == IROperandType::CONSTANT  ||
		op.m_operand_type == IROperandType::FUNCTION  ||
		op.m_operand_type == IROperandType::DATA_TYPE ||
		op.m_operand_type == IROperandType::MEMBER
		) {
		return op;
	}
	else if (op.m_operand_type == IROperandType::VARIABLE && op.get_variable()->is_global()) {
		return op;
	}
	else {
		throw std::runtime_error("unknown operand");
	}
}

IRInliner::IRInliner(size_t inline_depth) : m_inline_depth{ inline_depth }, m_inline_instance_counter{0} {}

IRInliner::IRInliner() : m_inline_depth{ 2 }, m_inline_instance_counter{0} {}

void IRInliner::expand_functions(IRFunction * main) {
	m_active_depth.clear();
	std::vector<IRBasicBlock*> blks = main->get_basic_blocks();

	for (IRBasicBlock* blk : blks) {
		std::vector<IRTriple*> all_triples = blk->get_all_triples();
		for (IRTriple* t : all_triples) {
			if (t->m_operation == IROperation::FUNCTION_CALL)
				expand_function_call(t);
		}
	}
}

size_t IRInliner::check_number_of_returns(IRFunction* fn) {
	int counter = 0;
	for (auto &blk : fn->get_basic_blocks()) {
		auto& triples = blk->get_all_triples();
		for (IRTriple *triple : triples) {
			if (triple->m_operation==IROperation::RETURN)
				counter++;
		}
	}
	return counter;
}

void IRInliner::expand_function_call(IRTriple* function_call) {
	IRFunction* callee = function_call->m_operands[0].get_function();
	IRFunction* caller = function_call->m_basic_blk->get_function();

	if (caller == callee)
		return;

	if (!callee->is_inline())
		return;

	int& active_depth = m_active_depth[callee];
	if (active_depth>=m_inline_depth)
		return;

	const size_t number_of_returns = check_number_of_returns(callee);
	const bool returns_void = callee->get_return_type().is_void();

	if (number_of_returns == 0)
		throw std::runtime_error("cannot inline function without explicit return");

	if (returns_void && function_call->is_used())
		throw std::runtime_error("void function call cannot have users");


	const size_t inline_id = m_inline_instance_counter++;
	InlineContext ctx;
	ctx.m_caller = caller;
	ctx.m_callee = callee;
	const auto parameters = callee->get_parameters();
	const auto variables = callee->get_variables();

	active_depth++;
	ctx.m_call = function_call;
	ctx.m_caller_blk = function_call->m_basic_blk;

	if (!returns_void && number_of_returns > 1) {
		std::string fn_result_name = std::format("#inline.{}.result", inline_id);
		ctx.m_function_result = ctx.m_caller->add_variable(fn_result_name, ctx.m_callee->get_return_type());
	}

	std::string continuation_blk_name = std::format("#inline.{}.continuation",inline_id);
	ctx.m_continuation_blk = ctx.m_caller->add_basic_block(continuation_blk_name);

	auto& all_blk_triples = ctx.m_call->m_basic_blk->m_triples;
	int starting_index = ctx.m_call->get_local_index();

	for (size_t i = starting_index+1; i < all_blk_triples.size();) {
		IRTriple* moved_triple = all_blk_triples[i];

		for (const IROperand& operand : moved_triple->m_operands) {
			if (operand.m_operand_type == IROperandType::BASIC_BLOCK)
				ctx.m_caller_blk->remove_successor(operand.get_basic_block());
		}

		all_blk_triples.erase(
			all_blk_triples.begin() + i
		);

		moved_triple->m_basic_blk = ctx.m_continuation_blk;

		ctx.m_continuation_blk->m_triples.push_back(moved_triple);

		for (const IROperand& operand : moved_triple->m_operands) {
			if (operand.m_operand_type == IROperandType::BASIC_BLOCK) {
				ctx.m_continuation_blk->add_successor(
					operand.get_basic_block()
				);
			}
		}
	}

	IRCoder coder{ ctx.m_caller->get_ir_prgram() };
	coder.set_position_after(ctx.m_call);

	int counter = 0;

	for (size_t i = 0; i < parameters.size(); i++) {
		if (!parameters[i]->get_data_type().is_reference()) {
			std::string new_parameter_name = std::format("#inline.{}.{}",inline_id,counter++);
			IRVariable* new_variable = ctx.m_caller->add_variable(new_parameter_name, parameters[i]->get_data_type());
			coder.add_triple(ctx.m_call->m_line_number, IROperation::INIT_ASSIGN, new_variable, ctx.m_call->m_operands[i + 1]);
			ctx.m_operands[parameters[i]] = new_variable;
		}
		else
			ctx.m_operands[parameters[i]] = ctx.m_call->m_operands[i + 1];
	}

	for (size_t j = parameters.size(); j < variables.size();j++) {
		IRVariable* var = variables[j];
		if (var->is_used()) {
			std::string new_variable_name = std::format("#inline.{}.{}",inline_id,counter++);
			IRVariable* new_variable = ctx.m_caller->add_variable(new_variable_name,var->get_data_type());
			ctx.m_operands[var] = new_variable;
		}
	}

	// for copy functions
	auto blks = ctx.m_callee->get_basic_blocks();
	// loop that copies basic blocks
	for (size_t i = 0; i < blks.size(); i++) {
		auto block_to_be_copied = blks[i];

		std::string new_blk_name = std::format("#inline.{}.{}",inline_id,i);
		IRBasicBlock* new_basic_blk = ctx.m_caller->add_basic_block(new_blk_name);
		ctx.m_operands[block_to_be_copied] = new_basic_blk;
	}

	coder.add_triple(ctx.m_call->m_line_number, IROperation::JMP, get_remapped_operand(blks[0], ctx));

	std::vector<IRTriple*> new_function_calls;
	for (size_t i = 0; i < blks.size(); i++) {

		auto block_to_be_copied = blks[i];
		IRBasicBlock* new_basic_blk = ctx.m_operands.at(block_to_be_copied).get_basic_block();
		auto& all_triples_blk_to_be_copied = block_to_be_copied->get_all_triples();
		coder.set_basic_block(new_basic_blk);

		for (size_t i = 0; i < all_triples_blk_to_be_copied.size(); i++) {
			auto triple_to_be_copied = all_triples_blk_to_be_copied[i];
			std::vector<IROperand> new_operands;

			for (const IROperand& op : triple_to_be_copied->m_operands) {
				new_operands.push_back(get_remapped_operand(op, ctx));
			}

			if (triple_to_be_copied->get_ir_operation() == IROperation::RETURN) {
				if (!ctx.m_callee->get_return_type().is_void() && number_of_returns > 1)
					coder.add_triple(triple_to_be_copied->m_line_number,IROperation::INIT_ASSIGN,ctx.m_function_result,get_remapped_operand(triple_to_be_copied->m_operands[0],ctx));
				else if (!ctx.m_callee->get_return_type().is_void() && number_of_returns == 1)
					ctx.m_function_result_one_return = get_remapped_operand(triple_to_be_copied->m_operands[0], ctx);

				coder.add_triple(triple_to_be_copied->m_line_number,IROperation::JMP,ctx.m_continuation_blk);
				continue;
			}

			IRTriple* new_triple = coder.add_triple(triple_to_be_copied->m_line_number, triple_to_be_copied->get_ir_operation(), new_operands);

			// collecting future calls
			if (new_triple->get_ir_operation() == IROperation::FUNCTION_CALL)
				new_function_calls.push_back(new_triple);

			ctx.m_operands[triple_to_be_copied] = new_triple;
		}
	}

	auto call_basic_blk = ctx.m_call->m_basic_blk;

	if (!returns_void) {
		if (number_of_returns > 1)
			ctx.m_call->replace_all_usages(ctx.m_function_result);
		else
			ctx.m_call->replace_all_usages(ctx.m_function_result_one_return.get_used_object());
	}

	call_basic_blk->remove_triple(ctx.m_call);

	// expanding function calls within the current function call
	for (IRTriple* call : new_function_calls) {
		expand_function_call(call);
	}

	active_depth--;
	ctx.m_caller->reindex_triples();

	IRProgram* ir_program = ctx.m_caller->get_ir_prgram();
	ir_program->calculate_size_required_for_fn(ctx.m_caller);
}