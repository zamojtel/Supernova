
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
	if (type == IRBasicType::BOOL)
		return true;
	else
		return false;
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

bool IRDataTypeTraits::is_signed(IRBasicType type) {
	return !is_unsigned(type);
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
	//case IRBasicType::STRING: {
	//	return "STRING";
	//}
	//case IRBasicType::ERROR: {
	//	return "ERROR";
	//}
	case IRBasicType::VOID: {
		return "VOID";
	}
	default:
		throw std::runtime_error("data type not allowed");
	}
}