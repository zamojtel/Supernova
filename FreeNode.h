

class FreeNode :public AbstractSyntaxTreeNode {
public:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
	FreeNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::FREE }, m_expr{ e } {
		add_child(m_expr);
	}
};