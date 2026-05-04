
// jak jest const IROperand &op to mozna przekazywac tymczasowe obiekty 
void SymbolTable::add_symbol(const std::string &name,const IROperand& op) {
	m_layers.back().add(name,op);
}

std::optional<IROperand> SymbolTable::find_symbol(const std::string &name) {
	for (int i = m_layers.size() - 1; i >= 0;i--) {
		auto operand = m_layers[i].find(name);
		if (operand.has_value())
			return operand;
	}

	return {};
}

bool SymbolTable::can_add(const std::string &name) const {
	return !m_layers.back().find(name).has_value();
}

void SymbolTable::add_layer() {
	m_layers.emplace_back();
}

void SymbolTable::pop_layer() {
	m_layers.pop_back();
}