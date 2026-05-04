
class AssertNode :public AbstractSyntaxTreeNode {
private:
public:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
	AssertNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) :AbstractSyntaxTreeNode{ TreeNodeType::ASSERT }, m_expr{e} {
		add_child(m_expr);
	}
};