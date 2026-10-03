

class IRProgram {
private:
	std::vector<IRGlobalVariable*> m_global_variables;
	std::unordered_map<std::string,std::vector<IRFunction*>> m_functions;
	std::unordered_map<std::string,std::vector<IRExternalFunction*>> m_external_fns;
	IRChecker m_checker;
	IRDataTypeManager m_dtm;
	StringLiteralPool m_string_literals;
public:
	size_t m_required_for_global_variables;
	IRProgram();
	void add_external_function(const std::string& name, IRExternalFunction* external_fn);
	IRFunction* add_function(const std::string& name, bool is_in, const TypeRef& return_type, const std::vector<std::string>& l_param_names, const std::vector<TypeRef>& l_param_types);
	void set_checker_listener(IRCheckerListener* listener);
	void check_program();
	const std::unordered_map<std::string,std::vector<IRFunction*>>& get_functions() const;
	std::vector<IRBaseFunction*> get_functions_with_name(const std::string& name) const;
	//IRFunction* get_function(const std::string &name,const std::vector<IROperand> &arguments);
	IRFunction* get_function(const std::string &name,const std::vector<TypeRef> &argument_types);
	IRExternalFunction* get_external_function(const std::string& name, const std::vector<TypeRef>& arguments);
	//IRExternalFunction* get_external_function(const std::string &name,const std::vector<IROperand> &arguments);
	IRGlobalVariable* add_variable(const std::string& name,const TypeRef& type);
	IRGlobalVariable* get_variable(const std::string& name);
	void calculate_required_size_for_all_fns();
	void calculate_size_required_for_fn(IRFunction* fn);
	const std::vector<IRGlobalVariable*>& get_global_variables() const;
	IRDataTypeManager* get_dtm_manager();
	IRChecker* get_ir_checker();
	void calculate_memory_layout();
	size_t calculate_size_required_for_global_variables();
	StringRef get_or_add_string_literal(const std::string& text);
};