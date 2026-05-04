
class WhileNode : public AbstractSyntaxTreeNode {
private:
	ReferencePtr<AbstractSyntaxTreeNode> m_condition;
	ReferencePtr<AbstractSyntaxTreeNode> m_stmt;
public:
	WhileNode(const ReferencePtr<AbstractSyntaxTreeNode>& cond, const ReferencePtr<AbstractSyntaxTreeNode>& stmt) : AbstractSyntaxTreeNode{ TreeNodeType::WHILE }, m_condition{ cond }, m_stmt{ stmt } {
		add_child(m_condition);
		add_child(m_stmt);
	}
	AbstractSyntaxTreeNode* get_condition() const { return m_condition.get_ptr(); }
	AbstractSyntaxTreeNode* get_block() const { return m_stmt.get_ptr(); }
};