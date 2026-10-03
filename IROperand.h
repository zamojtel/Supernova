
class IRTriple;
class IRBasicBlock;
class IRBaseFunction;
class IRFunction;
class IRExternalFunction;

class IROperand {
private:
public:
	IROperandType m_operand_type;
	std::variant<IRBasicBlock*,IRConstant*, IRVariable*, IRTriple*,IRFunction*,IRExternalFunction*,IRMember*,TypeRef> m_value;

	IROperand();
	IROperand(IRBasicBlock* b);
	IROperand(IRConstant* c);
	IROperand(IRVariable* n);
	IROperand(IRTriple* t);
	IROperand(IRFunction* t);
	IROperand(IRExternalFunction* t);
	IROperand(IRMember* m);
	IROperand(IRUsedObject* obj);
	IROperand(const TypeRef& type);

	IRBasicBlock* get_basic_block() const;
	IRConstant* get_constant() const;
	IRVariable* get_variable() const;
	IRTriple* get_triple() const;
	IRFunction* get_function() const;
	IRExternalFunction* get_external_function() const;
	IRBaseFunction* get_base_function() const;
	IRMember* get_member() const;
	TypeRef get_data_type() const;
	IRUsedObject* get_used_object() const;
	bool is_constant() const;
	bool operator<(const IROperand& other) const;
};

std::ostream& operator<<(std::ostream& o, const IROperand& op);
