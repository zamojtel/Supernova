
class IRStruct : public IRCompositeTypeNode {
private:
public:
	IRStruct(const std::string& name);
	IRDataTypeNodeType get_node_type() const override;
};
