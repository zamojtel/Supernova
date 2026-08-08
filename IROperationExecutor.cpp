
void IROperationExecutor::execute_operation(const IROperation operation,const std::vector<TypeRef>& operands_types,const std::vector<uint8_t*>& operands,const TypeRef& res_type, uint8_t* res_addr) {
	std::vector<ArrayIterator> iterators;
	for (size_t i = 0; i < operands.size();i++)
		iterators.push_back(ArrayIterator{operands[i],operands_types[i]});

	size_t size = 0;
	for (size_t i = 0; i < iterators.size();i++)
		size = std::max(size,iterators[i].get_count());

	ArrayIterator result_iter{ res_addr, res_type };

	switch (operation)
	{
		case IROperation::ADD:
		case IROperation::SUB:
		case IROperation::DIV:
		case IROperation::MUL:
		case IROperation::MOD:
		{
			for (size_t i = 0; i < size;i++) {
				execute_arithmetic_operation_on_addresses(iterators[0].get_element_type().remove_qualifiers(), operation, *iterators[0], *iterators[1], *result_iter);
				iterators[0].next();
				iterators[1].next();
				result_iter.next();
			}
			break;
		}
		case IROperation::LEFT_SHIFT:
		case IROperation::RIGHT_SHIFT:
		{
			for (size_t i = 0; i < size; i++) {
				execute_shift_operation(iterators[0].get_element_type().remove_qualifiers().get_ir_basic_type(), iterators[1].get_element_type().remove_qualifiers().get_ir_basic_type(), operation, *iterators[0], *iterators[1], *result_iter);
				iterators[0].next();
				iterators[1].next();
				result_iter.next();
			}
			break;
		}		
		case IROperation::BITWISE_AND:
		case IROperation::BITWISE_OR:
		case IROperation::BITWISE_XOR: {
			for (size_t i = 0; i < size;i++) {
				execute_bitwise_operation(iterators[0].get_element_type().remove_qualifiers().get_ir_basic_type(), operation, *iterators[0], *iterators[1], *result_iter);
				iterators[0].next();
				iterators[1].next();
				result_iter.next();
			}

			break;
		}
		case IROperation::BITWISE_NOT:
		case IROperation::UNARY_MINUS:
		case IROperation::INC:
		case IROperation::DEC:
		{
			for (size_t i = 0; i < size;i++) {
				execute_unary_operation(operation,iterators[0].get_element_type().get_ir_basic_type(),*iterators[0],*result_iter);
				iterators[0].next();
				result_iter.next();
			}

			break;
		}
		case IROperation::GT:
		case IROperation::GE:
		case IROperation::LT:
		case IROperation::LE:
		case IROperation::EQ:
		case IROperation::NEQ: {
			for (size_t i = 0; i < size; i++) {
				execute_cmp_operation_on_addresses(operation, iterators[0].get_element_type().remove_reference().remove_qualifiers(), *iterators[0], *iterators[1], *result_iter);
				iterators[0].next();
				iterators[1].next();
				result_iter.next();
			}
			break;
		}
		default:
			throw std::runtime_error("operation is not supported by IROperationExecutor");
			break;
	}
}

