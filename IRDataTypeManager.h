class IRDataTypeManager {
private:
	struct ArrayKey {
		IRDataTypeNode* m_data_node_type;
		size_t m_size;
		bool operator==(const ArrayKey& other) const = default;
	};
	struct QualifierKey {
		IRDataTypeNode* m_data_node_type;
		uint8_t m_mask;
		bool operator==(const QualifierKey& other) const = default;
	};
	struct ReferenceKey {
		IRDataTypeNode* m_data_node_type;
	};
	class ArrayKeyHasher {
	public:
		size_t operator()(const ArrayKey& a_k) const noexcept {
			size_t h1 = std::hash<IRDataTypeNode*>{}(a_k.m_data_node_type);
			size_t h2 = std::hash<size_t>{}(a_k.m_size);

			return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
		}
	};
	class QualifierKeyHasher {
	public:
		size_t operator()(const QualifierKey& q_k) const noexcept {
			size_t h1 = std::hash<IRDataTypeNode*>{}(q_k.m_data_node_type);
			size_t h2 = std::hash<size_t>{}(q_k.m_mask);

			return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
		}
	};
	TypeRef m_error_type;
	std::vector<IRDataTypeNode*> m_all_data_types;
	std::unordered_map<IRBasicType,IRBasicTypeNode*> m_basic_types;
	std::vector<TypeRef> m_unions;
	std::vector<TypeRef> m_structs;
	std::unordered_map<IRDataTypeNode*, IRDataTypeNode*> m_existing_pointer_types;
	std::unordered_map<IRDataTypeNode*,IRDataTypeNode*> m_reference_types;
	std::unordered_map<ArrayKey,IRDataTypeNode*,ArrayKeyHasher> m_existing_array_types;
	std::unordered_map<QualifierKey,IRDataTypeNode*,QualifierKeyHasher> m_existing_qualified_types;
public:
	IRDataTypeManager();
	TypeRef add_qualifiers(const TypeRef& type_node, uint8_t mask);
	TypeRef add_array(const TypeRef& type_node, size_t arr_size);
	TypeRef add_struct(const std::string& name);
	TypeRef add_union(const std::string& name);
	TypeRef add_pointer(const TypeRef& type_node);
	TypeRef add_reference(const TypeRef& type_node);
	TypeRef get_basic_type_node(IRBasicType type) const;
	std::vector<IRDataTypeNode*>& get_all_data_types();

	TypeRef get_bool() const;
	TypeRef get_int() const;
	TypeRef get_error() const;
	TypeRef get_void() const;
};