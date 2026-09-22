
std::array<const IRDataTypeTraits,(size_t)IRBasicType::NUMBER_OF_TYPES> ir_data_type_traits{
	{
		IRDataTypeTraits{ 1 }, // 0 
		IRDataTypeTraits{ 2 }, // 1 
		IRDataTypeTraits{ 4 }, // 2 
		IRDataTypeTraits{ 8 }, // 3
		IRDataTypeTraits{ 1 }, // 4
		IRDataTypeTraits{ 2 }, // 5 
		IRDataTypeTraits{ 4 }, // 6
		IRDataTypeTraits{ 8 }, // 7 
		IRDataTypeTraits{ 4 }, // 8 FLOAT
		IRDataTypeTraits{ 8 }, // 9 DOUBLE
		IRDataTypeTraits{ 1 }, // 10 BOOL UNKNOWN
		// IRDataTypeTraits{ 1 }, // 11 STRING UNKNOWN
		IRDataTypeTraits{ 0 }, // 12 ERROR KNOWN
		//IRDataTypeTraits{ 0 }, // 13 VOID KNOWN
	}
};

bool IRDataTypeTraits::can_implicitly_convert(const TypeRef& from,const TypeRef& to) {
	
	if (from.remove_reference().remove_qualifiers().is_array())
		return can_implicitly_convert_array_to_pointer(from, to);

	if (from.is_pointer())
		return can_implicitly_convert_pointers(from,to);

	const TypeRef from_value = from.remove_qualifiers();
	const TypeRef to_value = to.remove_qualifiers();

	if (from_value.is_basic_data_type() && to_value.is_basic_data_type())
		return can_implicitly_convert_basic_types(from_value.get_ir_basic_type(),to_value.get_ir_basic_type());
	
	return false;
}

bool IRDataTypeTraits::can_implicitly_convert_pointers(const TypeRef& from ,const TypeRef& to) {
	if (from==to)
		return true;

	if (to.is_nullptr())
		return false;

	if (from.is_nullptr())
		return true;

	TypeRef from_inner_type = from.remove_pointer();
	TypeRef to_inner_type = to.remove_pointer();

	if (from_inner_type.is_const() && !to_inner_type.is_const())
		return false;
	
	if (from_inner_type.is_volatile() && !to_inner_type.is_volatile())
		return false;

	from_inner_type = from_inner_type.remove_qualifiers();
	to_inner_type = to_inner_type.remove_qualifiers();
	
	if (to_inner_type.is_void())
		return true;
	
	if (from_inner_type == to_inner_type)
		return true;

	return false;
}

bool IRDataTypeTraits::can_implicitly_convert_basic_types(IRBasicType from, IRBasicType to) {
	if (from == to)
		return true;

	switch (from)
	{
	case IRBasicType::INT8: {
		if (to == IRBasicType::INT16 || to == IRBasicType::INT32 || to == IRBasicType::INT64 || to == IRBasicType::FLOAT || to == IRBasicType::DOUBLE)
			return true;
		return false;
	}
	case IRBasicType::INT16: {
		if (to == IRBasicType::INT32 || to == IRBasicType::INT64 || to == IRBasicType::FLOAT || to == IRBasicType::DOUBLE)
			return true;
		return false;
	}
	case IRBasicType::INT32: {
		if (to == IRBasicType::INT64 || to == IRBasicType::FLOAT || to == IRBasicType::DOUBLE)
			return true;
		return false;
	}
	case IRBasicType::UINT8:
	{
		if (to == IRBasicType::UINT16 || to == IRBasicType::UINT32 || to == IRBasicType::UINT64 || to == IRBasicType::INT16 || to == IRBasicType::INT32 || to == IRBasicType::INT64 || to == IRBasicType::FLOAT || to == IRBasicType::DOUBLE)
			return true;
		return false;
	}
	case IRBasicType::UINT16: {
		if (to == IRBasicType::UINT32 || to == IRBasicType::UINT64 || to == IRBasicType::INT32 || to == IRBasicType::INT64 || to == IRBasicType::FLOAT || to == IRBasicType::DOUBLE)
			return true;
		return false;
	}
	case IRBasicType::UINT32: {
		if (to == IRBasicType::INT64 || to == IRBasicType::UINT64 || to == IRBasicType::FLOAT || to == IRBasicType::DOUBLE)
			return true;
		return false;
	}
	case IRBasicType::FLOAT:
		if (to == IRBasicType::DOUBLE)
			return true;
		return false;
	case IRBasicType::INT64:
	case IRBasicType::UINT64:
	{
		if (to == IRBasicType::FLOAT || to == IRBasicType::DOUBLE)
			return true;
		return false;
	}
	case IRBasicType::DOUBLE:
	case IRBasicType::BOOL:
	case IRBasicType::VOID:
	case IRBasicType::STRING:
		return false;
	case IRBasicType::NUMBER_OF_TYPES:
		break;
	default:
		throw std::runtime_error("there's no such basic type");
	}
	return false;
}

