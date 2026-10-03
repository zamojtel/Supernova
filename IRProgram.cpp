
// For testing 
extern "C" __declspec(dllexport) int function(int x) {
	return x + 1;
}

extern "C" __declspec(dllexport) void print_float(float val) {
	std::cout << val << std::endl;
}

extern "C" __declspec(dllexport) void print_int(int val) {
	std::cout << val << std::endl;
}

IRProgram::IRProgram(): m_checker{ this } {
	std::vector<TypeRef> paramaters{ m_dtm.get_int()};
	std::string name = "function";
	add_external_function(name, new IRExternalFunction{ name, function,m_dtm.get_int(), paramaters,
		[](void** args,void* result_address) {
			*reinterpret_cast<int*>(result_address) = function(*reinterpret_cast<int*>(args[0]));
			} 
		}
	);

	std::vector<TypeRef> paramaters_print_float{ m_dtm.get_float()};
	name = "print_float";
	add_external_function(name, new IRExternalFunction{ name, print_float,m_dtm.get_void(), paramaters_print_float,
		[](void** args,void* result_address) {
				print_float(*reinterpret_cast<float*>(args[0]));
			} 
		}
	);

	std::vector<TypeRef> paramaters_print_int{ m_dtm.get_int()};
	name = "print_int";
	add_external_function(name, new IRExternalFunction{ name, print_int,m_dtm.get_void(), paramaters_print_int,
		[](void** args,void* result_address) {
				print_int(*reinterpret_cast<int*>(args[0]));
			} 
		}
	);
}

IRDataTypeManager* IRProgram::get_dtm_manager() { return &m_dtm; }

IRChecker* IRProgram::get_ir_checker() { return &m_checker; }

void IRProgram::add_external_function(const std::string& name,IRExternalFunction* external_fn) {
	m_external_fns[name].push_back(external_fn);
}

IRFunction* IRProgram::add_function(const std::string& name,bool is_in,const TypeRef& return_type, const std::vector<std::string>& l_param_names, const std::vector<TypeRef>& l_param_types) {
	if (l_param_names.size() != l_param_types.size())
		throw std::runtime_error("number of parameters is different from number of types passed");

	IRFunction* ir_function = new IRFunction{m_functions.size(), name,is_in,return_type,this};
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

const std::unordered_map<std::string, std::vector<IRFunction*>>& IRProgram::get_functions() const {
	return m_functions;
}

std::vector<IRBaseFunction*> IRProgram::get_functions_with_name(const std::string& name) const {
	std::vector<IRBaseFunction*> functions;
	auto it = m_functions.find(name);
	if (it!=m_functions.end())
		functions.insert(functions.end(), it->second.begin(), it->second.end());

	auto it2 = m_external_fns.find(name);
	if (it2 != m_external_fns.end())
		functions.insert(functions.end(),it2->second.begin(),it2->second.end());

	return functions;
}

void IRProgram::calculate_memory_layout() {
	m_required_for_global_variables = calculate_size_required_for_global_variables();
	calculate_required_size_for_all_fns();
}

void IRProgram::calculate_required_size_for_all_fns() {
	auto fns_map = get_functions();

	for(auto &[name,fns] : fns_map){
		for (size_t i = 0; i < fns.size();i++) {
			calculate_size_required_for_fn(fns[i]);
		}
	}
}

void IRProgram::calculate_size_required_for_fn(IRFunction* fn) {
	std::vector<IRBasicBlock*> blks = fn->get_basic_blocks();
	std::vector<IRVariable*> params = fn->get_parameters();
	size_t total_size_required = 0;
	size_t current_offset = 0;

	std::vector<IRVariable*> local_variables = fn->get_variables();
	for (size_t i = 0; i < local_variables.size(); i++) {
		TypeRef ref = local_variables[i]->get_data_type();
		size_t size_in_bytes = ref.get_size();
		local_variables[i]->m_local_mem_offset = current_offset;
		current_offset += size_in_bytes;

		total_size_required += size_in_bytes;
	}

	current_offset = total_size_required;

	for (size_t i = 0; i < blks.size(); i++) {
		auto* blk = blks[i];
		std::vector<IRTriple*> all_triples = blk->get_all_triples();
		for (size_t j = 0; j < all_triples.size(); j++) {
			IRTriple* current_triple = all_triples[j];
			TypeRef type = current_triple->get_data_type();
			if (type && type.has_size()) {
				size_t size_in_bytes = type.get_size();
				current_triple->m_local_mem_offset = current_offset;
				current_offset += size_in_bytes;
			}
		}
	}

	fn->m_total_size_required = current_offset;
}

StringRef IRProgram::get_or_add_string_literal(const std::string& text) {
	return m_string_literals.get_or_add(text);
}

size_t IRProgram::calculate_size_required_for_global_variables() {
	size_t current_offset = 0;
	for (size_t i = 0; i < m_global_variables.size();i++) {
		size_t size = m_global_variables[i]->get_data_type().get_size();
		m_global_variables[i]->m_local_mem_offset = current_offset;
		current_offset += size;
	}

	return current_offset;
}

//IRFunction* IRProgram::get_function(const std::string& name, const std::vector<IROperand>& arguments) {
//	for (const auto& [fn_name,functions]: m_functions ) {
//		if (fn_name == name) {
//			for (size_t i = 0; i < functions.size(); i++) {
//				IRFunction* fn = functions[i];
//				// reminder as for now parameters can only be variables it has to be changed later
//				if (fn->compare_arguments(arguments))
//					return fn;
//			}
//		}
//	}
//
//	return nullptr;
//}

IRFunction* IRProgram::get_function(const std::string& name, const std::vector<TypeRef>& argument_types) {
	for (const auto& [fn_name,functions]: m_functions ) {
		if (fn_name == name) {
			for (size_t i = 0; i < functions.size(); i++) {
				IRFunction* fn = functions[i];
				// reminder as for now parameters can only be variables it has to be changed later
				if (fn->compare_arguments(argument_types))
					return fn;
			}
		}
	}

	return nullptr;
}

IRExternalFunction* IRProgram::get_external_function(const std::string& name, const std::vector<TypeRef>& argument_types) {
	for (const auto& [fn_name, functions] : m_external_fns) {
		if (fn_name == name) {
			for (size_t i = 0; i < functions.size(); i++) {
				IRExternalFunction* fn = functions[i];
				if (fn->compare_arguments(argument_types))
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