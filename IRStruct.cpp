
IRStruct::IRStruct(IRDataTypeManager* dtm,const std::string& name): IRCompositeTypeNode{dtm, name } {}

IRDataTypeNodeType IRStruct::get_node_type() const {
	return 	IRDataTypeNodeType::STRUCT;
}