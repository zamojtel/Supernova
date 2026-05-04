
class MemberAccessNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
	ReferencePtr<IdentifierNode> m_field_identifier;
	bool m_is_arrow;
public:
	MemberAccessNode(const ReferencePtr<AbstractSyntaxTreeNode>& e, const ReferencePtr<IdentifierNode>& id, bool arrow) : AbstractSyntaxTreeNode{ TreeNodeType::MEMBER_ACCESS }, m_expr{ e }, m_field_identifier{ id }, m_is_arrow {arrow} {
		add_child(m_expr);
		add_child(m_field_identifier);
	}
	
	ReferencePtr<AbstractSyntaxTreeNode> get_expr() const { return m_expr.get_ptr(); }
	ReferencePtr<IdentifierNode> get_field_identifier() const { return m_field_identifier.get_ptr(); }
	bool is_arrow() const { return m_is_arrow; }
};