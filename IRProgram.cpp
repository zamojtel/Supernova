
IRProgram::IRProgram(): m_checker{ this } {}

IRDataTypeManager* IRProgram::get_dtm_manager() { return &m_dtm; }

IRChecker* IRProgram::get_ir_checker() { return &m_checker; }

IRFunction* IRProgram::add_function(const std::string& name,const TypeRef& return_type, const std::vector<std::string>& l_param_names, const std::vector<TypeRef>& l_param_types) {
	if (l_param_names.size() != l_param_types.size())
		throw std::runtime_error("number of parameters is different from number of types passed");

	IRFunction* ir_function = new IRFunction{m_functions.size(), name,return_type,this};
	m_functions[name].push_back(ir_function);

	std::vector<IRVariable*> params;
	for (size_t i = 0; i < l_param_names.size();i++)
		ir_function->add_parameter(l_param_names[i],l_param_types[i]);

	return ir_function;
}

void IRProgram::set_checker_listener(IRCheckerListener* listener) {
	m_checker.set_listener(listener);
}

void IRProgram::check_program() {
	for (const auto& [fn_name, functions] : m_functions) {
		for (size_t i = 0; i < functions.size();i++) {
			m_checker.check_function(functions[i]);
		}
	}
}

const std::unordered_map<std::string, std::vector<IRFunction*>>& IRProgram::get_functions() {
	return m_functions;
}

IRFunction* IRProgram::get_function(const std::string& name, const std::vector<IROperand>& arguments) {
	for (const auto& [fn_name,functions]: m_functions ) {
		if (fn_name == name) {
			for (size_t i = 0; i < functions.size(); i++) {
				IRFunction* fn = functions[i];
				// reminder as for now parameters can only be variables it has to be changed later
				if (fn->compare_arguments(arguments))
					return fn;
			}
		}
	}

	return nullptr;
}

IRGlobalVariable* IRProgram::add_variable(const std::string& name,const TypeRef& type) {
	IRGlobalVariable* variable = new IRGlobalVariable{ name,type,m_global_variables.size() };
	m_global_variables.push_back(variable);
	return variable;
};

IRGlobalVariable* IRProgram::get_variable(const std::string& name){
	for (size_t i = 0; i < m_global_variables.size(); i++) {
		if (m_global_variables[i]->get_variable_name() == name)
			return m_global_variables[i];
	}

	return nullptr;
}

const std::vector<IRGlobalVariable*>& IRProgram::get_global_variables() const {
	return m_global_variables;
}