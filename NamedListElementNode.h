
class NamedListElementNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<IdentifierNode> m_identifier;
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
	ReferencePtr<ListNode<AbstractSyntaxTreeNode>> m_list;
public:
	NamedListElementNode(const ReferencePtr<IdentifierNode>& id, const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::NAMED_LIST_ELEMENT }, m_identifier{id}, m_expr { e } {
		add_child(m_identifier);
		add_child(m_expr);
	}

	NamedListElementNode(const ReferencePtr<IdentifierNode>& id, const ReferencePtr<ListNode<AbstractSyntaxTreeNode>>& l) : AbstractSyntaxTreeNode{ TreeNodeType::NAMED_LIST_ELEMENT }, m_identifier{id}, m_list{ l } {
		add_child(m_identifier);
		add_child(m_list);
	}

	ReferencePtr<IdentifierNode> get_identifier() { return m_identifier; }
	ReferencePtr<AbstractSyntaxTreeNode> get_expr() { return m_expr; }
	ReferencePtr<AbstractSyntaxTreeNode> get_named_element_list() { return m_list; }
};