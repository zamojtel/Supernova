

class IfNode :public AbstractSyntaxTreeNode {
private:
public:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
	ReferencePtr<AbstractSyntaxTreeNode> m_stmt;
	ReferencePtr<AbstractSyntaxTreeNode> m_else_stmt;
	
	IfNode(const ReferencePtr<AbstractSyntaxTreeNode> &expr, const ReferencePtr<AbstractSyntaxTreeNode> &stmt) :AbstractSyntaxTreeNode{ TreeNodeType::IF }, m_expr{ expr }, m_stmt{stmt} {
		add_child(m_expr);
		add_child(m_stmt);
	}

	IfNode(const ReferencePtr<AbstractSyntaxTreeNode>& expr, const ReferencePtr<AbstractSyntaxTreeNode>& stmt, const ReferencePtr<AbstractSyntaxTreeNode>& e_stmt) :AbstractSyntaxTreeNode{ TreeNodeType::IF }, m_expr{ expr }, m_stmt{ stmt }, m_else_stmt{e_stmt} {
		add_child(m_expr);
		add_child(m_stmt);
		if (m_else_stmt.get_ptr() != nullptr) {
			add_child(m_else_stmt);
		}
	}
};