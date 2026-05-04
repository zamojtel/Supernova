class AbstractSyntaxTreeNode {
private:
	friend class ASTConverter;
	static size_t m_global_index;
	size_t m_index;
	std::vector<ReferencePtr<AbstractSyntaxTreeNode>> m_children;
	TreeNodeType m_type;
	int m_ref_count{ 0 };
	static size_t get_next_index() {
		return m_global_index++;
	}
	size_t m_line_number;
	IROperand m_operand;
protected:
	AbstractSyntaxTreeNode(TreeNodeType t) :m_index{get_next_index()}, m_type{t} {}
public:
	bool is_boolean_exprssion() const { 
		return 
			(m_type == TreeNodeType::AND) ||
			(m_type == TreeNodeType::OR)  ||
			(m_type == TreeNodeType::BOOLEAN_NOT);
	}

	static size_t get_max_index() { return m_global_index; }
	void add_ref() { m_ref_count++; }
	
	void release() {
		m_ref_count--;
		if (m_ref_count == 0)
			delete this;
	}
	
	TreeNodeType get_type() const { return m_type; };

	void add_child(const ReferencePtr<AbstractSyntaxTreeNode> &node) {
		//if (!node)
		//	std::runtime_error("Child is a nullptr");
		if(node)
			m_children.push_back(node);
	}

	size_t get_index() const { return m_index; }
	int get_child_count() const { return m_children.size(); }
	const ReferencePtr<AbstractSyntaxTreeNode>& get_child(size_t index) {
		if (index>m_children.size())
			throw std::runtime_error("CHILD INDEX OUT OF RANGE");
		return m_children[index];
	}
	
	void set_line_number(size_t l_n) { m_line_number = l_n; }
	size_t get_line_number() const { return m_line_number; }
	TreeNodeType get_tree_node_type() const { return m_type; };

	virtual ~AbstractSyntaxTreeNode() = default;
};