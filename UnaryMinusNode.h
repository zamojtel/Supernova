
class UnaryMinusNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
public:
	UnaryMinusNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::UNARY_MINUS}, m_expr{ e } {
		add_child(m_expr);
	}

	ReferencePtr<AbstractSyntaxTreeNode> get_expr_node() const { return m_expr.get_ptr(); }
};