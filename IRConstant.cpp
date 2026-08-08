
IRConstant::IRConstant(size_t i, const ConstantValue& cv, const TypeRef& ref) :m_index{ i }, m_constant_value{ cv }, m_data_type{ref} {}

const TypeRef& IRConstant::get_data_type() const { return m_data_type; }

const ConstantValue& IRConstant::get_value() { return m_constant_value; }

uint8_t* IRConstant::get_address() { return m_constant_value.get_address(); }

IROperandType IRConstant::get_operand_type() const {
	return IROperandType::CONSTANT;
}

size_t IRConstant::get_index() const { return m_index; }

IROperand IRConstant::get_operand() { return this; }