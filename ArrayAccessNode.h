
class ArrayAccessNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_array_name_expr;
	ReferencePtr<AbstractSyntaxTreeNode> m_index_expr;
public:
	ArrayAccessNode(const ReferencePtr<AbstractSyntaxTreeNode>& a_e, const ReferencePtr<AbstractSyntaxTreeNode>& i_e) : AbstractSyntaxTreeNode{ TreeNodeType::ARRAY_ACCESS }, m_array_name_expr{ a_e }, m_index_expr{i_e} {
		add_child(m_array_name_expr);
		add_child(m_index_expr);
	}

	ReferencePtr<AbstractSyntaxTreeNode> get_array_name_expr() const { return m_array_name_expr.get_ptr(); }
	ReferencePtr<AbstractSyntaxTreeNode> get_index_expr() const { return m_index_expr.get_ptr(); }
};