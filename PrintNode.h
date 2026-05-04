
class PrintNode :public AbstractSyntaxTreeNode {
private:
public:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
	PrintNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::PRINT }, m_expr{ e } {
		add_child(m_expr);
	}
};