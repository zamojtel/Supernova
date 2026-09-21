

class MemcpyNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_dest;
	ReferencePtr<AbstractSyntaxTreeNode> m_source;
	ReferencePtr<AbstractSyntaxTreeNode> m_count;
public:
	MemcpyNode(const ReferencePtr<AbstractSyntaxTreeNode>& d,const ReferencePtr<AbstractSyntaxTreeNode>& s,const ReferencePtr<AbstractSyntaxTreeNode>& c) : AbstractSyntaxTreeNode{ TreeNodeType::MEMCPY },
		m_dest{ d }, m_source{ s }, m_count{ c } {};
	ReferencePtr<AbstractSyntaxTreeNode> get_destination() const { return m_dest; }
	ReferencePtr<AbstractSyntaxTreeNode> get_source() const { return m_source; }
	ReferencePtr<AbstractSyntaxTreeNode> get_count() const { return m_count; }
};