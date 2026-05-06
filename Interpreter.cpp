
Interpreter::Interpreter(IRProgram* p, IRFunction* fn, std::vector<IROperand>& fn_arguments) :m_ir_program{ p }, m_current_function{ fn }, m_fn_arguments{ fn_arguments } {
	m_global_variables.resize(p->get_global_variables().size());
}

void Interpreter::set_listener(IRInterpreterListener* l) {
	m_listener = l;
}



ConstantValue Interpreter::get_operand_value(const IROperand& op) {
	switch (op.m_operand_type)
	{
	case IROperandType::CONSTANT: {
		return op.get_constant()->get_value();
	}
	case IROperandType::VARIABLE: {
		IRVariable* variable = op.get_variable();
		size_t index = op.get_variable()->get_index();

		if (variable->is_global()) {
			return m_global_variables[index];
		}
		else {
			return m_current_frame->m_local_variables[index];
		}

	}
	case IROperandType::TRIPLE: {
		size_t index = op.get_triple()->get_global_index();

		return 	m_current_frame->m_triple_values[index];
	}
	case IROperandType::FUNCTION: {
		return op.get_function();
	}
	default:
		break;
	}
}

// operation + / - / * / div 
template <class T>
T Interpreter::execute_arithmetic_operation(T val_1, T val_2, IROperation operation) {
	switch (operation)
	{
	case IROperation::ADD:
		return val_1 + val_2;
	case IROperation::SUB:
		return val_1 - val_2;
	case IROperation::DIV: {
		if (val_2 == 0)
			throw std::runtime_error("can't divide by 0");
		return val_1 / val_2;
	}
	case IROperation::MUL:
		return val_1 * val_2;
	default:
		break;
	}
}

ConstantValue Interpreter::execute_arithmetic_operation(const TypeRef& type, IROperation op, ConstantValue& cv1, ConstantValue& cv2) {
	ConstantValue value;
	switch (type.get_ir_basic_type())
	{
	case IRBasicType::INT8: {
		value = execute_arithmetic_operation(cv1.get_value<int8_t>(), cv2.get_value<int8_t>(), op);
	}
	case IRBasicType::INT16: {
		value = execute_arithmetic_operation(cv1.get_value<int16_t>(), cv2.get_value<int16_t>(), op);
		break;
	}
	case IRBasicType::INT32: {
		value = execute_arithmetic_operation(cv1.get_value<int32_t>(), cv2.get_value<int32_t>(), op);
		break;
	}
	case IRBasicType::INT64: {
		value = execute_arithmetic_operation(cv1.get_value<int64_t>(), cv2.get_value<int64_t>(), op);
		break;
	}
	case IRBasicType::UINT8: {
		value = execute_arithmetic_operation(cv1.get_value<uint8_t>(), cv2.get_value<uint8_t>(), op);
		break;
	}
	case IRBasicType::UINT16: {
		value = execute_arithmetic_operation(cv1.get_value<uint16_t>(), cv2.get_value<uint16_t>(), op);
		break;
	}
	case IRBasicType::UINT32: {
		value = execute_arithmetic_operation(cv1.get_value<uint32_t>(), cv2.get_value<uint32_t>(), op);
		break;
	}
	case IRBasicType::UINT64: {
		value = execute_arithmetic_operation(cv1.get_value<uint64_t>(), cv2.get_value<uint64_t>(), op);
		break;
	}
	case IRBasicType::FLOAT: {
		value = execute_arithmetic_operation(cv1.get_value<float>(), cv2.get_value<float>(), op);
		break;
	}
	case IRBasicType::DOUBLE: {
		value = execute_arithmetic_operation(cv1.get_value<double>(), cv2.get_value<double>(), op);
		break;
	}
	case IRBasicType::BOOL: {
		value = execute_arithmetic_operation(cv1.get_value<bool>(), cv2.get_value<bool>(), op);
		break;
	}
	case IRBasicType::VOID: {
		break;
	}
	default:
		break;
	}

	return value;
}

template <class T>
bool Interpreter::execute_cmp_operation(T v1, T v2, IROperation operation) {
	//ConstantValue value;
	switch (operation)
	{
	case IROperation::GT:
		return v1 > v2;
	case IROperation::GE:
		return v1 >= v2;
	case IROperation::LT:
		return v1 < v2;
	case IROperation::LE:
		return v1 <= v2;
	case IROperation::EQ:
		return v1 == v2;
	case IROperation::NEQ:
		return v1 != v2;
	default:
		throw std::runtime_error("unknown compare operator");
	}
}

