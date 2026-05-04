
class BlockNode :public AbstractSyntaxTreeNode {
private:
	ReferencePtr<ListNode<AbstractSyntaxTreeNode>> m_stmts;
public:
	BlockNode(const ReferencePtr<ListNode<AbstractSyntaxTreeNode>> &stmts) :AbstractSyntaxTreeNode{ TreeNodeType::BLOCK }, m_stmts{stmts} {
		add_child(m_stmts);
	}
};