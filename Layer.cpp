
Layer::Layer() {}

void Layer::add(const std::string &name,const IROperand &op) {
	if (m_operands.count(name)>0) {
		std::string msg = std::format("can't add operand with name {} to the layer with id",name);
		throw std::runtime_error(msg);
	}
	else
		m_operands[name] = op;
}

void Layer::remove(const std::string &name) {
	if (m_operands.count(name) > 0) 
		m_operands.erase(name);
	else {
		std::string msg = std::format("can't remove operand with name {}", name);
		throw std::runtime_error(msg);
	}
}

std::optional<IROperand> Layer::find(const std::string& name) const {
	if (m_operands.count(name) > 0)
		return { m_operands.at(name) };

	return {};
}

