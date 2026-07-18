

std::string ErrorTraits::get_name(ErrorType type) {
	switch (type)
	{
	case ErrorType::SYNTAX_ERROR: {
		return "SYNTAX_ERROR";
	}
	case ErrorType::IMPLICIT_CAST_NOT_ALLOWED: {
		return "IMPLICIT_CAST_NOT_ALLOWED";
	}
	case ErrorType::TYPE_NOT_DEFINED: {
		return "IMPLICIT_CAST_NOT_ALLOWED";
	}
	case ErrorType::UNKNOWN_ERROR: {
		return "UNKNOWN_ERROR";
	}
	case ErrorType::ERROR_COUNT:
		return "ERROR_COUNT";
	default:
		throw std::runtime_error("type not found");
		break;
	}
}

ErrorType ErrorTraits::get_type(const std::string& type) {
	// TODO modify later
	return ErrorType{ 0 };
}