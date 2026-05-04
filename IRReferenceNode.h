
class IRReferenceNode : public IRDataTypeNode {
private:
public:
	TypeRef m_element;
	IRReferenceNode(const TypeRef& r);
	IRDataTypeNodeType get_node_type() const override;
	size_t calculate_size() const;
};