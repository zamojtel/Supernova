
IRConstant::IRConstant(size_t index, const ConstantValue& cv, const TypeRef& ref) :m_index{ index }, m_constant_value{ cv }, m_data_type{ref} {}

IRConstant::IRConstant(size_t index, const StringRef& str_ref, const TypeRef& ref) :m_index{ index }, m_string_ref{ str_ref }, m_data_type{ ref } {}

const TypeRef& IRConstant::get_data_type() const { return m_data_type; }

const ConstantValue& IRConstant::get_value() { return m_constant_value; }

const StringRef& IRConstant::get_string_ref() { return m_string_ref; }

uint8_t* IRConstant::get_address() {
	if (m_data_type.is_string())
		return m_string_ref.get_pointer_address();

	return m_constant_value.get_address();
}

IROperandType IRConstant::get_operand_type() const {
	return IROperandType::CONSTANT;
}

size_t IRConstant::get_index() const { return m_index; }

IROperand IRConstant::get_operand() { return this; }