ConstantValue Interpreter::execute_cmp_operation(IROperation op, ConstantValue& cv1, ConstantValue& cv2) {
	ConstantValue value;
	//cv1.get_basic_type()
	switch (cv1.get_basic_type())
	{
	case IRBasicType::INT8: {
		value = execute_cmp_operation(cv1.get_value<int8_t>(), cv2.get_value<int8_t>(), op);
	}
	case IRBasicType::INT16: {
		value = execute_cmp_operation(cv1.get_value<int16_t>(), cv2.get_value<int16_t>(), op);
		break;
	}
	case IRBasicType::INT32: {
		value = execute_cmp_operation(cv1.get_value<int32_t>(), cv2.get_value<int32_t>(), op);
		break;
	}
	case IRBasicType::INT64: {
		value = execute_cmp_operation(cv1.get_value<int64_t>(), cv2.get_value<int64_t>(), op);
		break;
	}
	case IRBasicType::UINT8: {
		value = execute_cmp_operation(cv1.get_value<uint8_t>(), cv2.get_value<uint8_t>(), op);
		break;
	}
	case IRBasicType::UINT16: {
		value = execute_cmp_operation(cv1.get_value<uint16_t>(), cv2.get_value<uint16_t>(), op);
		break;
	}
	case IRBasicType::UINT32: {
		value = execute_cmp_operation(cv1.get_value<uint32_t>(), cv2.get_value<uint32_t>(), op);
		break;
	}
	case IRBasicType::UINT64: {
		value = execute_cmp_operation(cv1.get_value<uint64_t>(), cv2.get_value<uint64_t>(), op);
		break;
	}
	case IRBasicType::FLOAT: {
		value = execute_cmp_operation(cv1.get_value<float>(), cv2.get_value<float>(), op);
		break;
	}
	case IRBasicType::DOUBLE: {
		value = execute_cmp_operation(cv1.get_value<double>(), cv2.get_value<double>(), op);
		break;
	}
	case IRBasicType::BOOL: {
		value = execute_cmp_operation(cv1.get_value<bool>(), cv2.get_value<bool>(), op);
		break;
	}
	case IRBasicType::VOID: {
		break;
	}
	default:
		break;
	}

	return value;
}



IRStackFrame* Interpreter::add_frame(IRBasicBlock* blk, IRTriple* r_t, size_t triple_count,size_t l_var_count,size_t total_size) {
	//m_frames.emplace_back(blk, r_t, triple_count,l_var_count);
	m_frames.emplace_back(blk,r_t,triple_count,l_var_count,total_size);
	return &m_frames.back();
}

void Interpreter::pop_frame() {
	m_frames.pop_back();
}

