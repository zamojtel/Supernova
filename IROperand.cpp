
IROperand::IROperand(IRBasicBlock* b) :m_operand_type{ IROperandType::BASIC_BLOCK }, m_value{b} {}

IROperand::IROperand(IRConstant* c) :m_operand_type{ IROperandType::CONSTANT }, m_value{ c } {}

IROperand::IROperand(IRVariable* n) :m_operand_type{ IROperandType::VARIABLE }, m_value{ n } {}

IROperand::IROperand(IRTriple* t) :m_operand_type{ IROperandType::TRIPLE }, m_value{ t } {}

IROperand::IROperand(IRFunction* t) : m_operand_type{ IROperandType::FUNCTION }, m_value{ t } {}

IROperand::IROperand(IRMember* m) :m_operand_type{ IROperandType::MEMBER }, m_value{ m } {}

IROperand::IROperand(IRUsedObject* obj) {
	if (obj) {
		IROperand op = obj->get_operand();
		m_operand_type = op.m_operand_type;
		m_value = op.m_value;
	}
	else
		m_operand_type = IROperandType::NO_OPERAND;
}

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

bool IROperand::is_constant() const {
	switch (m_operand_type)
	{
	case IROperandType::CONSTANT:
		return true;
	default:
		return false;
		break;
	}
	return false;
}

IRUsedObject* IROperand::get_used_object() const {
	switch (m_operand_type)
	{
	case CONSTANT:
		return get_constant();
	case VARIABLE:
		return get_variable();
	case TRIPLE:
		return get_triple();
	case FUNCTION:
		return get_function();
	case BASIC_BLOCK:
		return get_basic_block();
	case MEMBER:
		return get_member();
	case NO_OPERAND:
		return nullptr;
	case DATA_TYPE:
		return nullptr;
	default:
		throw std::runtime_error("operand does not inherit from IRUsedObject");
		break;
	}
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
	case IROperandType::NO_OPERAND: {
		throw std::runtime_error("no operand no allowed");
		break;
	}
	default:
		throw std::runtime_error("not allowed operand type");
		break;
	}
}

bool IROperand::operator<(const IROperand& other) const {
	if (m_operand_type == other.m_operand_type) {
		switch (m_operand_type)
		{
		case CONSTANT: {
			return get_constant() < other.get_constant();
		}
		case VARIABLE: {
			return get_variable() < other.get_variable();
		}
		case TRIPLE: {
			return get_triple() < other.get_triple();
		}
		case FUNCTION: {
			return get_function() < other.get_function();
		}
		case DATA_TYPE: {
			return get_data_type() < other.get_data_type();
		}
		case BASIC_BLOCK: {
			return get_basic_block() < other.get_basic_block();
		}
		case MEMBER: {
			return get_member() < other.get_member();
		}
		case NO_OPERAND: {
			return false;
		}
		default:
			throw std::runtime_error("unknown operand type");
			break;
		}
	}
	else {
		return m_operand_type < other.m_operand_type;
	}
}

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