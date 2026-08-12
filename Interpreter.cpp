
Interpreter::Interpreter(IRProgram* p, IRFunction* fn, std::vector<IROperand>& fn_arguments) :m_ir_program{ p }, m_current_function{ fn }, m_fn_arguments{ fn_arguments } {
	m_global_variables.resize(p->get_global_variables().size());
	std::cout << m_ir_program->m_required_for_global_variables;
	m_meomory_for_gl_variables.resize(m_ir_program->m_required_for_global_variables);
}

void Interpreter::set_listener(IRInterpreterListener* l) {
	m_listener = l;
}

uint8_t* Interpreter::get_operand_address(IROperand op,bool ignore_reference) {
	
	switch (op.m_operand_type)
	{
	case IROperandType::CONSTANT:{
		return op.get_constant()->get_address();
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
			size_t offset = variable->get_local_mem_offset();
			uint8_t* result =  m_meomory_for_gl_variables.data() + offset;
			std::cout << "Found value " << (int)(*result) << std::endl;
			return result;
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
}

IRStackFrame* Interpreter::add_frame(IRBasicBlock* blk, IRTriple* r_t, size_t triple_count,size_t l_var_count,size_t total_size) {
	m_frames.emplace_back(blk,r_t,triple_count,l_var_count,total_size);
	return &m_frames.back();
}

void Interpreter::pop_frame() {
	m_frames.pop_back();
}

void Interpreter::start(IRFunction* fn) {
	m_current_function = fn;
	auto basic_blks = m_current_function->get_basic_blocks();
	auto variables = m_current_function->get_variables();
	
	std::vector<IROperand> args;
	bool finished = false;
	IRBasicBlock* current_blk = basic_blks[0];
	int current_blk_triple_index = 0;

	m_current_frame = add_frame(current_blk, nullptr, m_current_function->get_triple_count(),m_current_function->get_variables().size(),m_current_function->get_required_size());

	while (true) {
		IRTriple* current_triple = current_blk->get_all_triples()[current_blk_triple_index];

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
		// mutual block for all executor operations 
		case IROperation::INC:
		case IROperation::DEC:
		case IROperation::ADD:
		case IROperation::SUB:
		case IROperation::MUL:
		case IROperation::DIV:
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
			std::vector<uint8_t*> operand_addresses;
			std::vector<TypeRef> operand_types;
			
			operand_addresses.reserve(current_triple->m_operands.size());
			operand_types.reserve(current_triple->m_operands.size());

			for (const IROperand& operand : current_triple->m_operands ) {
				operand_addresses.push_back(get_operand_address(operand));
				operand_types.push_back(operand.get_data_type());
			}

			uint8_t* result_address = m_current_frame->m_memory_stack.data() + current_triple->get_local_mem_offset();

			m_operation_executor.execute_operation(
				current_triple->get_ir_operation(),
				operand_types,
				operand_addresses,
				current_triple->get_data_type(),
				result_address
			);
			
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_address;

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
			//IRFunction* out_fun = m_current_function;
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

			// TODO: restore the callback after implementing safe return-value passing
			// m_listener->function_call_end(out_fun,return_value_address);

			break;
		}
		case IROperation::JMP: {
			IROperand op = current_triple->m_operands[0];
			current_blk = std::get<IRBasicBlock*>(op.m_value);
			current_blk_triple_index = 0;
			continue;
		}
		case IROperation::JC: {

			uint8_t* value_addr = get_operand_address(current_triple->m_operands[0]);
			if (*value_addr) {
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
		case IROperation::PRINT_TYPE: {
			IROperand op = current_triple->m_operands[0];
			TypeRef type = op.get_data_type();
			std::string msg = type.to_string();
			m_listener->print_called(msg);

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
		case IROperation::ADREESS_OF: {
			IROperand op1 = current_triple->m_operands[0];
			uint8_t* op_1_addr = get_operand_address(op1);
			uint8_t* result_addr = &m_current_frame->m_memory_stack[0] + current_triple->get_local_mem_offset();
			int32_t* result = reinterpret_cast<int32_t*>(op_1_addr);

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
		case IROperation::MALLOC: {
			IROperand op_1 = current_triple->m_operands[0];
			uint8_t* op_1_addr = get_operand_address(op_1);
			uint8_t* result_addr = m_current_frame->m_memory_stack.data() + current_triple->get_local_mem_offset();
			ConstantValue value(op_1.get_data_type().get_ir_basic_type(),op_1_addr);

			auto opt = value.safe_convert_value_to<uint64_t>();
			if (opt.has_value()) {
				uint64_t result = opt.value();
				void * allocated_memory = malloc(result);
				std::cout << "Malloc allocated memory :" << (void*)allocated_memory << std::endl;
				*reinterpret_cast<void**>(result_addr) = allocated_memory;
				m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_addr;
			}

			break;
		}
		case IROperation::FREE: {
			IROperand op_1 = current_triple->m_operands[0];
			uint8_t* op_1_addr = get_operand_address(op_1);
			free(*(void**)(op_1_addr));
			break;
		}
		case IROperation::REINTERPRET_CAST:{
			uint8_t* op_2_addr = get_operand_address(current_triple->m_operands[1]);
			// nothing to do here 
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = op_2_addr;
			break;
		}
		case IROperation::CAST: {
			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];
			uint8_t* op_1_addr = get_operand_address(current_triple->m_operands[0]);
			uint8_t* op_2_addr = get_operand_address(current_triple->m_operands[1]);
			
			if (op1.get_data_type().is_basic_data_type()) {
				ConstantValue value{op2.get_data_type().remove_reference().get_ir_basic_type(),op_2_addr};
				ConstantValue casted_value = value.unsafe_convert(op1.get_data_type().get_ir_basic_type());
				uint8_t* result_addr = m_current_frame->m_memory_stack.data() + current_triple->get_local_mem_offset();
				memcpy(result_addr,casted_value.get_address(),op1.get_data_type().get_size());
				m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_addr;
			}
			else
				m_current_frame->m_triple_addresses[current_triple->get_global_index()] = op_2_addr;

			break;
		}
		case IROperation::COPY: {
			IROperand op1 = current_triple->m_operands[0];
			uint8_t* op_1_addr = get_operand_address(op1);
			uint8_t* result_addr = m_current_frame->m_memory_stack.data() + current_triple->get_local_mem_offset();
			memcpy(result_addr,op_1_addr,op1.get_data_type().get_size());
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_addr;
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