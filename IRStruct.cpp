
IRStruct::IRStruct(const std::string& name): IRCompositeTypeNode{ name } {}

IRDataTypeNodeType IRStruct::get_node_type() const {
	return 	IRDataTypeNodeType::STRUCT;
}