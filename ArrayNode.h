

class ArrayNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
public:
	ArrayNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::ARRAY}, m_expr{e} {
		add_child(m_expr);
	}

	ReferencePtr<AbstractSyntaxTreeNode> get_expr() const { return m_expr.get_ptr(); }
};