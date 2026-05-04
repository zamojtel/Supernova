
class MemberDeclarationNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<IdentifierNode> m_name;
	ReferencePtr<DataTypeNode> m_data_type_node;
public:
	MemberDeclarationNode(const ReferencePtr<DataTypeNode>& dtn, const ReferencePtr<IdentifierNode>& m_mdcl) : AbstractSyntaxTreeNode{ TreeNodeType::MEMBER_DECLARATION }, m_data_type_node{ dtn }, m_name{ m_mdcl } {
		add_child(m_data_type_node);
		add_child(m_name);
	}

	DataTypeNode* get_data_type_node() { return m_data_type_node.get_ptr(); }
	ReferencePtr<IdentifierNode> get_identifier() { return m_name.get_ptr(); }
};