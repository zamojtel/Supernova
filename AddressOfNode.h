
class AddressOfNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_expr;
public:
	AddressOfNode(const ReferencePtr<AbstractSyntaxTreeNode>& e) : AbstractSyntaxTreeNode{ TreeNodeType::ADDRESS_OF }, m_expr{e} {
		add_child(m_expr);
	}
	ReferencePtr<AbstractSyntaxTreeNode> get_expr_node() { return m_expr; }
};