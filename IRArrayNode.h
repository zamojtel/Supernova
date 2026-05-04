
class IRArrayNode : public IRDataTypeNode {
private:
public:
	size_t m_size;
	TypeRef m_element_type;
	IRArrayNode(const TypeRef& ref, size_t s);
	IRDataTypeNodeType get_node_type() const override;
	size_t calculate_size() override;
};