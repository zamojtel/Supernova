

class PrintTypeNode :public AbstractSyntaxTreeNode {
private:
public:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
	PrintTypeNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::PRINT_TYPE }, m_expr{ e } {
		add_child(m_expr);
	}
};