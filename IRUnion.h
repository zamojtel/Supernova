
class IRUnion: public IRCompositeTypeNode {
private:
public:
	IRUnion(IRDataTypeManager* dtm,const std::string& name);
	IRDataTypeNodeType get_node_type() const override;
};