
class BooleanNotNode : public AbstractSyntaxTreeNode {
private:
	friend ASTConverter;
	ReferencePtr<AbstractSyntaxTreeNode> m_child;
public:
	BooleanNotNode(const ReferencePtr<AbstractSyntaxTreeNode>& c) : AbstractSyntaxTreeNode{ TreeNodeType::BOOLEAN_NOT}, m_child{ c } {
		add_child(m_child);
	}
};