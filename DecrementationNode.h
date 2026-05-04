
class DecrementationNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
	bool m_is_post_dec;
public:
	DecrementationNode(const ReferencePtr<AbstractSyntaxTreeNode>&e ,bool ipi) : AbstractSyntaxTreeNode{ TreeNodeType::DEC }, m_expr { e }, m_is_post_dec{ ipi } {
		add_child(m_expr);
	}

	AbstractSyntaxTreeNode* get_expr_node() const { return m_expr.get_ptr(); }
	bool get_post_dec() const { return m_is_post_dec; };
};