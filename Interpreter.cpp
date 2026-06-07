
Interpreter::Interpreter(IRProgram* p, IRFunction* fn, std::vector<IROperand>& fn_arguments) :m_ir_program{ p }, m_current_function{ fn }, m_fn_arguments{ fn_arguments } {
	m_global_variables.resize(p->get_global_variables().size());
	//IRFunction* get_function(const std::string & name, const std::vector<IROperand> &arguments);
	m_meomory_for_gl_variables.resize(p->get_function("_global_function", {})->get_required_size());
}

void Interpreter::set_listener(IRInterpreterListener* l) {
	m_listener = l;
}

uint8_t* Interpreter::get_operand_address(IROperand op,bool ignore_reference) {
	
	switch (op.m_operand_type)
	{
	case IROperandType::CONSTANT:{
		return const_cast<uint8_t*>(op.get_constant()->get_value().get_address());
	}
	case IROperandType::MEMBER: {

		break;
	}
	case IROperandType::TRIPLE: {
		IRTriple *t = op.get_triple();
		return m_current_frame->m_triple_addresses[t->get_global_index()];
	}
	case IROperandType::VARIABLE: {
		IRVariable* variable = op.get_variable();
		size_t index;

		if (variable->get_data_type().is_reference() && !ignore_reference) {
			size_t offset = variable->get_local_mem_offset();
			uint8_t* address = &m_current_frame->m_memory_stack[0] + offset;
			return *reinterpret_cast<uint8_t**>(address);
		}
		else {
			index = op.get_variable()->get_index();
		}

		if (variable->is_global()) {
			throw std::runtime_error("dont use global");
		}
		else {
			size_t offset = variable->get_local_mem_offset();
			return &m_current_frame->m_memory_stack[0] + offset;
		}
		break;
	}
	default:
		break;
	}
}

ConstantValue Interpreter::get_operand_value(const IROperand& op) {
	throw std::runtime_error("can't be used!");
	//switch (op.m_operand_type)
	//{
	//case IROperandType::CONSTANT: {
	//	return op.get_constant()->get_value();
	//}
	//case IROperandType::VARIABLE: {
	//	IRVariable* variable = op.get_variable();
	//	size_t index = op.get_variable()->get_index();

	//	if (variable->is_global()) {
	//		return m_global_variables[index];
	//	}
	//	else {
	//		return m_current_frame->m_local_variables[index];
	//	}

	//}
	//case IROperandType::TRIPLE: {
	//	size_t index = op.get_triple()->get_global_index();

	//	return 	m_current_frame->m_triple_values[index];
	//}
	//case IROperandType::FUNCTION: {
	//	return op.get_function();
	//}
	//default:
	//	break;
	//}
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

void Interpreter::execute_arithmetic_operation_on_addresses(const TypeRef& type, IROperation op,const uint8_t* cv1,const uint8_t* cv2,uint8_t* res_addr) {
	ConstantValue value;
	if (type.is_array()) {
		
	}
	else {
		switch (type.get_ir_basic_type())
		{
		case IRBasicType::INT8: {
			*reinterpret_cast<int8_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const int8_t*>(cv1), *reinterpret_cast<const int8_t*>(cv2), op);
		}
		case IRBasicType::INT16: {
			*reinterpret_cast<int16_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const int16_t*>(cv1), *reinterpret_cast<const int16_t*>(cv2), op);
			break;
		}
		case IRBasicType::INT32: {
			*reinterpret_cast<int32_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const int32_t *>(cv1),*reinterpret_cast<const int32_t *>(cv2),op);
			break;
		}
		case IRBasicType::INT64: {
			*reinterpret_cast<int64_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const int64_t*>(cv1), *reinterpret_cast<const int64_t*>(cv2), op);
			break;
		}
		case IRBasicType::UINT8: {
			*reinterpret_cast<uint8_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const uint8_t*>(cv1), *reinterpret_cast<const uint8_t*>(cv2), op);
			break;
		}
		case IRBasicType::UINT16: {

			*reinterpret_cast<uint16_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const uint16_t*>(cv1), *reinterpret_cast<const uint16_t*>(cv2), op);
			break;
		}
		case IRBasicType::UINT32: {
			*reinterpret_cast<uint32_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const uint32_t*>(cv1), *reinterpret_cast<const uint32_t*>(cv2), op);
			break;
		}
		case IRBasicType::UINT64: {
			*reinterpret_cast<uint64_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const uint64_t*>(cv1), *reinterpret_cast<const uint64_t*>(cv2), op);
			break;
		}
		case IRBasicType::FLOAT: {
			*reinterpret_cast<float*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const float*>(cv1), *reinterpret_cast<const float*>(cv2), op);
			break;
		}
		case IRBasicType::DOUBLE: {
			*reinterpret_cast<double *>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const double*>(cv1), *reinterpret_cast<const double*>(cv2), op);
			break;
		}
		case IRBasicType::BOOL: {
			*reinterpret_cast<bool*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const bool*>(cv1), *reinterpret_cast<const bool*>(cv2), op);
			break;
		}
		case IRBasicType::VOID: {
			break;
		}
		default:
			break;
		}
	}

}


