TypeRef::TypeRef(IRDataTypeNode* ir_data_type) : m_data_type_node{ir_data_type} {}

TypeRef::TypeRef() : m_data_type_node{nullptr} {}

TypeRef::TypeRef(const TypeRef& other) {
	m_data_type_node = other.m_data_type_node;
	if (m_data_type_node) {
		m_data_type_node->m_reference_count++;
	}
}

TypeRef::TypeRef(TypeRef&& other) {
	m_data_type_node = other.m_data_type_node;
	other.m_data_type_node = nullptr;
}

TypeRef TypeRef::remove_pointer_with_qualifiers() const {
	TypeRef current_ref = *this;

	current_ref = current_ref.remove_qualifiers();
	return !current_ref.is_pointer() ? *this : static_cast<IRPointerNode*>(current_ref.m_data_type_node)->m_element;
}

TypeRef TypeRef::remove_reference() const {
	TypeRef current_ref = *this;
	return !current_ref.is_reference() ? *this : static_cast<IRReferenceNode*>(current_ref.m_data_type_node)->m_element;
}

TypeRef TypeRef::remove_array() const {
	TypeRef current_ref = *this;
	return !current_ref.is_array() ? *this : static_cast<IRArrayNode*>(current_ref.m_data_type_node)->m_element_type;
}

TypeRef TypeRef::remove_qualifiers() const {
	return !is_qualifiers() ? *this : static_cast<IRQualifiersNode*>(m_data_type_node)->m_element;
}

TypeRef TypeRef::remove_extent() const {
	TypeRef current_ref = *this;
	return !current_ref.is_array() ? *this : static_cast<IRArrayNode*>(current_ref.m_data_type_node)->m_element_type;
}

TypeRef TypeRef::remove_all_extents() const {
	TypeRef current_ref = *this;

	while (current_ref.is_array())
		current_ref = static_cast<IRArrayNode*>(current_ref.m_data_type_node)->m_element_type;
	
	return current_ref;
}

std::vector<size_t> TypeRef::get_all_extents_size() const {
	TypeRef current_ref = *this;
	std::vector<size_t> dimensions;

	while (current_ref.is_array()) {
		auto casted = static_cast<IRArrayNode*>(current_ref.get_data_type_node());
		size_t size = casted->m_size;
		current_ref = casted->m_element_type;
		dimensions.push_back(size);
	}
	return dimensions;
}

// simplify this 
TypeRef& TypeRef::operator=(IRDataTypeNode* other) {
	// make it shorter
	//if (other == nullptr) {
	//	m_data_type_node->m_reference_count--;
	//	m_data_type_node = nullptr;
	//	return *this;
	//}

	//if (m_data_type_node == other)
	//	return *this;

	//if (m_data_type_node!=nullptr) {
	//	m_data_type_node->m_reference_count--;
	//	m_data_type_node = nullptr;
	//}

	//m_data_type_node = other;
	//m_data_type_node->m_reference_count++;

	//return *this;

	if (m_data_type_node != nullptr) {
		m_data_type_node->m_reference_count--;
	}
	m_data_type_node = other;
	
	if (m_data_type_node)
		m_data_type_node->m_reference_count++;

	return *this;
}

bool TypeRef::operator==(const TypeRef& other) const {
	return this->m_data_type_node == other.m_data_type_node;
}

bool TypeRef::operator!=(const TypeRef& other) const {
	return this->m_data_type_node != other.m_data_type_node;
}

TypeRef& TypeRef::operator=(const TypeRef& other) {
	return *this = other.m_data_type_node;
}

TypeRef& TypeRef::operator=(TypeRef&& other) {
	if (m_data_type_node != nullptr)
		m_data_type_node->m_reference_count--;

	m_data_type_node = other.m_data_type_node;
	other.m_data_type_node = nullptr;

	return *this;
}

TypeRef::~TypeRef() {
	if (m_data_type_node)
		m_data_type_node->m_reference_count--;
}

IRDataTypeNode* TypeRef::get_data_type_node() const {
	return m_data_type_node;
}

std::string TypeRef::get_basic_type_string(IRBasicType type) const {
	switch (type)
	{
	case IRBasicType::INT8: {
		return "INT8";
	}
	case IRBasicType::INT16: {
		return "INT16";
	}
	case IRBasicType::INT32: {
		return "INT32";
	}
	case IRBasicType::INT64: {
		return "INT64";
	}
	case IRBasicType::UINT8: {
		return "UINT8";
	}
	case IRBasicType::UINT16: {
		return "UINT16";
	}
	case IRBasicType::UINT32: {
		return "UINT32";
	}
	case IRBasicType::UINT64: {
		return "UINT64";
	}
	case IRBasicType::FLOAT: {
		return "FLOAT";
	}
	case IRBasicType::DOUBLE: {
		return "DOUBLE";
	}
	case IRBasicType::BOOL: {
		return "BOOL";
	}
	case IRBasicType::VOID: {
		return "VOID ";
	}
	default:
		throw std::runtime_error("no such type");
	}
}

