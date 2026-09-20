
class IRBasicTypeNode : public IRDataTypeNode {
private:
public:
	IRBasicType m_ir_data_type;
	IRBasicTypeNode(IRDataTypeManager* dtm, IRBasicType t);
	IRDataTypeNodeType get_node_type() const override;
};