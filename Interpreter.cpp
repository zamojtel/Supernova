
Interpreter::Interpreter(IRProgram* p, IRFunction* fn, std::vector<IROperand>& fn_arguments) :m_ir_program{ p }, m_current_function{ fn }, m_fn_arguments{ fn_arguments } {
	m_global_variables.resize(p->get_global_variables().size());
	//IRFunction* get_function(const std::string & name, const std::vector<IROperand> &arguments);
	m_meomory_for_gl_variables.resize(p->get_function("_global_function", {})->get_required_size());
}

void Interpreter::set_listener(IRInterpreterListener* l) {
	m_listener = l;
}

uint8_t* Interpreter::get_operand_address(IROperand op) {
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
		size_t index = op.get_variable()->get_index();

		if (variable->is_global()) {
			throw std::runtime_error("dont use global");
		}
		else {
			size_t offset = variable->get_local_mem_offset();
			return &m_current_frame->m_memory_stack[0] + offset;
			//return m_current_frame->m_local_variables[index];
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

	//std::cout << "Offsets for variables " << std::endl;
	//for (size_t i = 0; i < variables.size();i++) {
	//	std::cout << variables[i]->get_variable_name() << " " << variables[i]->get_local_mem_offset() << std::endl;
	//}
	//auto blks = m_current_function->get_basic_blocks();
	//std::cout << "Offsets for triples " << std::endl;
	//for (auto blk :  blks) {
	//	for (auto *triple : blk->get_all_triples()) {
	//		std::cout <<"T"<<triple->get_global_index() << " " << triple->get_local_mem_offset() << std::endl;
	//	}
	//}
	//std::cout << std::endl;

	std::vector<IROperand> args;
	bool finished = false;
	IRBasicBlock* current_blk = basic_blks[0];
	int current_blk_triple_index = 0;

	m_current_frame = add_frame(current_blk, nullptr, m_current_function->get_triple_count(),m_current_function->get_variables().size(),m_current_function->get_required_size());
	
	//std::cout << "Memory Stack.data : " <<(void*) m_current_frame->m_memory_stack.data() << std::endl;
	while (true) {
		IRTriple* current_triple = current_blk->get_all_triples()[current_blk_triple_index];
		//CONSTANT
		switch (current_triple->get_ir_operation())
		{
		case IROperation::ASSIGN: {
			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];
			if (op2.m_operand_type == IROperandType::TRIPLE) {
				int x = 123;
			}

			uint8_t* addr1 = get_operand_address(op1);
			uint8_t* addr2 = get_operand_address(op2);
			//if (op2.m_operand_type==IROperandType::TRIPLE) {
			//	int32_t* value1 = reinterpret_cast<int32_t*>(addr1);
			//	int32_t** value2 = reinterpret_cast<int32_t**>(addr2);
			//	int32_t* value_2_inside = reinterpret_cast<int32_t*>(*value2);
			//	std::cout << " INSIDE ASSIGN First operand addr: " << value1 << std::endl;
			//	std::cout <<" INSIDE ASSIGN : "<< value_2_inside << " -> " <<*value_2_inside<< std::endl;
			//}
			//m_current_frame->m_triple_addresses
			int32_t* value1 = reinterpret_cast<int32_t*>(addr1);
			int32_t* value2 = reinterpret_cast<int32_t*>(addr2);

			TypeRef type = op1.get_data_type();
			size_t size = type.get_size();
			memcpy(addr1,addr2,size);

			//if (op2.m_operand_type == IROperandType::TRIPLE) {
			//	int32_t* value1 = reinterpret_cast<int32_t*>(addr1);
			//	int32_t** value2 = reinterpret_cast<int32_t**>(addr2);
			//	int32_t* value_2_inside = reinterpret_cast<int32_t*>(*value2);
			//	std::cout << " INSIDE ASSIGN : " << value_2_inside << " -> " << *value_2_inside << std::endl;
			//}

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
			TypeRef type = op1.get_data_type();
			size_t size_of_type = type.get_size();
		
			uint8_t* result_addr = &m_current_frame->m_memory_stack[0] + current_triple->get_local_mem_offset();
			execute_arithmetic_operation_on_addresses(type,current_triple->get_ir_operation(),addr1,addr2,result_addr);
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = result_addr;

			break;
		}
		case IROperation::LT:
		case IROperation::LE:
		case IROperation::GT:
		case IROperation::GE:
		case IROperation::EQ:
		case IROperation::NEQ: {
			//IROperation operation = current_triple->get_ir_operation();
			//IROperand op1 = current_triple->m_operands[0];
			//IROperand op2 = current_triple->m_operands[1];
			//ConstantValue cv1 = get_operand_value(op1);
			//ConstantValue cv2 = get_operand_value(op2);

			//size_t index = current_triple->get_global_index();
			//TypeRef type = current_triple->get_data_type();
			//ConstantValue value = execute_cmp_operation(operation, cv1, cv2);

			//m_current_frame->m_triple_values[index] = value;
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

			uint8_t* return_value_address = nullptr;
			if (current_triple->m_operands.size()>0) {
				IROperand op1 = current_triple->m_operands[0];
				return_value_address = get_operand_address(op1);
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

			m_current_frame = m_frames.size() > 1 ? &*(--(--m_frames.end())) : nullptr;
			if (m_current_frame) {
				m_current_frame->m_triple_addresses[triple_return_addr->get_global_index()] = return_value_address;
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
			m_listener;
			IROperand op = current_triple->m_operands[0];
			uint8_t* address = get_operand_address(op);
			std::cout << "address to be printed: " << reinterpret_cast<void*>(address) << std::endl;

			IRBasicType basic_type = op.get_data_type().get_ir_basic_type();
			ConstantValue value = ConstantValue{basic_type,address};
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
				auto value = get_operand_address(arguments[i]);
				TypeRef type = parameters[i]->get_data_type();
				size_t size = type.get_size();
				uint64_t result_offset = m_current_frame->m_memory_stack[0] + parameters[i]->get_local_mem_offset();
				memcpy(&m_frames.back().m_memory_stack[result_offset],value,size);
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
			IROperand op1 = current_triple->m_operands[0];
			IROperand op2 = current_triple->m_operands[1];
			// p[2]
			//if(op1.m_operand_type==)
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

			uint8_t* op_1_addr = get_operand_address(op1);
			size_t offset = op2.get_member()->get_offset();
			uint8_t* result_addr = op_1_addr + offset;
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
			//std::cout << "p address: " << *reinterpret_cast<void**>(op_1_addr) << std::endl;
			//std::cout << "under the address: " << **reinterpret_cast<uint32_t**>(op_1_addr) << std::endl;
			//std::cout << " INSIDE DEREFERENCE : " << *reinterpret_cast<void**>(op_1_addr) << " -> " << **reinterpret_cast<uint32_t**>(op_1_addr) << std::endl;
			m_current_frame->m_triple_addresses[current_triple->get_global_index()] = *reinterpret_cast<uint8_t**>(op_1_addr);
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