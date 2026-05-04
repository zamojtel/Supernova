

class AssignmentNode : public AbstractSyntaxTreeNode {
private:
	friend class TreePrinter;
	ReferencePtr<AbstractSyntaxTreeNode> m_left_expr_node; // treated as identifier to which we assign some value
	ReferencePtr<AbstractSyntaxTreeNode> m_right_expr_node;
public:
	AssignmentNode(const ReferencePtr<AbstractSyntaxTreeNode> &l_expr,const ReferencePtr<AbstractSyntaxTreeNode> &r_expr) : AbstractSyntaxTreeNode{ TreeNodeType::ASSIGNMENT }, m_left_expr_node{l_expr}, m_right_expr_node{r_expr} {
		add_child(m_left_expr_node);
		add_child(m_right_expr_node);
	}

	ReferencePtr<AbstractSyntaxTreeNode> get_left_expr_node() { return m_left_expr_node.get_ptr(); }
	ReferencePtr<AbstractSyntaxTreeNode> get_right_expr_node() { return m_right_expr_node.get_ptr(); }

};
