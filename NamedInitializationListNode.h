
class NamedInitializationListNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<ListNode<NamedListElementNode>> m_element_nodes;
public:
	NamedInitializationListNode(const ReferencePtr<ListNode<NamedListElementNode>>& e_nodes) : AbstractSyntaxTreeNode{ TreeNodeType::NAMED_INITIALIZATION_LIST }, m_element_nodes{ e_nodes } { }
	ReferencePtr<ListNode<NamedListElementNode>> get_named_element_list() { return m_element_nodes;  }
};