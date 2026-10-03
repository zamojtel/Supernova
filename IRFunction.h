
class IRFunction : public IRBaseFunction {
private:
	friend class IRBasicBlock;
	friend class IRProgram;
	friend class IRChecker;
	friend class IRCoder;
	bool m_is_inline{ false };
	IRProgram* m_ir_program = nullptr;
	// inside of the function we remember how many triples we have
	size_t m_triple_count;
	size_t m_index;
	std::vector<IRBasicBlock*> m_basic_blocks;
	std::vector<IRConstant*> m_constants;
	std::vector<IRVariable*> m_variables;
	std::vector<IRVariable*> m_parameters;
	TypeRef m_return_type;
	size_t m_total_size_required{ 0 };
public:
	IRFunction(size_t index,const std::string& name,const TypeRef& r_t);
	IRFunction(size_t index, const std::string& name, bool is_inline, const TypeRef& r_t, IRProgram* p);
	IROperandType get_operand_type() const override;
	IROperand get_operand() override;
	void add_parameter(const std::string& name, const TypeRef& type);
	IRVariable* add_variable(const std::string& name,const TypeRef& type);
	IRConstant* add_constant(const ConstantValue &cv);
	IRConstant* add_constant(const StringRef& str_ref);
	IRBasicBlock* add_basic_block();
	IRBasicBlock* add_basic_block(const std::string& name);
	IRBasicBlock* get_basic_blk(size_t index);
	const std::vector<IRBasicBlock*>& get_basic_blocks() const;
	const IRVariable* get_variable(size_t index) const;
	const std::vector<IRVariable*>& get_variables() const;
	IRVariable* get_variable(const std::string& name);
	const IRConstant* get_constant(size_t index) const;
	const std::vector<IRConstant*>& get_constants() const;
	bool has_variable(const std::string& name) const;
	void set_checker_listener(IRCheckerListener* listener);
	size_t get_triple_count();
	void reindex_triples();
	const TypeRef& get_return_type() const;
	void set_name(const std::string& name);
	const std::string& get_name();
	const std::vector<IRVariable*>& get_parameters() const;
	//bool compare_arguments(const std::vector<IROperand> &arguments);
	size_t get_index();
	size_t get_required_size();
	const std::string& get_identifier() const;
	IRProgram* get_ir_prgram();
	bool is_inline() const;
	void remove_blk(IRBasicBlock* blk);
	std::vector<TypeRef> get_paramater_type();
};
