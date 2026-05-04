
class QualifierNode :public AbstractSyntaxTreeNode {
private:
	// const = 1
	// volatile = 2
	uint8_t m_mask;
public:
	QualifierNode(uint8_t mask) : AbstractSyntaxTreeNode{ TreeNodeType::QUALIFIER }, m_mask{mask} {}
	uint8_t get_mask() const { return m_mask;  }
};