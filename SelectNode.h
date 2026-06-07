
class SelectNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_condition;
	ReferencePtr<AbstractSyntaxTreeNode> m_expr_true;
	ReferencePtr<AbstractSyntaxTreeNode> m_expr_false;
public:
	
	SelectNode(const ReferencePtr<AbstractSyntaxTreeNode>& c, const ReferencePtr<AbstractSyntaxTreeNode>& e_t, const ReferencePtr<AbstractSyntaxTreeNode>& e_f) : AbstractSyntaxTreeNode{ TreeNodeType::SELECT }, m_condition{ c }, m_expr_true{ e_t }, m_expr_false{e_f} {
		add_child(m_condition);
		add_child(m_expr_true);
		add_child(m_expr_false);
	}

	ReferencePtr<AbstractSyntaxTreeNode> get_condition() const { return m_condition.get_ptr(); }
	ReferencePtr<AbstractSyntaxTreeNode> get_expr_true() const { return m_expr_true.get_ptr(); }
	ReferencePtr<AbstractSyntaxTreeNode> get_expr_false() const { return m_expr_false.get_ptr(); }
};