
class Layer {
private:
	// IROperand ale one sa odzielone od tych prawdziwego IR
	std::unordered_map<std::string,IROperand> m_operands;
public:
	Layer();
	void add(const std::string& name,const IROperand& op);
	std::optional<IROperand> find(const std::string& name) const;
	void remove(const std::string& name);
};