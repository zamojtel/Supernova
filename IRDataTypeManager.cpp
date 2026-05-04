
IRDataTypeManager::IRDataTypeManager() {
	size_t n = (size_t)IRBasicType::NUMBER_OF_TYPES;
	m_error_type = new IRErrorTypeNode{};
	for (size_t i = 0; i < n ; i++) {
		IRBasicType b_t = (IRBasicType)i;
		IRBasicTypeNode* new_basic_type_node = new IRBasicTypeNode{b_t};
		m_basic_types[b_t] = new_basic_type_node;
		m_all_data_types.push_back(new_basic_type_node);
	}
}

TypeRef IRDataTypeManager::add_qualifiers(const TypeRef& type_node,uint8_t mask) {
	if (type_node.is_array())
		throw std::runtime_error("qualifier array type is not allowed");

	if (type_node.is_qualifiers()) {
		IRQualifiersNode* qualifier_node = static_cast<IRQualifiersNode*>(type_node.m_data_type_node);
		uint8_t new_mask = qualifier_node->m_bit_mask | mask;
		QualifierKey new_qualifier_key = QualifierKey{ type_node.m_data_type_node,new_mask };
		if (m_existing_qualified_types.count(new_qualifier_key) > 0)
			return m_existing_qualified_types.at(new_qualifier_key);
		else {
			IRQualifiersNode* new_qualifier_node = new IRQualifiersNode{type_node.m_data_type_node,new_mask};
			m_existing_qualified_types[new_qualifier_key] = new_qualifier_node;
			m_all_data_types.push_back(new_qualifier_node);
			return new_qualifier_node;
		}
	}
	else {
		QualifierKey new_qualifier_key = QualifierKey{ type_node.m_data_type_node,mask };
		if (m_existing_qualified_types.count(new_qualifier_key) > 0)
			return m_existing_qualified_types.at(new_qualifier_key);
		else {
			IRQualifiersNode* qualifier_node = new IRQualifiersNode{type_node.m_data_type_node,mask};
			m_existing_qualified_types[new_qualifier_key] = qualifier_node;
			m_all_data_types.push_back(qualifier_node);
			return qualifier_node;
		}
	}
}

TypeRef IRDataTypeManager::add_array(const TypeRef& type_node,size_t arr_size) {
	ArrayKey new_key{ type_node.m_data_type_node,arr_size };

	if (m_existing_array_types.count(new_key) == 0) {
		IRArrayNode* new_array_type = new IRArrayNode{ type_node,arr_size };
		m_existing_array_types[new_key] = new_array_type;
		m_all_data_types.push_back(new_array_type);
		return new_array_type;
	}
	else
		return m_existing_array_types.at(new_key);
}

TypeRef IRDataTypeManager::add_struct(const std::string& name) {
	IRStruct* new_struct = new IRStruct{ name };
	m_structs.emplace_back(new_struct);
	m_all_data_types.push_back(new_struct);
	return new_struct;
}

TypeRef IRDataTypeManager::add_union(const std::string& name) {
	IRStruct* new_union = new IRStruct{ name };
	m_structs.emplace_back(new_union);
	m_all_data_types.push_back(new_union);
	return new_union;
}

TypeRef IRDataTypeManager::add_pointer(const TypeRef &type_node) {
	if (m_existing_pointer_types.count(type_node.m_data_type_node)==0) {
		IRPointerNode* new_pointer = new IRPointerNode{type_node};
		m_existing_pointer_types[type_node.m_data_type_node] = new_pointer;
		m_all_data_types.push_back(new_pointer);
		return new_pointer;
	}
	else 
		return { m_existing_pointer_types.at(type_node.m_data_type_node)};
}

TypeRef IRDataTypeManager::add_reference(const TypeRef& type_node) {
	if (m_reference_types.count(type_node.m_data_type_node) == 0) {
		IRReferenceNode* new_reference = new IRReferenceNode{ type_node };
		m_reference_types[type_node.m_data_type_node] = new_reference;
		m_all_data_types.push_back(new_reference);
		return new_reference;
	}
	else
		return {m_reference_types.at(type_node.m_data_type_node)};
}

std::vector<IRDataTypeNode*>& IRDataTypeManager::get_all_data_types() {
	return m_all_data_types;
}

TypeRef IRDataTypeManager::get_basic_type_node(IRBasicType type) const {
	return m_basic_types.at(type);
}

TypeRef IRDataTypeManager::get_bool() const {
	return m_basic_types.at(IRBasicType::BOOL);
}

TypeRef IRDataTypeManager::get_int() const {
	return m_basic_types.at(IRBasicType::INT32);
}

TypeRef IRDataTypeManager::get_error() const {
	return m_error_type;
}

TypeRef IRDataTypeManager::get_void() const {
	return m_basic_types.at(IRBasicType::VOID);
}