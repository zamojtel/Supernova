
bool IROptimizer::is_triple_dead(IRTriple* triple) {
	if (triple->is_used())
		return false;

	switch (triple->get_ir_operation())
	{
	case IROperation::ADD:
	case IROperation::SUB:
	case IROperation::MUL:
	case IROperation::DIV:
	case IROperation::MOD:
	case IROperation::CAST:
	case IROperation::REINTERPRET_CAST:
	case IROperation::GT:
	case IROperation::GE:
	case IROperation::LT:
	case IROperation::LE:
	case IROperation::EQ:
	case IROperation::NEQ:
	case IROperation::COPY:
	case IROperation::UNARY_MINUS:
	case IROperation::BITWISE_AND:
	case IROperation::BITWISE_OR:
	case IROperation::BITWISE_XOR:
	case IROperation::BITWISE_NOT:
	case IROperation::LEFT_SHIFT:
	case IROperation::RIGHT_SHIFT:
	case IROperation::SELECT:
		return true;
	default:
		return false;
	}
}

bool IROptimizer::check_if_all_constants(size_t n,const IRTriple* triple) {
	for (size_t i = 0; i < n;i++) {
		if (!triple->m_operands[i].is_constant()) {
			return false;
		}
	}

	return true;
}

void IROptimizer::run(IRFunction* fn) {
	for (IRBasicBlock* blk : fn->get_basic_blocks()) {
		for (auto& triple : blk->get_all_triples()) {
			switch (triple->m_operation)
			{
			case IROperation::ADD:
			case IROperation::SUB:
			case IROperation::DIV:
			case IROperation::MUL:
			case IROperation::MOD:
			case IROperation::LEFT_SHIFT:
			case IROperation::RIGHT_SHIFT:
			case IROperation::BITWISE_AND:
			case IROperation::BITWISE_OR:
			case IROperation::BITWISE_XOR:
			case IROperation::BITWISE_NOT:
			case IROperation::UNARY_MINUS:
			case IROperation::LT:
			case IROperation::LE:
			case IROperation::GT:
			case IROperation::GE:
			case IROperation::EQ:
			case IROperation::NEQ: {
				std::vector<TypeRef> operand_types;
				std::vector<uint8_t*> operands;
				size_t n = triple->m_operands.size();

				operand_types.reserve(n);
				operands.reserve(n);
				if (check_if_all_constants(n,triple)) {
					for (const IROperand& operand : triple->m_operands) {
						operand_types.push_back(operand.get_data_type());
						operands.push_back(operand.get_constant()->get_address());
					}

					TypeRef result_type = triple->get_data_type();
					uint64_t result{0};

					m_operation_executor.execute_operation(triple->get_ir_operation(), operand_types, operands, result_type, reinterpret_cast<uint8_t*>(&result));
					ConstantValue result_value{ result_type.get_ir_basic_type(),&result };
					IRConstant* cv = fn->add_constant(result_value);
					triple->replace_all_usages(cv);
				}

				break;
			}
			case IROperation::JC: {
				if (triple->m_operands[0].is_constant()) {
					ConstantValue cv = triple->m_operands[0].get_constant()->get_value();
					bool condition = cv.get_value<bool>();
					IRBasicBlock* blk_1 = triple->m_operands[1].get_basic_block();
					IRBasicBlock* blk_2 = triple->m_operands[2].get_basic_block();
					if (condition)
						triple->set_data(IROperation::JMP, {blk_1});
					else
						triple->set_data(IROperation::JMP, {blk_2});
				}

				break;
			}
			default:
				break;
			}

		}

	}

	//IRPrinter printer;
	//std::cout << "Representation before removing triples " << std::endl;
	//printer.print_ir_representation(*fn->get_ir_prgram());

	bool changed = false;
	do {
		changed = false;
		auto blks = fn->get_basic_blocks();

		for (size_t i = blks.size(); i-- > 0; ) {
			auto& triples = blks[i]->get_all_triples();
			for (size_t j = triples.size(); j-- > 0;) {
				IRTriple* triple = triples[j];

				if (is_triple_dead(triple)) {
					blks[i]->remove_triple(triple);
					changed = true;
				}
			}
		}

	} while (changed);

	//std::cout << "Representation after removing triples " << std::endl;
	//printer.print_ir_representation(*fn->get_ir_prgram());
}