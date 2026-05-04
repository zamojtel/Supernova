class TypeModifierNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<ListNode<AbstractSyntaxTreeNode>> m_list;
public:
	TypeModifierNode(const ReferencePtr<ListNode<AbstractSyntaxTreeNode>>& l) : AbstractSyntaxTreeNode{ TreeNodeType::TYPE_MODIFIER } , m_list { l } {
		add_child(m_list);
	}
};