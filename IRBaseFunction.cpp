
IRBaseFunction::IRBaseFunction(const std::string& name, const std::vector<TypeRef>& types, const TypeRef& return_type, Kind kind) : m_identifier{ name }, m_parameter_types{ types }, m_return_type{ return_type }, m_kind{kind} {}

const std::string& IRBaseFunction::get_name() const { return m_identifier; }

const std::vector<TypeRef> IRBaseFunction::get_parameter_types() const {
	return m_parameter_types;
}

bool IRBaseFunction::compare_arguments(const std::vector<TypeRef>& argument_types) {
	auto parameter_types = get_parameter_types();
	if (parameter_types.size() != argument_types.size())
		return false;

	for (size_t i = 0; i < argument_types.size(); i++) {
		if (parameter_types[i].remove_reference() != argument_types[i].remove_reference())
			return false;
	}

	return true;
}

const TypeRef IRBaseFunction::get_return_type() const { return m_return_type; }