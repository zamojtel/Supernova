
class UnnamedInitializationListNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<ListNode<AbstractSyntaxTreeNode>> m_element_nodes;
public:
	UnnamedInitializationListNode(const ReferencePtr<ListNode<AbstractSyntaxTreeNode>>& el_nodes) : AbstractSyntaxTreeNode{ TreeNodeType::UNNAMED_INITIALIZATION_LIST }, m_element_nodes{ el_nodes } {}
	ReferencePtr<ListNode<AbstractSyntaxTreeNode>> get_unnamed_element_list() { return m_element_nodes; }
};