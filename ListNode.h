//#pragma once

template <class T> 
class ListNode : public AbstractSyntaxTreeNode {
private:
	friend class TreePrinter;
	std::vector<ReferencePtr<T>> m_list;
public:
	ListNode() : AbstractSyntaxTreeNode{ TreeNodeType::LIST } {}
	void add(const ReferencePtr<T> &node) {
		m_list.push_back(node);
		add_child(node);
	}

	size_t get_count() {
		return m_list.size();
	}

	ReferencePtr<T> get_element(size_t index) {
		return m_list[index];
	}

};
