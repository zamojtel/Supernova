
IROperand::IROperand(IRBasicBlock* b) :m_operand_type{ IROperandType::BASIC_BLOCK }, m_value{b} {}

IROperand::IROperand(IRConstant* c) :m_operand_type{ IROperandType::CONSTANT }, m_value{ c } {}

IROperand::IROperand(IRVariable* n) :m_operand_type{ IROperandType::VARIABLE }, m_value{ n } {}

IROperand::IROperand(IRTriple* t) :m_operand_type{ IROperandType::TRIPLE }, m_value{ t } {}

IROperand::IROperand(IRFunction* t) : m_operand_type{ IROperandType::FUNCTION }, m_value{ t } {}

IROperand::IROperand(IRMember* m) :m_operand_type{ IROperandType::MEMBER }, m_value{ m } {}

IROperand::IROperand() : m_operand_type{ IROperandType::NO_OPERAND } {}

IROperand::IROperand(const TypeRef& type) : m_operand_type{ IROperandType::DATA_TYPE }, m_value{type} {}

IRConstant* IROperand::get_constant() const { return std::get<IRConstant*>(m_value); }

IRVariable* IROperand::get_variable() const { return std::get<IRVariable*>(m_value); }

IRTriple* IROperand::get_triple() const { return std::get<IRTriple*>(m_value); }

IRFunction* IROperand::get_function() const { return std::get<IRFunction*>(m_value); }

IRMember* IROperand::get_member() const { return std::get<IRMember*>(m_value); };

IRBasicBlock* IROperand::get_basic_block() const { 
	return std::get<IRBasicBlock*>(m_value);
}

TypeRef IROperand::get_data_type() const {

	switch (m_operand_type)
	{
	case IROperandType::CONSTANT: {
		return get_constant()->get_data_type();
	}
	case IROperandType::TRIPLE: {
		return get_triple()->get_data_type();
	}
	case IROperandType::VARIABLE: {
		return get_variable()->get_data_type();
	}
	case IROperandType::DATA_TYPE: {
		return std::get<TypeRef>(m_value);
	}
	case IROperandType::MEMBER: {
		return get_member()->get_data_type();
	}
	default:
		throw std::runtime_error("not allowed operand type");
		break;
	}
}
