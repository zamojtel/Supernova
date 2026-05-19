
class DereferenceNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
public:
	DereferenceNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::DEREFERENCE }, m_expr{ e } {
		add_child(m_expr);
	}

	//ReferencePtr<AbstractSyntaxTreeNode> get_expression() { return m_expr; }
	ReferencePtr<AbstractSyntaxTreeNode> get_expr_node() { return m_expr; }
};