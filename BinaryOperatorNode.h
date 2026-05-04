

class BinaryOperatorNode : public AbstractSyntaxTreeNode {
private:
	friend class TreePrinter;
public:
	OperationType m_op;
	ReferencePtr<AbstractSyntaxTreeNode> m_left;
	ReferencePtr<AbstractSyntaxTreeNode> m_right;

	BinaryOperatorNode(const ReferencePtr<AbstractSyntaxTreeNode> &l,const ReferencePtr<AbstractSyntaxTreeNode> &r, OperationType op) : AbstractSyntaxTreeNode{ TreeNodeType::BIN_OPERATION }, m_op{ op }, m_left{ l }, m_right{ r } {
		add_child(m_left);
		add_child(m_right);
	}

	OperationType get_operation_type() const { return m_op; }

};