
class StringLiteralNode : public AbstractSyntaxTreeNode {
private:
	std::string m_text;
public:
	StringLiteralNode(const std::string& t) : AbstractSyntaxTreeNode{ TreeNodeType::STRING_LITERAL }, m_text{ t } {}
	std::string get_string_literal() { return m_text; }
};