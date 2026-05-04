
class IncrementationNode :public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
	bool m_is_post_inc;
public:
	IncrementationNode(const ReferencePtr<AbstractSyntaxTreeNode>&e, bool ipi) :AbstractSyntaxTreeNode{ TreeNodeType::INC }, m_expr { e }, m_is_post_inc{ ipi } {
		add_child(m_expr);
	}

	AbstractSyntaxTreeNode* get_expr_node() const { return m_expr.get_ptr(); }
	bool get_post_inc() const { return m_is_post_inc; };
};