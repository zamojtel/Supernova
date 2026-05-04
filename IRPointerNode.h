
class IRPointerNode : public IRDataTypeNode {
private:
public:
	TypeRef m_element;
	IRPointerNode(const TypeRef& e);
	IRDataTypeNodeType get_node_type() const override;
};