std::string TypeRef::to_string() const {
	std::string result = "";
	
	if (!m_data_type_node)
		return "null";

	switch (m_data_type_node->get_node_type())
	{
	case IRDataTypeNodeType::ARRAY: {
		IRArrayNode* casted = static_cast<IRArrayNode*>(m_data_type_node);
		return casted->m_element_type.to_string() +" "+"[" + std::to_string(casted->m_size) + "]";
	}
	case IRDataTypeNodeType::BASIC_TYPE: {
		IRBasicTypeNode* casted = static_cast<IRBasicTypeNode*>(m_data_type_node);
		std::string basic_type = get_basic_type_string(casted->m_ir_data_type);
		return basic_type;
	}
	case IRDataTypeNodeType::POINTER: {
		IRPointerNode* casted = static_cast<IRPointerNode*>(m_data_type_node);
		return casted->m_element.to_string() +" "+ "*";
	}
	case IRDataTypeNodeType::QUALIFIER: {
		IRQualifiersNode* casted = static_cast<IRQualifiersNode*>(m_data_type_node);
		std::string qualifier;
		if (casted->m_bit_mask & casted->CONST)
		{
			// const -> c 
			qualifier = "c " + qualifier;
		}
	
		if (casted->m_bit_mask & casted->VOLATILE) {
			// volatile -> v
			qualifier = "v " + qualifier;
		}

		return casted->m_element.to_string() + " " + qualifier;
	}
	case IRDataTypeNodeType::REFERENCE: {
		IRReferenceNode* casted = static_cast<IRReferenceNode*>(m_data_type_node);
		return casted->m_element.to_string() + " " + "&";
	}
	case IRDataTypeNodeType::STRUCT: {
		IRStruct* casted = static_cast<IRStruct*>(m_data_type_node);

		return casted->get_name();
	}
	case IRDataTypeNodeType::UNION: {
		IRUnion* casted = static_cast<IRUnion*>(m_data_type_node);
		
		return casted->get_name();
	}
	case IRDataTypeNodeType::ERROR: {
		return "ERROR";
	}
	default:
		throw std::runtime_error("Type of this node not found");
		break;
	}
}

bool TypeRef::is_qualifiers() const {
	return m_data_type_node && (m_data_type_node->get_node_type() == IRDataTypeNodeType::QUALIFIER);
}

bool TypeRef::is_basic_data_type() const {
	return m_data_type_node && (m_data_type_node->get_node_type() == IRDataTypeNodeType::BASIC_TYPE);
}

bool TypeRef::is_boolean() const {
	return m_data_type_node && (m_data_type_node->get_node_type() == IRDataTypeNodeType::BASIC_TYPE && get_ir_basic_type() == IRBasicType::BOOL);
}

bool TypeRef::is_composite() const {
	return m_data_type_node && (m_data_type_node->get_node_type() == IRDataTypeNodeType::STRUCT || m_data_type_node->get_node_type() == IRDataTypeNodeType::UNION);
}

bool TypeRef::is_pointer() const {
	return m_data_type_node && (m_data_type_node->get_node_type() == IRDataTypeNodeType::POINTER);
}

bool TypeRef::is_array() const {
	return m_data_type_node && (m_data_type_node->get_node_type() == IRDataTypeNodeType::ARRAY);
}

bool TypeRef::is_integer() const {
	if (is_basic_data_type()) {
		IRBasicType type = static_cast<IRBasicTypeNode*>(m_data_type_node)->m_ir_data_type;
		return
			type == IRBasicType::INT8 || type == IRBasicType::INT16 ||
			type == IRBasicType::INT32 || type == IRBasicType::INT64 ||
			type == IRBasicType::UINT8 || type == IRBasicType::UINT16 ||
			type == IRBasicType::UINT32 || type == IRBasicType::UINT64;
	}
	return false;
}

bool TypeRef::is_numeric() const {
	if (is_basic_data_type()) {
		IRBasicType type = static_cast<IRBasicTypeNode*>(m_data_type_node)->m_ir_data_type;
		return
			type == IRBasicType::INT8   || type == IRBasicType::INT16 ||
			type == IRBasicType::INT32  || type == IRBasicType::INT64 ||
			type == IRBasicType::UINT8  || type == IRBasicType::UINT16 ||
			type == IRBasicType::UINT32 || type == IRBasicType::UINT64 ||
			type == IRBasicType::FLOAT  || type == IRBasicType::DOUBLE;
	}
	return false;
}

bool TypeRef::is_reference() const {
	return m_data_type_node && (m_data_type_node->get_node_type() == IRDataTypeNodeType::REFERENCE);
}

bool TypeRef::is_pointer_with_qualifiers() const {
	return remove_qualifiers().is_pointer();
}

bool TypeRef::is_void() const {
	return m_data_type_node && (m_data_type_node->get_node_type() == IRDataTypeNodeType::BASIC_TYPE && get_ir_basic_type() == IRBasicType::VOID);
}

bool TypeRef::is_error() const {
	return m_data_type_node && (m_data_type_node->get_node_type() == IRDataTypeNodeType::ERROR);
}

IRBasicType TypeRef::get_ir_basic_type() const {
	if (is_basic_data_type())
		return static_cast<IRBasicTypeNode*>(m_data_type_node)->m_ir_data_type;
	else
		throw std::runtime_error("typeRef is not a basic type");
}

size_t TypeRef::get_size() const {
	if (m_data_type_node) {
		auto size_opt = m_data_type_node->get_size();
		if (size_opt.has_value())
			return *size_opt;
		else {
			throw std::runtime_error("size of type is not set");
		}
	}
	else
		throw std::runtime_error("data_type_node is nullptr");
}

bool TypeRef::has_size() const {
	if (m_data_type_node)
		return m_data_type_node->m_size.has_value();
	else
		throw std::runtime_error("data_type_node is nullptr");
}

TypeRef::operator bool() const {
	return m_data_type_node != nullptr;
}