
class SymbolTable {
private:
	std::vector<Layer> m_layers;
public:
	void add_symbol(const std::string& name,const IROperand& op);
	std::optional<IROperand> find_symbol(const std::string& name);
	bool can_add(const std::string& name) const;
	void add_layer();
	void pop_layer();
};