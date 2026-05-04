

class FunctionParameterNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<DataTypeNode> m_data_type;
	ReferencePtr<IdentifierNode> m_identifier;
public:
	FunctionParameterNode(const ReferencePtr<DataTypeNode>& dn, const ReferencePtr<IdentifierNode>& id) : AbstractSyntaxTreeNode{TreeNodeType::PARAMETER}, m_data_type { dn }, m_identifier{ id } {
		add_child(m_data_type);
		add_child(m_identifier);
	};

	ReferencePtr<DataTypeNode> get_data_type_node() const { return m_data_type.get_ptr(); }
	ReferencePtr<IdentifierNode> get_identifier_node() const { return m_identifier.get_ptr(); }
};