class IRFunction;

class IRBasicBlock : public IRUsedObject {
private:
	friend class IRCoder;
	friend class IRInliner;
	size_t m_index;
	std::vector<IRTriple*> m_triples;
	IRFunction * m_current_function;
	std::string m_name;
	// change to unordered_map
	std::map<IRBasicBlock*,int> m_successors;
	std::map<IRBasicBlock*,int> m_predecessors;
public:
	IRBasicBlock(IRFunction* c_f, size_t i) : m_current_function{ c_f }, m_index{ i }, m_name{""} {}
	IRBasicBlock(IRFunction* c_f, size_t i, const std::string& name) : m_current_function{ c_f }, m_index{ i }, m_name{name} {}
	IRBasicBlock* add_basic_block(const std::string& name);
	bool check_operand_types(const IROperand& op1, const IROperand& op2) const;
	size_t get_index() const { return m_index; }
	size_t get_number_of_operands_for_operation(IROperation op);
	void deduce_triple_data_type(IRTriple* triple);
	const std::vector<IRTriple*>& get_all_triples();
	size_t get_number_of_triples();
	IRFunction* get_function() const;
	std::string get_basic_blk_name();
	void remove_triple(IRTriple *triple);
	void add_successor(IRBasicBlock* blk);
	void remove_successor(IRBasicBlock* blk);
	std::vector<IRBasicBlock*> get_successors() const;
	std::vector<IRBasicBlock*> get_predecessors() const;
	void merge_blocks(IRBasicBlock* blk);
	IROperandType get_operand_type() const;
	IROperand get_operand() override;
	void clear();
};