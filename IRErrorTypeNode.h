
class IRErrorTypeNode : public IRDataTypeNode {
private:
public:
	IRErrorTypeNode(IRDataTypeManager* dtm);
	IRDataTypeNodeType get_node_type() const override;
};
