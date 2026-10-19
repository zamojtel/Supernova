
// For testing 
// move somewhere else 
extern "C" __declspec(dllexport) int function(int x) {
	return x + 1;
}

template <class T>
void print(T value) {
	ConstantValue cv{value};
	Tester::get_message_collector().print_called(cv.to_string());
	std::cout << value << std::endl;
}

void print_string(const char * str) {
	std::string message{ str };
	if (str!="") {
		Tester::get_message_collector().print_called(message);
	}
	else {
		Tester::get_message_collector().print_called("!empty string!");
	}
}

void print_char_array(const char* data,size_t count) {
	std::string message;

	for (size_t i = 0; i < count && data[i] != '\0';i++)
		message.push_back(data[i]);
	
	Tester::get_message_collector().print_called(message);
}

template <class T>
void print_type(T value) {
	if constexpr (std::is_same_v<T, int8_t>) {
		Tester::get_message_collector().print_called("int8");
	}
	else if constexpr (std::is_same_v<T, char>) {
		Tester::get_message_collector().print_called("char");
	}
	else if constexpr (std::is_same_v<T, int16_t>) {
		Tester::get_message_collector().print_called("int16");
	}
	else if constexpr (std::is_same_v<T, int32_t>) {
		Tester::get_message_collector().print_called("int32");
	}
	else if constexpr (std::is_same_v<T, int64_t>) {
		Tester::get_message_collector().print_called("int64");
	}
	else if constexpr (std::is_same_v<T, float>) {
		Tester::get_message_collector().print_called("float");
	}
	else if constexpr (std::is_same_v<T, double>) {
		Tester::get_message_collector().print_called("double");
	}
	else if constexpr (std::is_same_v<T, uint8_t>) {
		Tester::get_message_collector().print_called("uint8");
	}
	else if constexpr (std::is_same_v<T, uint16_t>) {
		Tester::get_message_collector().print_called("uint16");
	}
	else if constexpr (std::is_same_v<T, uint32_t>) {
		Tester::get_message_collector().print_called("uint32");
	}
	else if constexpr (std::is_same_v<T, uint64_t>) {
		Tester::get_message_collector().print_called("uint64");
	}
}

template <class T>
void print_array(const T* array, size_t size) {
	std::string msg = "[";

	for (size_t i = 0; i < size; i++) {
		if (i != 0)
			msg += ",";
		ConstantValue value = ConstantValue{array[i]};
		msg += value.to_string();
	}

	msg += "]";

	Tester::get_message_collector().print_called(msg);
}

IRProgram::IRProgram() : m_checker{ this }, m_current_fn_index{0} {
	std::vector<TypeRef> paramaters{ m_dtm.get_int()};
	std::string name = "function";
	add_external_function(name, new IRExternalFunction{ 
		name,
		m_current_fn_index++,
		function,
		m_dtm.get_int(),
		paramaters,
		[](void** args,void* result_address) {
			*reinterpret_cast<int*>(result_address) = function(*reinterpret_cast<int*>(args[0]));
			} 
		}
	);

	add_external_function("malloc", new IRExternalFunction{
		"malloc",
		m_current_fn_index++,
		std::malloc,
		m_dtm.get_void_star(),
		{m_dtm.get_uint64()},
		[](void** args, void* result_address) {
			*reinterpret_cast<void**>(result_address) = std::malloc(
				*reinterpret_cast<uint64_t*>(args[0])
			);
		}
	});

	add_external_function("memcpy", new IRExternalFunction{
		"memcpy",
		m_current_fn_index++,
		std::memcpy,
		m_dtm.get_void_star(),
		{
			m_dtm.get_void_star(),
			m_dtm.get_void_const_star(),
			m_dtm.get_uint64()
		},
		[](void** args, void* result_address) {
			const char * str = *((const char**) args[1]);
			uint64_t size = *((uint64_t *) args[2]);
			std::cout << str << std::endl;
			std::cout << size << std::endl;

			*reinterpret_cast<void**>(result_address) = std::memcpy(
				*reinterpret_cast<void**>(args[0]),
				*reinterpret_cast<const void**>(args[1]),
				*reinterpret_cast<uint64_t*>(args[2])
			);
		}
	});

	add_external_function("free", new IRExternalFunction{
		"free",
		m_current_fn_index++,
		std::free,
		m_dtm.get_void(),
		{m_dtm.get_void_star()},
		[](void** args, void* result_address) {
			std::free(*reinterpret_cast<void**>(args[0]));
		}
	});

}

IRDataTypeManager* IRProgram::get_dtm_manager() { return &m_dtm; }

IRChecker* IRProgram::get_ir_checker() { return &m_checker; }

void IRProgram::add_external_function(const std::string& name,IRExternalFunction* external_fn) {
	m_external_fns[name].push_back(external_fn);
}

IRFunction* IRProgram::add_function(const std::string& name,bool is_in,const TypeRef& return_type, const std::vector<std::string>& l_param_names, const std::vector<TypeRef>& l_param_types) {
	if (l_param_names.size() != l_param_types.size())
		throw std::runtime_error("number of parameters is different from number of types passed");

	IRFunction* ir_function = new IRFunction{m_current_fn_index, name,is_in,return_type,this};
	m_current_fn_index++;
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
const std::unordered_map<std::string, std::vector<IRExternalFunction*>>& IRProgram::get_external_functions() const {
	return m_external_fns;
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

void IRProgram::sort_blocks() {
	for (auto &[name,functions] : m_functions) {
		
		for (IRFunction* fn : functions) {
			IRBasicBlock* starting_blk = fn->get_basic_blk(0);
			int number_of_blocks = fn->get_basic_blocks().size();
			std::vector<bool> visited(number_of_blocks,false);
			std::queue<IRBasicBlock*> queue;
			std::vector<IRBasicBlock*> traversal_order;
			queue.push(starting_blk);
			traversal_order.push_back(starting_blk);

			visited[starting_blk->get_index()] = true;
			while (!queue.empty()) {

				IRBasicBlock* current_blk = queue.front();
				queue.pop();

				for (IRBasicBlock* successor : current_blk->get_successors()) {
					if (!visited[successor->get_index()]) {
						visited[successor->get_index()] = true;
						traversal_order.push_back(successor);
						queue.push(successor);
					}
				}
			}

			for (size_t i = 0; i < traversal_order.size();i++)
				traversal_order[i]->set_index(i);

			fn->m_basic_blocks = std::move(traversal_order);
		}
	}
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