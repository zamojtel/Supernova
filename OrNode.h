
class OrNode : public AbstractSyntaxTreeNode {
private:
	friend ASTConverter;
	ReferencePtr<AbstractSyntaxTreeNode> m_left;
	ReferencePtr<AbstractSyntaxTreeNode> m_right;
public:
	OrNode(const ReferencePtr<AbstractSyntaxTreeNode>& l, const ReferencePtr<AbstractSyntaxTreeNode>& r) : AbstractSyntaxTreeNode{ TreeNodeType::OR }, m_left{ l }, m_right{ r } {
		add_child(m_left);
		add_child(m_right);
	}
};