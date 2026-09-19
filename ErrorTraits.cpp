

std::string ErrorTraits::get_name(ErrorType type) {
	switch (type)
	{
	case ErrorType::SYNTAX_ERROR:
		return "SYNTAX_ERROR";
	case ErrorType::IMPLICIT_CAST_NOT_ALLOWED:
		return "IMPLICIT_CAST_NOT_ALLOWED";
	case ErrorType::EXPLICIT_CAST_NOT_ALLOWED:
		return "EXPLICIT_CAST_NOT_ALLOWED";
	case ErrorType::TYPE_NOT_DEFINED:
		return "TYPE_NOT_DEFINED";
	case ErrorType::UNKNOWN_ERROR:
		return "UNKNOWN_ERROR";
	case ErrorType::ERROR_COUNT:
		return "ERROR_COUNT";
	case ErrorType::NO_RETURN_ERROR:
		return "NO_RETURN_ERROR";
	case ErrorType::INVALID_OPERAND_TYPE:
		return "INVALID_OPERAND_TYPE";
	case ErrorType::NO_MATCHING_FUNCTION:
		return "NO_MATCHING_FUNCTION";
	case ErrorType::AMBIGUOUS_FUNCTION_CALL:
		return "AMBIGUOUS_FUNCTION_CALL";
	case ErrorType::INTEGER_TYPE_REQUIRED:
		return "INTEGER_TYPE_REQUIRED";
	case ErrorType::BOOL_TYPE_REQUIRED:
		return "BOOL_TYPE_REQUIRED";
	case ErrorType::POINTER_TYPE_REQUIRED:
		return "POINTER_TYPE_REQUIRED";
	case ErrorType::TYPE_MISMATCH:
		return "TYPE_MISMATCH";
	case ErrorType::TYPE_SIZE_MISTMATCH:
		return "TYPE_SIZE_MISTMATCH";
	case ErrorType::INCOMPATIBLE_ARRAY_SIZES:
		return "INCOMPATIBLE_ARRAY_SIZES";
	default:
		throw std::runtime_error("type not found");
	}
}

ErrorType ErrorTraits::get_type(const std::string& type) {
	// TODO modify later
	return ErrorType{ 0 };
}