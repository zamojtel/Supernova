
class IRNullptrNode : public IRDataTypeNode {
private:
public:
	TypeRef m_element;
	IRNullptrNode();
	IRDataTypeNodeType get_node_type() const override;
};
