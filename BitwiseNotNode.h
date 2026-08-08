
class BitwiseNotNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
public:
	BitwiseNotNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::BITWISE_NOT }, m_expr{ e } {
		add_child(m_expr);
	}

	ReferencePtr<AbstractSyntaxTreeNode> get_expr_node() const { return m_expr.get_ptr(); }
};