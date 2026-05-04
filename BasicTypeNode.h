

class BasicTypeNode : public AbstractSyntaxTreeNode {
private:
	friend class TreePrinter;
	IRBasicType m_basic_type;
public:
	BasicTypeNode(IRBasicType t) : AbstractSyntaxTreeNode{ TreeNodeType::BASIC_TYPE }, m_basic_type { t } {}
	IRBasicType get_data_type() const { return m_basic_type; };
};