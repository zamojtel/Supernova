
class ForNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_init_stmts;
	ReferencePtr<AbstractSyntaxTreeNode> m_condition;
	ReferencePtr<AbstractSyntaxTreeNode> m_exprs;
	ReferencePtr<AbstractSyntaxTreeNode> m_stmt;

public:
	ForNode(const ReferencePtr<AbstractSyntaxTreeNode>& init_stmt, const ReferencePtr<AbstractSyntaxTreeNode>& cond, const ReferencePtr<AbstractSyntaxTreeNode>& expr, const ReferencePtr<AbstractSyntaxTreeNode>& stmt) : AbstractSyntaxTreeNode{ TreeNodeType::FOR }, m_init_stmts{ init_stmt }, m_condition{ cond }, m_exprs{expr}, m_stmt { stmt } {
		add_child(init_stmt);
		add_child(cond);
		add_child(expr);
		add_child(stmt);
	}

	AbstractSyntaxTreeNode* get_init_stmt() const { return m_init_stmts.get_ptr(); }
	AbstractSyntaxTreeNode* get_condition() const { return m_condition.get_ptr(); }
	AbstractSyntaxTreeNode* get_exprs() const { return m_exprs.get_ptr(); }
	AbstractSyntaxTreeNode* get_block() const { return m_stmt.get_ptr(); }
};