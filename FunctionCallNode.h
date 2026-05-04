

class FunctionCallNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<IdentifierNode> m_identifier;
	ReferencePtr<ListNode<AbstractSyntaxTreeNode>> m_arguments;
public:
	FunctionCallNode(const ReferencePtr<IdentifierNode>& id, const ReferencePtr<ListNode<AbstractSyntaxTreeNode>>& a_l) : AbstractSyntaxTreeNode{ TreeNodeType::FUNCTION_CALL }, m_identifier{ id }, m_arguments{ a_l } {
		add_child(m_identifier);
		add_child(m_arguments);
	};

	ReferencePtr<IdentifierNode> get_identifier_node() const { return m_identifier.get_ptr(); }
	ReferencePtr<ListNode<AbstractSyntaxTreeNode>> get_arguments() const { return m_arguments.get_ptr(); }

};