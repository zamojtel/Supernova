
IRUnion::IRUnion(const std::string& name) : IRCompositeTypeNode{ name } {}

IRDataTypeNodeType IRUnion::get_node_type() const {
	return IRDataTypeNodeType::UNION;
}
