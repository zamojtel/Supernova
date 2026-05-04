
class SizeOfNode : public AbstractSyntaxTreeNode {
private:
public:
	ReferencePtr<DataTypeNode> m_data_type;
	SizeOfNode(const ReferencePtr<DataTypeNode>& dt) : AbstractSyntaxTreeNode{ TreeNodeType::SIZE_OF }, m_data_type{ dt } {
		add_child(m_data_type);
	}
	

};