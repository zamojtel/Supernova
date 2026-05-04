
class DeclarationListItemNode : public AbstractSyntaxTreeNode {
private:
	friend class TreePrinter;
	ReferencePtr<IdentifierNode> m_identifier_node;
	ReferencePtr<AbstractSyntaxTreeNode> m_expr_node;

public:
	DeclarationListItemNode(const ReferencePtr<IdentifierNode>& in) : AbstractSyntaxTreeNode{ TreeNodeType::DECLARATION }, m_identifier_node{ in } {
		add_child(m_identifier_node);
	}

	DeclarationListItemNode(const ReferencePtr<IdentifierNode>& in, const ReferencePtr<AbstractSyntaxTreeNode>& expr) : AbstractSyntaxTreeNode{ TreeNodeType::DECLARATION }, m_identifier_node{ in }, m_expr_node{ expr } {
		add_child(m_identifier_node);
		add_child(m_expr_node);
	}

	IdentifierNode* get_indentifier_node() { return m_identifier_node.get_ptr(); }
	AbstractSyntaxTreeNode* get_expr_node() { return m_expr_node.get_ptr(); }
};