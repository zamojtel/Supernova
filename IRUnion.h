
class IRUnion: public IRCompositeTypeNode {
public:
private:
	IRUnion(const std::string& name);
	IRDataTypeNodeType get_node_type() const override;
};