ConstantValue IROperationExecutor::execute_arithmetic_operation(const TypeRef& type, IROperation op, ConstantValue& cv1, ConstantValue& cv2) {
	ConstantValue value;

	switch (type.get_ir_basic_type())
	{
	case IRBasicType::INT8: {
		value = execute_arithmetic_operation(cv1.get_value<int8_t>(), cv2.get_value<int8_t>(), op);
		break;
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

void IROperationExecutor::execute_shift_operation(const IRBasicType& bt_1, const IRBasicType& bt_2, const IROperation operation, uint8_t* op1, uint8_t* op2, uint8_t* res_addr) {
	ConstantValue right_value(bt_2, op2);
	ConstantValue converted_value = right_value.safe_convert(IRBasicType::UINT64);

	switch (bt_1)
	{
	case IRBasicType::INT8: {
		exec_shift_operation<int8_t>(operation, op1, converted_value.get_value<uint64_t>(), res_addr);
		break;
	}
	case IRBasicType::INT16: {
		exec_shift_operation<int16_t>(operation, op1, converted_value.get_value<uint64_t>(), res_addr);
		break;
	}
	case IRBasicType::INT32: {
		exec_shift_operation<int32_t>(operation, op1, converted_value.get_value<uint64_t>(), res_addr);
		break;
	}
	case IRBasicType::INT64: {
		exec_shift_operation<int64_t>(operation, op1, converted_value.get_value<uint64_t>(), res_addr);
		break;
	}
	case IRBasicType::UINT8: {
		exec_shift_operation<uint8_t>(operation, op1, converted_value.get_value<uint64_t>(), res_addr);
		break;
	}
	case IRBasicType::UINT16: {
		exec_shift_operation<uint16_t>(operation, op1, converted_value.get_value<uint64_t>(), res_addr);
		break;
	}
	case IRBasicType::UINT32: {
		exec_shift_operation<uint32_t>(operation, op1, converted_value.get_value<uint64_t>(), res_addr);
		break;
	}
	case IRBasicType::UINT64: {
		exec_shift_operation<uint64_t>(operation, op1, converted_value.get_value<uint64_t>(), res_addr);
		break;
	}
	default:
		throw std::runtime_error("can't shift floating point type");
		break;
	}
}

void IROperationExecutor::execute_bitwise_operation(const IRBasicType& type, IROperation operation, const uint8_t* cv1, const uint8_t* cv2, uint8_t* res_addr) {
	switch (type)
	{
	case IRBasicType::INT8: {
		*reinterpret_cast<int8_t*>(res_addr) = execute_bitwise_operation<int8_t>(*reinterpret_cast<const int8_t*>(cv1), *reinterpret_cast<const int8_t*>(cv2), operation);
		break;
	}
	case IRBasicType::INT16: {
		*reinterpret_cast<int16_t*>(res_addr) = execute_bitwise_operation<int16_t>(*reinterpret_cast<const int16_t*>(cv1), *reinterpret_cast<const int16_t*>(cv2), operation);
		break;
	}
	case IRBasicType::INT32: {
		*reinterpret_cast<int32_t*>(res_addr) = execute_bitwise_operation<int32_t>(*reinterpret_cast<const int32_t*>(cv1), *reinterpret_cast<const int32_t*>(cv2), operation);
		break;
	}
	case IRBasicType::INT64: {
		*reinterpret_cast<int64_t*>(res_addr) = execute_bitwise_operation<int64_t>(*reinterpret_cast<const int64_t*>(cv1), *reinterpret_cast<const int64_t*>(cv2), operation);
		break;
	}
	case IRBasicType::UINT8: {
		*reinterpret_cast<uint8_t*>(res_addr) = execute_bitwise_operation<uint8_t>(*reinterpret_cast<const uint8_t*>(cv1), *reinterpret_cast<const uint8_t*>(cv2), operation);
		break;
	}
	case IRBasicType::UINT16: {
		*reinterpret_cast<uint16_t*>(res_addr) = execute_bitwise_operation<uint16_t>(*reinterpret_cast<const uint16_t*>(cv1), *reinterpret_cast<const uint16_t*>(cv2), operation);
		break;
	}
	case IRBasicType::UINT32: {
		*reinterpret_cast<uint32_t*>(res_addr) = execute_bitwise_operation<uint32_t>(*reinterpret_cast<const uint32_t*>(cv1), *reinterpret_cast<const uint32_t*>(cv2), operation);
		break;
	}
	case IRBasicType::UINT64: {
		*reinterpret_cast<uint64_t*>(res_addr) = execute_bitwise_operation<uint64_t>(*reinterpret_cast<const uint64_t*>(cv1), *reinterpret_cast<const uint64_t*>(cv2), operation);
		break;
	}
	default:
		throw std::runtime_error("bitwise operation requires an integer type");
	}
}

void IROperationExecutor::execute_arithmetic_operation_on_addresses(const TypeRef& type, IROperation op, const uint8_t* cv1, const uint8_t* cv2, uint8_t* res_addr) {

	switch (type.get_ir_basic_type())
	{
	case IRBasicType::INT8: {
		*reinterpret_cast<int8_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const int8_t*>(cv1), *reinterpret_cast<const int8_t*>(cv2), op);
		break;
	}
	case IRBasicType::INT16: {
		*reinterpret_cast<int16_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const int16_t*>(cv1), *reinterpret_cast<const int16_t*>(cv2), op);
		break;
	}
	case IRBasicType::INT32: {
		*reinterpret_cast<int32_t*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const int32_t*>(cv1), *reinterpret_cast<const int32_t*>(cv2), op);
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
		*reinterpret_cast<double*>(res_addr) = execute_arithmetic_operation(*reinterpret_cast<const double*>(cv1), *reinterpret_cast<const double*>(cv2), op);
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

void IROperationExecutor::execute_cmp_operation_on_addresses(IROperation op,const TypeRef& type,uint8_t* cv1,uint8_t* cv2,uint8_t* res_addr) {
	switch (type.get_ir_basic_type())
	{
	case IRBasicType::INT8: {
		*reinterpret_cast<bool*>(res_addr) = execute_cmp_operation(*reinterpret_cast<const int8_t*>(cv1), *reinterpret_cast<const int8_t*>(cv2), op);
		break;
	}
	case IRBasicType::INT16: {
		*reinterpret_cast<bool*>(res_addr) = execute_cmp_operation(*reinterpret_cast<const int16_t*>(cv1), *reinterpret_cast<const int16_t*>(cv2), op);
		break;
	}
	case IRBasicType::INT32: {
		*reinterpret_cast<bool*>(res_addr) = execute_cmp_operation(*reinterpret_cast<const int32_t*>(cv1), *reinterpret_cast<const int32_t*>(cv2), op);
		break;
	}
	case IRBasicType::INT64: {
		*reinterpret_cast<bool*>(res_addr) = execute_cmp_operation(*reinterpret_cast<const int64_t*>(cv1), *reinterpret_cast<const int64_t*>(cv2), op);
		break;
	}
	case IRBasicType::UINT8: {
		*reinterpret_cast<bool*>(res_addr) = execute_cmp_operation(*reinterpret_cast<const uint8_t*>(cv1), *reinterpret_cast<const uint8_t*>(cv2), op);
		break;
	}
	case IRBasicType::UINT16: {
		*reinterpret_cast<bool*>(res_addr) = execute_cmp_operation(*reinterpret_cast<const uint16_t*>(cv1), *reinterpret_cast<const uint16_t*>(cv2), op);
		break;
	}
	case IRBasicType::UINT32: {
		*reinterpret_cast<bool*>(res_addr) = execute_cmp_operation(*reinterpret_cast<const uint32_t*>(cv1), *reinterpret_cast<const uint32_t*>(cv2), op);
		break;
	}
	case IRBasicType::UINT64: {
		*reinterpret_cast<bool*>(res_addr) = execute_cmp_operation(*reinterpret_cast<const uint64_t*>(cv1), *reinterpret_cast<const uint64_t*>(cv2), op);
		break;
	}
	case IRBasicType::FLOAT: {
		*reinterpret_cast<bool*>(res_addr) = execute_cmp_operation(*reinterpret_cast<const float*>(cv1), *reinterpret_cast<const float*>(cv2), op);
		break;
	}
	case IRBasicType::DOUBLE: {
		*reinterpret_cast<bool*> (res_addr) = execute_cmp_operation(*reinterpret_cast<const double*>(cv1), *reinterpret_cast<const double*>(cv2), op);
		break;
	}
	case IRBasicType::BOOL: {
		*reinterpret_cast<bool*>(res_addr) = execute_cmp_operation(*reinterpret_cast<const bool*>(cv1), *reinterpret_cast<const bool*>(cv2), op);
		break;
	}
	case IRBasicType::VOID: {
		break;
	}
	default:
		break;
	}

}

ConstantValue IROperationExecutor::execute_cmp_operation(IROperation op, ConstantValue& cv1, ConstantValue& cv2) {
	ConstantValue value;

	switch (cv1.get_basic_type())
	{
	case IRBasicType::INT8: {
		value = execute_cmp_operation(cv1.get_value<int8_t>(), cv2.get_value<int8_t>(), op);
		break;
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

template <class T>
void IROperationExecutor::execute_unary_operation(IROperation operation, uint8_t* op1, uint8_t* res_addr) {
	if (operation == IROperation::UNARY_MINUS) {
		*reinterpret_cast<T*>(res_addr) = -(*reinterpret_cast<T*>(op1));
	}
	else if (operation == IROperation::BITWISE_NOT) {
		if constexpr (std::is_integral_v<T> && !std::is_same_v<T,bool>) {
			*reinterpret_cast<T*>(res_addr) = ~(*reinterpret_cast<T*>(op1));
		}
		else
			throw std::runtime_error("bitwise not requires an integer operand");
	}
	else if (operation == IROperation::INC) {
		if constexpr (!std::is_same_v<T, bool>)
			*reinterpret_cast<T*>(res_addr) = ++(*reinterpret_cast<T*>(op1));
		else
			throw std::runtime_error("cannot increment boolean type");
	}
	else if (operation == IROperation::DEC) {
		if constexpr (!std::is_same_v<T, bool>)
			*reinterpret_cast<T*>(res_addr) = --(*reinterpret_cast<T*>(op1));
		else
			throw std::runtime_error("cannot decrement boolean type");
	}
	else
		throw std::runtime_error("not allowed operation");
}

void IROperationExecutor::execute_unary_operation(IROperation operation, IRBasicType bt,uint8_t* op1,uint8_t* res_addr) {
	switch (bt)
	{
	case IRBasicType::INT8: {
		execute_unary_operation<int8_t>(operation,op1,res_addr);
		break;
	}
	case IRBasicType::INT16: {
		execute_unary_operation<int16_t>(operation, op1, res_addr);
		break;
	}
	case IRBasicType::INT32: {
		execute_unary_operation<int32_t>(operation, op1, res_addr);
		break;
	}
	case IRBasicType::INT64: {
		execute_unary_operation<int64_t>(operation, op1, res_addr);
		break;
	}
	case IRBasicType::UINT8: {
		execute_unary_operation<uint8_t>(operation, op1, res_addr);
		break;
	}
	case IRBasicType::UINT16: {
		execute_unary_operation<uint16_t>(operation, op1, res_addr);
		break;
	}
	case IRBasicType::UINT32: {
		execute_unary_operation<uint32_t>(operation, op1, res_addr);
		break;
	}
	case IRBasicType::UINT64: {
		execute_unary_operation<uint64_t>(operation, op1, res_addr);
		break;
	}
	case IRBasicType::FLOAT: {
		execute_unary_operation<float>(operation, op1, res_addr);
		break;
	}
	case IRBasicType::DOUBLE: {
		execute_unary_operation<double>(operation, op1, res_addr);
		break;
	}
	case IRBasicType::BOOL: {
		execute_unary_operation<bool>(operation, op1, res_addr);
		break;
	}
	default:
		break;
	}
}

template <class T>
void IROperationExecutor::exec_shift_operation(const IROperation operation, uint8_t* op1, uint64_t op2, uint8_t* res_addr) {
	if (operation == IROperation::LEFT_SHIFT)
		*(reinterpret_cast<T*>(res_addr)) = *(reinterpret_cast<T*>(op1)) << op2;
	else if (operation == IROperation::RIGHT_SHIFT)
		*(reinterpret_cast<T*>(res_addr)) = *(reinterpret_cast<T*>(op1)) >> op2;
}

template <class T>
bool IROperationExecutor::execute_cmp_operation(T v1, T v2, IROperation operation) { // ok
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

template <class T>
T IROperationExecutor::execute_arithmetic_operation(T val_1, T val_2, IROperation operation) {
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
	case IROperation::MOD:
	{
		if constexpr (std::is_integral_v<T> && !std::is_same_v<T, bool>) {
			if (val_2==0)
				throw std::runtime_error("cannot execute modulo division by 0");
			return val_1 % val_2;
		}
		else
			throw std::runtime_error("cannot execute mod operation on non integer values");
	}
	default:
		throw std::runtime_error("unsupported arithmetic operation");
	}
}

template <class T>
T IROperationExecutor::execute_bitwise_operation(T val_1, T val_2, IROperation operation) {
	switch (operation)
	{
	case IROperation::BITWISE_AND:
		return val_1 & val_2;
	case IROperation::BITWISE_OR:
		return val_1 | val_2;
	case IROperation::BITWISE_XOR: {
		return val_1 ^ val_2;
	}
	default:
		throw std::runtime_error("unsupported bitwise operation");
		break;
	}
}

template <class To>
std::optional<To> IROperationExecutor::convert_value_to(ConstantValue& v) const {
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