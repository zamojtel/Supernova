

class CastNode : public AbstractSyntaxTreeNode {
public:
	ReferencePtr<DataTypeNode> m_data_type_node;
	ReferencePtr<AbstractSyntaxTreeNode> m_expr_node;
public:
	CastNode(const ReferencePtr<DataTypeNode>& c_t, const ReferencePtr<AbstractSyntaxTreeNode>& e) :AbstractSyntaxTreeNode{ TreeNodeType::CAST }, m_data_type_node{ c_t }, m_expr_node{ e } {
		add_child(m_data_type_node);
		add_child(m_expr_node);
	}

	DataTypeNode* get_data_type_node() { return m_data_type_node.get_ptr(); }
	AbstractSyntaxTreeNode* get_expr_node() { return m_expr_node.get_ptr(); }
};