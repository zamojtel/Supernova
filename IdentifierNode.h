
class IdentifierNode : public AbstractSyntaxTreeNode {
private:
	friend class TreePrinter;
	std::string m_identifier;
public:
	IdentifierNode(const std::string& i) 
		: 
		AbstractSyntaxTreeNode{ TreeNodeType::IDENTIFIER },
		m_identifier{ i } {}
	std::string get_identifier() { return m_identifier; }
};