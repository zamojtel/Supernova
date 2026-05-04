class ReturnNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
public:
	ReturnNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::RETURN },m_expr { e } {
		add_child(m_expr);
	}

	AbstractSyntaxTreeNode* get_expr() const { return m_expr.get_ptr(); }
};