template <class T>
bool Interpreter::execute_cmp_operation(T v1, T v2, IROperation operation) {
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

void Interpreter::execute_cmp_operation_on_arrays(const TypeRef& type1,const TypeRef& type2, IROperation op, uint8_t* arr1, uint8_t* arr2, uint8_t* res_addr, const TypeRef& res_type) {
	ArrayIterator arr1_iter{ arr1,type1 };
	ArrayIterator arr2_iter{ arr2,type2 };
	ArrayIterator result_iter{ res_addr, res_type };
	
	size_t size = std::max(arr1_iter.get_count(), arr1_iter.get_count());
	bool boolean_result;

	for (size_t i = 0; i < size; i++) {
		switch (arr1_iter.get_element_type().get_ir_basic_type())
		{
		case IRBasicType::INT8: {
			*(*result_iter) = execute_cmp_operation<int8_t>(*reinterpret_cast<int8_t*>(*arr1_iter), *reinterpret_cast<int8_t*>(*arr2_iter),op);
			break;
		}
		case IRBasicType::INT16: {
			*(*result_iter) = execute_cmp_operation<int16_t>(*reinterpret_cast<int16_t*>(*arr1_iter), *reinterpret_cast<int16_t*>(*arr2_iter), op);
			break;
		}
		case IRBasicType::INT32: {
			bool result_value = execute_cmp_operation<int32_t>(*reinterpret_cast<int32_t*>(*arr1_iter), *reinterpret_cast<int32_t*>(*arr2_iter), op);

			*(*result_iter) = result_value;
			std::cout <<"Saved value"<< *reinterpret_cast<bool*>(*result_iter) << std::endl;
			break;
		}
		case IRBasicType::INT64: {
			*(*result_iter) = execute_cmp_operation<int64_t>(*reinterpret_cast<int64_t*>(*arr1_iter), *reinterpret_cast<int64_t*>(*arr2_iter), op);
			break;
		}
		case IRBasicType::UINT8: {
			*(*result_iter) = execute_cmp_operation<uint8_t>(*reinterpret_cast<uint8_t*>(*arr1_iter), *reinterpret_cast<uint8_t*>(*arr2_iter), op);
			break;
		}
		case IRBasicType::UINT16: {
			*(*result_iter) = execute_cmp_operation<uint16_t>(*reinterpret_cast<uint16_t*>(*arr1_iter), *reinterpret_cast<uint16_t*>(*arr2_iter), op);
			break;
		}
		case IRBasicType::UINT32: {
			*(*result_iter) = execute_cmp_operation<uint32_t>(*reinterpret_cast<uint32_t*>(*arr1_iter), *reinterpret_cast<uint32_t*>(*arr2_iter), op);
			break;
		}
		case IRBasicType::UINT64: {
			*(*result_iter) = execute_cmp_operation<uint64_t>(*reinterpret_cast<uint64_t*>(*arr1_iter), *reinterpret_cast<uint64_t*>(*arr2_iter), op);
			break;
		}
		case IRBasicType::FLOAT: {
			*(*result_iter) = execute_cmp_operation<float>(*reinterpret_cast<float*>(*arr1_iter), *reinterpret_cast<float*>(*arr2_iter), op);
			break;
		}
		case IRBasicType::DOUBLE: {
			*(*result_iter) = execute_cmp_operation<double>(*reinterpret_cast<double*>(*arr1_iter), *reinterpret_cast<double*>(*arr2_iter), op);
			break;
		}
		case IRBasicType::BOOL: {
			*(*result_iter) = execute_cmp_operation<bool>(*reinterpret_cast<bool*>(*arr1_iter), *reinterpret_cast<bool*>(*arr2_iter), op);
			break;
		}
		default:
			break;
		}

		arr1_iter.next();
		arr2_iter.next();
		result_iter.next();
	}
}

IRStackFrame* Interpreter::add_frame(IRBasicBlock* blk, IRTriple* r_t, size_t triple_count,size_t l_var_count,size_t total_size) {
	m_frames.emplace_back(blk,r_t,triple_count,l_var_count,total_size);
	return &m_frames.back();
}

void Interpreter::pop_frame() {
	m_frames.pop_back();
}

void Interpreter::start() {
	auto basic_blks = m_current_function->get_basic_blocks();
	auto variables = m_current_function->get_variables();

	std::vector<IROperand> args;
	bool finished = false;
	IRBasicBlock* current_blk = basic_blks[0];
	int current_blk_triple_index = 0;

	m_current_frame = add_frame(current_blk, nullptr, m_current_function->get_triple_count(),m_current_function->get_variables().size(),m_current_function->get_required_size());

	while (true) {
		IRTriple* current_triple = current_blk->get_all_triples()[current_blk_triple_index];
		// CONSTANT
		// BLAD Z ROZMIARU 
		switch (current_triple->get_ir_operation())
		{
		case IROperation::ASSIGN: {
			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];

			uint8_t* addr1 = get_operand_address(op1);
			uint8_t* addr2 = get_operand_address(op2);
			int32_t* value1 = reinterpret_cast<int32_t*>(addr1);
			int32_t* value2 = reinterpret_cast<int32_t*>(addr2);

			TypeRef type = op1.get_data_type().remove_reference();
			size_t size = type.get_size();
			memcpy(addr1,addr2,size);

			break;
		}
		case IROperation::INIT_ASSIGN: {
			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];

			uint8_t* addr1 = get_operand_address(op1,true);
			uint8_t* addr2 = get_operand_address(op2);
			int32_t* value1 = nullptr;
			if (op1.get_data_type().is_reference()) {
				*reinterpret_cast<uint8_t**>(addr1) = addr2;
			}
			else {
				TypeRef type = op1.get_data_type();
				size_t size = type.get_size();
				memcpy(addr1, addr2, size);
			}

			break;
		}
		case IROperation::ADD:
		case IROperation::SUB:
		case IROperation::MUL:
		case IROperation::DIV:
		case IROperation::BITWISE_AND:
		case IROperation::BITWISE_OR:
		case IROperation::BITWISE_XOR:
		{
			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];

			uint8_t *addr1 = get_operand_address(op1);
			uint8_t *addr2 = get_operand_address(op2);
			TypeRef type_op1 = op1.get_data_type();
			TypeRef type_op2 = op2.get_data_type();
			

			uint8_t* result_addr = &m_current_frame->m_memory_stack[0] + current_triple->get_local_mem_offset();
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_addr;
			IRArrayNode* arr_node1 = static_cast<IRArrayNode*>(type_op1.get_data_type_node());
			IRArrayNode* arr_node2 = static_cast<IRArrayNode*>(type_op2.get_data_type_node());

			ArrayIterator arr_iter_1{addr1,type_op1};
			ArrayIterator arr_iter_2{addr2,type_op2};

			uint8_t * result_arr_address = get_operand_address(current_triple);
			TypeRef result_type = arr_iter_1.get_count() > arr_iter_2.get_count() ? type_op1 : type_op2;
			ArrayIterator result_iter{result_arr_address,result_type};
			for (size_t i = 0; i < result_iter.get_count();i++) {
				uint8_t* current_arr_1_addr = *arr_iter_1;
				uint8_t * current_arr_2_addr = *arr_iter_2;
				uint8_t * result_arr_addr = *result_iter;
				execute_arithmetic_operation_on_addresses(result_iter.get_element_type(),current_triple->get_ir_operation(), current_arr_1_addr, current_arr_2_addr,result_arr_addr);

				arr_iter_1.next();
				arr_iter_2.next();
				result_iter.next();
			}

			break;
		}
		case IROperation::LT:
		case IROperation::LE:
		case IROperation::GT:
		case IROperation::GE:
		case IROperation::EQ:
		case IROperation::NEQ: {

			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];

			uint8_t* addr1 = get_operand_address(op1);
			uint8_t* addr2 = get_operand_address(op2);
			TypeRef type1 = op1.get_data_type();
			TypeRef type2 = op2.get_data_type();

			uint8_t* result_addr = &m_current_frame->m_memory_stack[0] + current_triple->get_local_mem_offset();
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_addr;

			execute_cmp_operation_on_arrays(type1,type2,current_triple->get_ir_operation(),addr1,addr2,result_addr, current_triple->get_data_type());

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
			TypeRef type;

			uint8_t* return_value_address = nullptr;
			if (current_triple->m_operands.size()>0) {
				IROperand op1 = current_triple->m_operands[0];
				type = op1.get_data_type();
				return_value_address = get_operand_address(op1);
			}

			IRTriple* function_call_triple = frame->m_return_triple;
			if (function_call_triple) {
				size_t index = function_call_triple->get_local_index();

				m_current_function = frame->m_return_blk->get_function();
				current_blk = frame->m_return_blk;
				current_blk_triple_index = function_call_triple->get_local_index();
			}
			else {
				m_current_function = nullptr;
				finished = true;
			}

			m_current_frame = m_frames.size() > 1 ? &*(--(--m_frames.end())) : nullptr;
			if (m_current_frame) {
				if (current_triple->m_operands.size() > 0) {
					m_current_frame->m_triple_addresses[function_call_triple->get_global_index()] = m_current_frame->m_memory_stack.data() + function_call_triple->get_local_mem_offset();
					size_t size = type.get_size();
					memcpy(m_current_frame->m_triple_addresses[function_call_triple->get_global_index()],return_value_address,size);
				}
			}

			pop_frame();

			m_listener->function_call_end(out_fun,return_value_address);

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
			// # TODO ZROBIC PRINTOWANIE ARRAYÓW
			IROperand op = current_triple->m_operands[0];
			TypeRef type = op.get_data_type();
			type = type.remove_reference().remove_qualifiers();

			if (type.is_array()) {
				IRArrayNode* arr_node = static_cast<IRArrayNode*>(type.get_data_type_node());
				type = type.remove_all_extents();
				size_t arr_size = arr_node->m_count;
				
				IRBasicType basic_type = type.get_ir_basic_type();
				uint8_t* address = get_operand_address(op);
				size_t element_size = type.get_size();
				std::string msg = "[";

				for (size_t i = 0; i < arr_size; i++) {
					if (i != 0)
						msg += ",";

					ConstantValue value = ConstantValue{basic_type,address};
					msg += value.to_string();
					address += element_size;
				}

				msg += "]";

				m_listener->print_called(msg);
			}
			else if (type.is_pointer()) {
				IROperand op = current_triple->m_operands[0];
				uint8_t* address = get_operand_address(op);
				std::string msg = std::format("{:#x}", reinterpret_cast<uintptr_t>(address));
				m_listener->print_called(msg);
			}
			else {
				uint8_t* address = get_operand_address(op);
				std::cout << "address to be printed: " << reinterpret_cast<void*>(address) << std::endl;
				type = type.remove_reference();

				IRBasicType basic_type = type.get_ir_basic_type();
				ConstantValue value = ConstantValue{basic_type,address};
				m_listener->print_called(value.to_string());
			}

			break;
		}
		// funkcja jest Ÿle wywo³ywana 
		case IROperation::FUNCTION_CALL: {
			std::vector<IROperand> arguments = current_triple->get_function_call_arguments();
			std::vector<ConstantValue> values_passed_to_func;
			
			IROperand function_op = current_triple->m_operands[0];
			IRFunction* fn = function_op.get_function();
			m_current_function = fn;
			size_t function_triple_count = function_op.get_function()->get_triple_count();

			add_frame(current_blk, current_triple, function_triple_count, fn->get_variables().size(),m_current_function->get_required_size());
			std::vector<IRVariable*> parameters = fn->get_parameters();
			for (size_t i = 0; i < arguments.size();i++) {
				if (parameters[i]->get_data_type().is_reference()) {
					uint8_t* argument_address = get_operand_address(arguments[i]);
					TypeRef type = parameters[i]->get_data_type();
					size_t size = type.get_size();

					uint8_t* parameter_address = m_frames.back().m_memory_stack.data() + parameters[i]->get_local_mem_offset();
					*reinterpret_cast<uint8_t**>(parameter_address) = argument_address;
					values_passed_to_func.push_back(argument_address);
				}
				else {
					uint8_t* passed_value_address = get_operand_address(arguments[i]);
					TypeRef type = parameters[i]->get_data_type();
					size_t size = type.get_size();
					std::cout <<"Parameter address: " << * reinterpret_cast<void**>(passed_value_address) << std::endl;
					uint8_t* argument_value_address = m_frames.back().m_memory_stack.data() + parameters[i]->get_local_mem_offset();
					memcpy(argument_value_address,passed_value_address,size);
					values_passed_to_func.push_back(argument_value_address);
				}
			}

			m_current_frame = &m_frames.back();
			m_listener->function_call_start(values_passed_to_func,fn);
			IROperand op = current_triple->m_operands[0];

			current_blk = fn->get_basic_blk(0);
			current_blk_triple_index = 0;
			
			continue;
		}
		case IROperation::ARRAY_ACCESS: {
			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];
	
			TypeRef type = op1.get_data_type();
			uint8_t* starting_address = nullptr;

			if (type.is_array()) {
				type = type.remove_all_extents();
				starting_address = get_operand_address(op1);
			}
			else if (type.is_pointer()) {
				type = type.remove_pointer_with_qualifiers();
				starting_address = get_operand_address(op1);
				starting_address = *reinterpret_cast<uint8_t**>(starting_address);
			}
			else {
				throw std::runtime_error("unkown type");
			}

			size_t size_of_element = type.get_size();

			TypeRef type_of_index_element = op2.get_data_type();
			uint8_t* value = get_operand_address(op2);
			int32_t* pointer = reinterpret_cast<int32_t*>(value);

			IRBasicType basic_type = type_of_index_element.get_ir_basic_type();
			ConstantValue constant_value = ConstantValue{ basic_type,value };

			std::optional<int64_t> converted_value_op = convert_value_to<int64_t>(constant_value);
			
			size_t converted_value;
			if (converted_value_op.has_value()) {
				converted_value = converted_value_op.value();
			}
			else
				throw std::runtime_error("can't convert value from empty optional");
		
			size_t offset = converted_value * size_of_element;
			uint8_t* result_addr = starting_address + offset;
			std::cout <<"Stored value "<< *reinterpret_cast<uint32_t*>(result_addr) << std::endl;
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_addr;
			break;
		}
		case IROperation::MEMBER_ACCESS: {
			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];

			TypeRef type = op1.get_data_type();
			uint8_t* starting_address = nullptr;

			if (type.is_pointer()) {
				type = type.remove_pointer_with_qualifiers();
				starting_address = get_operand_address(op1);
				starting_address = *reinterpret_cast<uint8_t**>(starting_address);
			}
			else if (type.is_composite()) {
				type = type.remove_all_extents();
				starting_address = get_operand_address(op1);
			}
			else {
				throw std::runtime_error("unkown type");
			}
			
			size_t offset = op2.get_member()->get_offset();
			uint8_t* result_addr = starting_address + offset;
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_addr;
			break;
		}
		// ADDRESS_OF not ADREESS_OF
		// zmienic nazwe 
		case IROperation::ADREESS_OF: {

			IROperand op1 = current_triple->m_operands[0];
			uint8_t* op_1_addr = get_operand_address(op1);
			uint8_t* result_addr = &m_current_frame->m_memory_stack[0] + current_triple->get_local_mem_offset();
			int32_t* result = reinterpret_cast<int32_t*>(op_1_addr);
			std::cout <<"Whta's in the mem: "<< * result << std::endl;
			*reinterpret_cast<void**>(result_addr) = op_1_addr;
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_addr;

			break;
		}
		case IROperation::DEREFERENCE: {
			IROperand op1 = current_triple->m_operands[0];
			uint8_t* op_1_addr = get_operand_address(op1);
			uint8_t* result_addr = nullptr;
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = *reinterpret_cast<uint8_t**>(op_1_addr);
			break;
		}
		case IROperation::SELECT: {
			IROperand op_1 = current_triple->m_operands[0];
			IROperand op_2 = current_triple->m_operands[1];
			IROperand op_3 = current_triple->m_operands[2];

			uint8_t* op_1_addr = get_operand_address(op_1);
			uint8_t* op_2_addr = get_operand_address(op_2);
			uint8_t* op_3_addr = get_operand_address(op_3);
			uint8_t *result_array_addr = m_current_frame->m_memory_stack.data() + current_triple->get_local_mem_offset();
			
			ArrayIterator condition_array_iter{op_1_addr,op_1.get_data_type()};
			ArrayIterator expr_true_array_iter{op_2_addr,op_2.get_data_type()};
			ArrayIterator expr_false_array_iter{op_3_addr,op_3.get_data_type()};
			ArrayIterator result_array_iter{result_array_addr,current_triple->get_data_type()};
			
			size_t size = condition_array_iter.get_count();
			result_array_iter.get_element_type();
			size_t element_size = result_array_iter.get_element_type().get_size();
			for (size_t i = 0; i < size;i++) {
				if (*(*condition_array_iter)==true)
					memcpy((*result_array_iter),*expr_true_array_iter, result_array_iter.get_element_type().get_size());
				else
					memcpy((*result_array_iter), *expr_false_array_iter, result_array_iter.get_element_type().get_size());

				condition_array_iter.next();
				expr_true_array_iter.next();
				expr_false_array_iter.next();
				result_array_iter.next();
			}

			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_array_addr;
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

template <class To>
std::optional<To> Interpreter::convert_value_to(ConstantValue &v) const {
	if (!v.is_empty())
		throw std::runtime_error("no type has been set");

	switch (v.get_basic_type())
	{
	case IRBasicType::INT8:
		return { static_cast<To>(v.get_value<int8_t>()) };
	case IRBasicType::INT16:
		return { static_cast<To>(v.get_value<int16_t>()) };
	case IRBasicType::INT32: {
		return { static_cast<To>(v.get_value<int32_t>()) };
	}
	case IRBasicType::INT64:
		return { static_cast<To>(v.get_value<int64_t>()) };
	case IRBasicType::UINT8:
		return { static_cast<To>(v.get_value<uint8_t>()) };
	case IRBasicType::UINT16:
		return { static_cast<To>(v.get_value<uint16_t>()) };
	case IRBasicType::UINT32:
		return { static_cast<To>(v.get_value<uint32_t>()) };
	case IRBasicType::UINT64:
		return { static_cast<To>(v.get_value<uint64_t>()) };
	case IRBasicType::FLOAT:
		return { static_cast<To>(v.get_value<float>()) };
	case IRBasicType::DOUBLE:
		return { static_cast<To>(v.get_value<double>()) };
	case IRBasicType::BOOL:
		return { static_cast<To>(v.get_value<bool>()) };
	case IRBasicType::VOID: {
		break;
	}
	default:
		break;
	}
}