bool IRDataTypeTraits::can_explicitly_convert(const IROperand& op,const TypeRef& to) {
	const TypeRef& from_value = op.get_data_type().remove_reference().remove_qualifiers();
	const TypeRef& to_value = to.remove_reference().remove_qualifiers();

	// for now we forbid to cast string to anything else
	if (from_value.is_string() || to_value.is_string())
		return false;

	return true;
}

bool IRDataTypeTraits::can_implicitly_convert_array_to_pointer(const TypeRef& from, const TypeRef& to) {
	if (to.is_reference())
		return false;

	const TypeRef source = from.remove_reference().remove_qualifiers();
	const TypeRef target = to.remove_qualifiers();

	if (!source.is_array() || !target.is_pointer())
		return false;

	const TypeRef element_type = source.remove_array();

	IRDataTypeManager *dtm = from.get_data_type_node()->get_dtm();

	const TypeRef pointer_type = dtm->add_pointer(element_type);

	return can_implicitly_convert_pointers(pointer_type,target);

}

bool IRDataTypeTraits::can_implicitly_convert_argument(const IROperand& argument, const TypeRef& to) {
	if (to.is_reference()) {
		if (argument.m_operand_type != IROperandType::VARIABLE)
			return false;

		const TypeRef argument_type = argument.get_data_type().remove_reference();
		const TypeRef target_reference_type = to.remove_reference();
		return argument_type == target_reference_type;
	}

	if (can_implicitly_convert(argument.get_data_type(),to))
		return true;

	if (!argument.is_constant() || !to.is_basic_data_type())
		return false;

	const ConstantValue cv = argument.get_constant()->get_value();

	IRBasicType source_type = argument.get_data_type().get_ir_basic_type();
	IRBasicType target_type = to.get_ir_basic_type();

	if (source_type == IRBasicType::INT32) {
		switch (target_type)
		{
		case IRBasicType::INT8:
			return cv.safe_convert_value_to<int8_t>().has_value();
		case IRBasicType::UINT8:
			return cv.safe_convert_value_to<uint8_t>().has_value();
		case IRBasicType::INT16:
			return cv.safe_convert_value_to<int16_t>().has_value();
		case IRBasicType::UINT16:
			return cv.safe_convert_value_to<uint16_t>().has_value();
		case IRBasicType::UINT32:
			return cv.safe_convert_value_to<uint32_t>().has_value();
		case IRBasicType::UINT64:
			return cv.safe_convert_value_to<uint64_t>().has_value();
		default:
			return false;
		}
	}

	if (source_type == IRBasicType::INT64 && target_type == IRBasicType::UINT64) 
		return cv.safe_convert_value_to<uint64_t>().has_value();

	return false;
}

bool IRDataTypeTraits::is_floating_point(IRBasicType type) {
	switch (type)
	{
	case IRBasicType::FLOAT:
	case IRBasicType::DOUBLE:
		return true;
	default:
		return false;
	}
}

bool IRDataTypeTraits::is_integer(IRBasicType type) {
	switch (type)
	{
	case IRBasicType::INT8:
	case IRBasicType::INT16:
	case IRBasicType::INT32:
	case IRBasicType::INT64:
	case IRBasicType::UINT8:
	case IRBasicType::UINT16:
	case IRBasicType::UINT32:
	case IRBasicType::UINT64:
		return true;
	default:
		return false;
	}
}

bool IRDataTypeTraits::is_boolean(IRBasicType type) {
	return type == IRBasicType::BOOL;
}

bool IRDataTypeTraits::is_unsigned(IRBasicType type) {
	switch (type)
	{
	case IRBasicType::UINT8:
	case IRBasicType::UINT16:
	case IRBasicType::UINT32:
	case IRBasicType::UINT64: {
		return true;
	}
	default:
		return false;
	}
}

bool IRDataTypeTraits::is_signed_integer(IRBasicType type) {
	return
		type == IRBasicType::INT8  ||
		type == IRBasicType::INT16 ||
		type == IRBasicType::INT32 ||
		type == IRBasicType::INT64;
}

std::string IRDataTypeTraits::get_name(const IRBasicType type) {
	switch (type)
	{
	case IRBasicType::FLOAT: {
		return "FLOAT";
	}
	case IRBasicType::DOUBLE: {
		return "DOUBLE";
	}
	case IRBasicType::UINT8: {
		return "UINT8";
	}
	case IRBasicType::UINT16: {
		return "UINT16";
	}
	case IRBasicType::UINT32: {
		return "UINT32";
	}
	case IRBasicType::UINT64: {
		return "UINT64";
	}
	case IRBasicType::INT8: {
		return "INT8";
	}
	case IRBasicType::INT16: {
		return "INT16";
	}
	case IRBasicType::INT32: {
		return "INT32";
	}
	case IRBasicType::INT64: {
		return "INT64";
	}
	case IRBasicType::BOOL: {
		return "BOOL";
	}
	case IRBasicType::VOID: {
		return "VOID";
	}
	default:
		throw std::runtime_error("data type not allowed");
	}
}