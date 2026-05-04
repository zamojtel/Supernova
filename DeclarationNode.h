
class DeclarationNode : public AbstractSyntaxTreeNode {
private:
	friend class TreePrinter;
	ReferencePtr<DataTypeNode> m_data_type_node;
	ReferencePtr<ListNode<DeclarationListItemNode>> m_declarations;
public:
	DeclarationNode(const ReferencePtr<DataTypeNode>& dtn, const ReferencePtr<ListNode<DeclarationListItemNode>>& in) : AbstractSyntaxTreeNode{ TreeNodeType::DECLARATION }, m_data_type_node{ dtn }, m_declarations{in} {
		add_child(m_data_type_node);
		add_child(m_declarations);
	}

	DataTypeNode* get_data_type_node() { return m_data_type_node.get_ptr(); }
	ListNode<DeclarationListItemNode>* get_declarations() { return m_declarations.get_ptr(); }
};