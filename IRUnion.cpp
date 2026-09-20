
IRUnion::IRUnion(IRDataTypeManager* dtm, const std::string& name) : IRCompositeTypeNode{ dtm,name } {}

IRDataTypeNodeType IRUnion::get_node_type() const {
	return IRDataTypeNodeType::UNION;
}
