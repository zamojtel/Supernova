
const TypeRef& IRMember::get_data_type() const {
	return m_data_type;
}

const std::string IRMember::get_field_name() const {
	return m_name;
}

IROperandType IRMember::get_operand_type() const { return IROperandType::MEMBER; }

IROperand IRMember::get_operand() { return this; }

size_t IRMember::get_offset() const { return m_offset; }

void IRMember::set_offset(size_t offset) {
	m_offset = offset;
}