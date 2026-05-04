
class TypeRef {
private:
	friend class IRDataTypeManager;
	IRDataTypeNode* m_data_type_node = nullptr;
	std::string get_basic_type_string(IRBasicType type) const;
public:
	TypeRef();
	TypeRef(IRDataTypeNode* ir_data_type);
	TypeRef(const TypeRef& other);
	TypeRef(TypeRef&& other);
	TypeRef& operator=(IRDataTypeNode* other);
	TypeRef& operator=(const TypeRef& other);
	TypeRef& operator=(TypeRef&& other);
	bool operator==(const TypeRef& other) const;
	bool operator!=(const TypeRef& other) const;
	operator bool() const;
	std::string to_string() const;
	IRDataTypeNode* get_data_type_node() const;

	TypeRef remove_pointer_with_qualifiers() const;
	TypeRef remove_qualifiers() const;
	TypeRef remove_reference() const;
	TypeRef remove_array() const;
	TypeRef remove_extent() const;
	TypeRef remove_all_extents() const;
	std::vector<size_t> get_all_extents_size() const;

	bool is_array() const;
	bool is_qualifiers() const;
	bool is_basic_data_type() const;
	bool is_boolean() const;
	bool is_void() const;
	bool is_error() const;
	bool is_composite() const;
	bool is_pointer() const;
	bool is_reference() const;
	bool is_integer() const;
	bool is_numeric() const;
	bool is_pointer_with_qualifiers() const;

	size_t get_size() const;
	bool has_size() const;
	IRBasicType get_ir_basic_type() const;
	~TypeRef();
};