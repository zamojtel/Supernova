
class IRStruct : public IRCompositeTypeNode {
private:
public:
	IRStruct(IRDataTypeManager* dtm, const std::string& name);
	IRDataTypeNodeType get_node_type() const override;
};
