
class DataTypeNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_fundamental_type;
	ReferencePtr<ListNode<AbstractSyntaxTreeNode>> m_modifiers;
public:
	TypeRef m_ir_data_type;

	DataTypeNode(const ReferencePtr<AbstractSyntaxTreeNode>& ft, const ReferencePtr<ListNode<AbstractSyntaxTreeNode>>& ml) : AbstractSyntaxTreeNode{ TreeNodeType::DATA_TYPE }, m_fundamental_type{ ft }, m_modifiers{ ml } {
		add_child(m_fundamental_type);
		add_child(m_modifiers);
	}

	ReferencePtr<AbstractSyntaxTreeNode> get_fundamental_type() const { return m_fundamental_type.get_ptr(); }
	const TypeRef& get_ir_data_type() const { return m_ir_data_type; }
	ReferencePtr<ListNode<AbstractSyntaxTreeNode>> get_modifier_list() const { return m_modifiers.get_ptr(); }
};