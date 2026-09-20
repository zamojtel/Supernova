
class IRPointerNode : public IRDataTypeNode {
private:
public:
	TypeRef m_element;
	IRPointerNode(IRDataTypeManager* dtm,const TypeRef& e);
	IRDataTypeNodeType get_node_type() const override;
};
