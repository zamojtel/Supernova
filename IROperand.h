
class IRTriple;
class IRBasicBlock;
class IRFunction;

class IROperand {
private:
public:
	IROperandType m_operand_type;
	
	std::variant<IRBasicBlock*,IRConstant*, IRVariable*, IRTriple*,IRFunction*,IRMember*,TypeRef> m_value;

	IROperand();
	IROperand(IRBasicBlock* b);
	IROperand(IRConstant* c);
	IROperand(IRVariable* n);
	IROperand(IRTriple* t);
	IROperand(IRFunction* t);
	IROperand(IRMember* m);
	IROperand(const TypeRef& type);

	IRBasicBlock* get_basic_block() const;
	IRConstant* get_constant() const;
	IRVariable* get_variable() const;
	IRTriple* get_triple() const;
	IRFunction* get_function() const;
	IRMember* get_member() const;
	TypeRef get_data_type() const;
};

std::ostream& operator<<(std::ostream& o, const IROperand& op) {
	switch (op.m_operand_type)
	{
	case IROperandType::CONSTANT: {
		o<<op.get_constant();
		break;
	}
	case IROperandType::VARIABLE: {
		IRVariable *var = op.get_variable();
		o << "Type : " << var->get_data_type().to_string() << " " << var->m_identifier << " " << var->m_index << std::endl;
		break;
	}
	case IROperandType::TRIPLE: {

		break;
	}
	case IROperandType::FUNCTION: {

		break;
	}
	case IROperandType::DATA_TYPE: {

		break;
	}
	case IROperandType::BASIC_BLOCK: {

		break;
	}
	case IROperandType::NO_OPERAND: {

		break;
	}
	case IROperandType::MEMBER: {

		break;
	}
	default:
		break;
	}

	return o;
}

