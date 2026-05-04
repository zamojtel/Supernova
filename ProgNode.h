
class ProgNode : public AbstractSyntaxTreeNode {
private:
	friend class ASTConverter;
	// item can be a function or declaration with assignment
	ReferencePtr<ListNode<AbstractSyntaxTreeNode>> m_items;
public:
	ProgNode(const ReferencePtr<ListNode<AbstractSyntaxTreeNode>>& items) :AbstractSyntaxTreeNode{ TreeNodeType::PROG }, m_items{ items } {
		add_child(m_items);
	}
};