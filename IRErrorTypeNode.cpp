
IRErrorTypeNode::IRErrorTypeNode(IRDataTypeManager* dtm) : IRDataTypeNode{dtm} {}

IRDataTypeNodeType IRErrorTypeNode::get_node_type() const { return IRDataTypeNodeType::ERROR; };

size_t IRErrorTypeNode::calculate_size() { return 0; }