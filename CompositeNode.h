class CompositeNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<IdentifierNode> m_identifier;
	ReferencePtr<ListNode<MemberDeclarationNode>> m_declarations;
protected:
	// to jest jedynie konstruktor dla klas dziedzic¹cych nie do uzytku publicznego
	CompositeNode(TreeNodeType type, const ReferencePtr<IdentifierNode>& id, const ReferencePtr<ListNode<MemberDeclarationNode>>& decls) : AbstractSyntaxTreeNode{ type }, m_identifier{id}, m_declarations{ decls } {
		add_child(m_identifier);
		add_child(m_declarations);
	};
public:
	ReferencePtr<IdentifierNode>  get_identifier_node() const { return m_identifier.get_ptr(); }
	ReferencePtr<ListNode<MemberDeclarationNode>> get_declarations() const { return m_declarations.get_ptr(); }
	TypeRef m_ir_composite_data_type;
};