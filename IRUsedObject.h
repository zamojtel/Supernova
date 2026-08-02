

class IRUsedObject {
private:
	friend class IRTriple;
	std::vector<IRUseSite*> m_use_sites;
	void add_use_site(IRTriple *triple,size_t index);
	void remove_use_site(IRTriple* triple, size_t index);
public:
	void replace_all_usages(IRUsedObject *other);
	virtual ~IRUsedObject() = default;
	virtual IROperandType get_operand_type() const = 0;
	virtual IROperand get_operand() = 0;
	bool is_used();
};