
IRErrorTypeNode::IRErrorTypeNode(IRDataTypeManager* dtm) : IRDataTypeNode{dtm} {}

IRDataTypeNodeType IRErrorTypeNode::get_node_type() const { return IRDataTypeNodeType::ERROR; };