void Interpreter::start() {
	auto basic_blks = m_current_function->get_basic_blocks();

	std::vector<IROperand> args;

	bool finished = false;
	IRBasicBlock* current_blk = basic_blks[0];
	int current_blk_triple_index = 0;
	//m_current_function->
	m_current_frame = add_frame(current_blk, nullptr, m_current_function->get_triple_count(),m_current_function->get_variables().size(),m_current_function->get_required_size());
	while (true) {
		IRTriple* current_triple = current_blk->get_all_triples()[current_blk_triple_index];

		switch (current_triple->get_ir_operation())
		{
		case IROperation::ASSIGN: {
			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];
		
			IRVariable* var = op1.get_variable();
			size_t index = var->get_index();
			ConstantValue c_v = get_operand_value(op2);

			if (var->is_global()) {
				m_global_variables[index] = c_v;
			}
			else {
				m_current_frame->m_local_variables[index] = c_v;
			}

			break;
		}
		case IROperation::ADD:
		case IROperation::SUB:
		case IROperation::MUL:
		case IROperation::DIV:
		case IROperation::BITWISE_AND:
		case IROperation::BITWISE_OR:
		case IROperation::BITWISE_XOR: {
			IROperation operation = current_triple->get_ir_operation();

			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];
			ConstantValue cv1 = get_operand_value(op1);
			ConstantValue cv2 = get_operand_value(op2);

			size_t index = current_triple->get_global_index();
			TypeRef type = current_triple->get_data_type();
			ConstantValue value = execute_arithmetic_operation(type, operation, cv1, cv2);

			m_current_frame->m_triple_values[index] = value;
			break;
		}
		case IROperation::LT:
		case IROperation::LE:
		case IROperation::GT:
		case IROperation::GE:
		case IROperation::EQ:
		case IROperation::NEQ: {
			IROperation operation = current_triple->get_ir_operation();
			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];
			ConstantValue cv1 = get_operand_value(op1);
			ConstantValue cv2 = get_operand_value(op2);

			size_t index = current_triple->get_global_index();
			TypeRef type = current_triple->get_data_type();
			ConstantValue value = execute_cmp_operation(operation, cv1, cv2);

			m_current_frame->m_triple_values[index] = value;
			break;
		}
		case IROperation::ASSERT: {
			ConstantValue cv = get_operand_value(current_triple->m_operands[0]);
			if (cv.get_value<bool>())
				m_listener->assertion_succeded();
			else
				m_listener->assertion_failed(current_triple->m_line_number, "assertion failed");
			break;
		}
		case IROperation::RETURN: {
			IRFunction* out_fun = m_current_function;
			IRStackFrame* frame = &m_frames.back();
			ConstantValue return_value;
			IROperand op1;

			if (current_triple->m_operands.size()>0) {
				return_value = get_operand_value(current_triple->m_operands[0]);
			}

			IRTriple* triple_return_addr = frame->m_return_triple;
			if (triple_return_addr) {
				size_t index = triple_return_addr->get_local_index();

				m_current_function = frame->m_return_blk->get_function();
				current_blk = frame->m_return_blk;
				current_blk_triple_index = triple_return_addr->get_local_index();
			}
			else {
				m_current_function = nullptr;
				finished = true;
			}

			pop_frame();

			m_current_frame = m_frames.size() > 0 ? &m_frames.back() : nullptr;
			if (m_current_frame)
				m_current_frame->m_triple_values[triple_return_addr->get_global_index()] = return_value;

			m_listener->function_call_end(out_fun,return_value);
			
			break;
		}
		case IROperation::JMP: {
			IROperand op = current_triple->m_operands[0];
			current_blk = std::get<IRBasicBlock*>(op.m_value);
			current_blk_triple_index = 0;
			continue;
		}
		case IROperation::JC: {
			ConstantValue cond_value = get_operand_value(current_triple->m_operands[0]);

			if (cond_value.get_value<bool>()) {
				IROperand op = current_triple->m_operands[1];
				current_blk = std::get<IRBasicBlock*>(op.m_value);
				current_blk_triple_index = 0;
			}
			else {
				IROperand op = current_triple->m_operands[2];
				current_blk = std::get<IRBasicBlock*>(op.m_value);
				current_blk_triple_index = 0;
			}

			continue;
		}
		case IROperation::PRINT: {
			ConstantValue value = get_operand_value(current_triple->m_operands[0]);
			m_listener->print_called(value);

			break;
		}
		case IROperation::FUNCTION_CALL: {
			std::vector<IROperand> arguments = current_triple->get_function_call_arguments();
			std::vector<ConstantValue> values_passed_to_func;
			
			IROperand function_op = current_triple->m_operands[0];
			IRFunction* fn = function_op.get_function();
			m_current_function = fn;
			size_t function_triple_count = function_op.get_function()->get_triple_count();

			add_frame(current_blk, current_triple, function_triple_count, fn->get_variables().size(),m_current_function->get_required_size());
			std::vector<IRVariable*> parameters = fn->get_parameters();
			for (size_t i = 0; i < parameters.size();i++) {
				// trzeba sci¹gn¹æ z parameters i pod nie ustawic te wartoœci
				//size_t param_index = parameters[i]->get_index();
				auto value = get_operand_value(arguments[i]);
				m_frames.back().m_local_variables[i] = value;
				values_passed_to_func.push_back(value);
			}

			m_current_frame = &m_frames.back();

			m_listener->function_call_start(values_passed_to_func,fn);
			IROperand op = current_triple->m_operands[0];

			current_blk = fn->get_basic_blk(0);
			current_blk_triple_index = 0;
			
			continue;
		}
		case IROperation::ARRAY_ACCESS: {


			break;
		}
		default:
			throw std::runtime_error("ir operation is not supported");
		}
		if (finished)
			break;

		current_blk_triple_index++;
	}

}




//size_t Interpreter::calculate_required_size(IRFunction* fn) {
//	std::vector<IRBasicBlock*> blks = fn->get_basic_blocks();
//	std::vector<IRVariable*> params = fn->get_parameters();
//	size_t total_size_required = 0;
//
//	for (size_t i = 0; i < params.size();i++) {
//		TypeRef ref = params[i]->get_data_type();
//		size_t size = ref.get_size();
//		total_size_required += size;
//	}
//
//	std::vector<IRVariable*> local_variables = fn->get_variables();
//	for (size_t i = 0; i < local_variables.size();i++) {
//		TypeRef ref = local_variables[i]->get_data_type();
//		size_t size = ref.get_size();
//		total_size_required += size;
//	}
//
//	size_t required_size_for_triples = 0;
//
//	for (size_t i = 0; i < blks.size();i++) {
//		auto *blk = blks[i];
//		std::vector<IRTriple*> all_triples = blk->get_all_triples();
//		for (size_t j = 0; j < all_triples.size();j++) {
//			IRTriple *current_triple = all_triples[j];
//			TypeRef type = current_triple->get_data_type();
//
//			if (type && type.has_size()) {
//				required_size_for_triples += type.get_size();
//			}
//		}
//	}
//
//	total_size_required += required_size_for_triples;
//
//	return total_size_required;
//}