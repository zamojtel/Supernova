

class IRProgram {
private:
	std::vector<IRGlobalVariable*> m_global_variables;
	std::unordered_map<std::string,std::vector<IRFunction*>> m_functions;
	IRChecker m_checker;
	IRDataTypeManager m_dtm;
public:
	size_t m_required_for_global_variables;
	IRProgram();
	//void enumerate_triples();
	IRFunction* add_function(const std::string& name, bool is_in, const TypeRef& return_type, const std::vector<std::string>& l_param_names, const std::vector<TypeRef>& l_param_types);
	void set_checker_listener(IRCheckerListener* listener);
	void check_program();
	const std::unordered_map<std::string,std::vector<IRFunction*>>& get_functions() const;
	IRFunction* get_function(const std::string &name,const std::vector<IROperand> &arguments);
	IRGlobalVariable* add_variable(const std::string& name,const TypeRef& type);
	IRGlobalVariable* get_variable(const std::string& name);
	void calculate_required_size_for_all_fns();
	void calculate_size_required_for_fn(IRFunction* fn);
	const std::vector<IRGlobalVariable*>& get_global_variables() const;
	IRDataTypeManager* get_dtm_manager();
	IRChecker* get_ir_checker();
	void calculate_memory_layout();
	size_t calculate_size_required_for_global_variables();
};