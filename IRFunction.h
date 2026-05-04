
class IRFunction {
private:
	friend class IRBasicBlock;
	friend class IRProgram;
	friend class IRChecker;
	friend class IRCoder;
	std::string m_identifier;
	IRProgram* m_ir_program = nullptr;
	// inside of the function we remember how many triples we have
	size_t m_triple_count;
	size_t m_index;
	std::vector<IRBasicBlock*> m_basic_blocks;
	std::vector<IRConstant*> m_constants;
	std::vector<IRVariable*> m_variables;
	std::vector<IRVariable*> m_parameters;
	TypeRef m_return_type;
public:
	//IRFunction* IRProgram::add_function(const std::string& name, const TypeRef& return_type, const std::vector<std::string>& l_param_names, const std::vector<IRBasicType>& l_param_types)
	IRFunction(size_t index) :m_triple_count{ 0 }, m_index{index} { m_basic_blocks.push_back(new IRBasicBlock{ this, m_basic_blocks.size() }); }
	IRFunction(size_t index, const std::string& name, const TypeRef& r_t,IRProgram * p) : m_triple_count{ 0 }, m_index{ index }, m_identifier{ name }, m_return_type{ r_t }, m_ir_program{p} { m_basic_blocks.push_back(new IRBasicBlock{ this, m_basic_blocks.size() }); }

	void add_parameter(const std::string& name, const TypeRef& type);
	IRVariable* add_variable(const std::string& name,const TypeRef& type);
	IRConstant* add_constant(const ConstantValue &cv);
	IRBasicBlock* add_basic_block();
	IRBasicBlock* add_basic_block(const std::string& name);
	IRBasicBlock* get_basic_blk(size_t index);
	const std::vector<IRBasicBlock*>& get_basic_blocks();
	const IRVariable* get_variable(size_t index) const;
	const std::vector<IRVariable*>& get_variables() const;
	IRVariable* get_variable(const std::string& name);

	const IRConstant* get_constant(size_t index) const;
	const std::vector<IRConstant*>& get_constants() const;
	bool has_variable(const std::string& name) const;
	//void check_function();
	void set_checker_listener(IRCheckerListener* listener);
	size_t get_triple_count();
	//IRBasicType get_return_type();
	const TypeRef& get_return_type() const;
	void set_name(const std::string& name);
	const std::string& get_name();
	const std::vector<IRVariable*>& get_parameters();
	// SHOW
	bool compare_arguments(const std::vector<IROperand> &arguments);
	size_t get_index();
};
