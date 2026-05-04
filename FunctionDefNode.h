

//class FunctionDefNode : public AbstractSyntaxTreeNode {
//private:
//	ReferencePtr<DataTypeNode> m_data_type;
//	ReferencePtr<ListNode<FunctionParameterNode>> m_parameters;
//public:
//	FunctionDefNode(const ReferencePtr<DataTypeNode>& dn, const ReferencePtr<ListNode<FunctionParameterNode>>& p_l) : AbstractSyntaxTreeNode{ TreeNodeType::FUNCTIONDEF }, m_data_type{ dn }, m_parameters{ p_l } {
//		add_child(m_data_type);
//		add_child(m_parameters);
//	}
//};