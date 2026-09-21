
class CharLiteralNode : public AbstractSyntaxTreeNode {
private:
	char m_char_literal;
public:
	CharLiteralNode(char c) : AbstractSyntaxTreeNode{ TreeNodeType::CHAR }, m_char_literal{c} {};
	char get_char_literal() { return m_char_literal; }
};