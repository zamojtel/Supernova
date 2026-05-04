
class FunctionNode : public AbstractSyntaxTreeNode {
private:
	friend class TreePrinter;
	ReferencePtr<DataTypeNode> m_data_type;
	ReferencePtr<IdentifierNode> m_identifier;
	ReferencePtr<ListNode<FunctionParameterNode>> m_parameters;
	ReferencePtr<BlockNode> m_block;
	IRFunction* m_fn_ptr;
public:
	FunctionNode(const ReferencePtr<DataTypeNode>& dn, const ReferencePtr<IdentifierNode>& id,const ReferencePtr<ListNode<FunctionParameterNode>> &n_l, const ReferencePtr<BlockNode>& block) : AbstractSyntaxTreeNode{ TreeNodeType::FUNCTION }, m_data_type{ dn }, m_identifier{ id }, m_parameters{ n_l }, m_block{block} {
		add_child(m_data_type);
		add_child(m_identifier);
		add_child(m_parameters);
		add_child(m_block);
	}

	ReferencePtr<DataTypeNode> get_data_type_node() const { return m_data_type.get_ptr(); }
	ReferencePtr<IdentifierNode> get_identifier_node() const { return m_identifier.get_ptr(); }
	ReferencePtr<BlockNode> get_block_node() const { return m_block.get_ptr(); }
	ReferencePtr<ListNode<FunctionParameterNode>> get_parameters() const { return m_parameters.get_ptr(); }
	void set_function_ptr(IRFunction* fn_ptr) { m_fn_ptr = fn_ptr; }
	IRFunction* get_function_ptr() const { return m_fn_ptr; }
};