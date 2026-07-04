
class MallocNode :public AbstractSyntaxTreeNode {
public:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
	MallocNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::MALLOC }, m_expr{ e } {
		add_child(m_expr);
	}
};