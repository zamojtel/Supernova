
class IRNullptrNode : public IRDataTypeNode {
private:
public:
	TypeRef m_element;
	IRNullptrNode(IRDataTypeManager* dtm);
	IRDataTypeNodeType get_node_type() const override;
};
