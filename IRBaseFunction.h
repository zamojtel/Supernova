class IRBaseFunction : public IRUsedObject {
public:
	enum class Kind {
		INTERNAL,
		EXTERNAL
	};

	IRBaseFunction(const std::string& name,size_t index, const std::vector<TypeRef>& types,const TypeRef& return_type,Kind kind);
	std::string m_identifier;
	Kind m_kind;
	std::vector<TypeRef> m_parameter_types;
	TypeRef m_return_type;
	size_t m_index;
	const std::string& get_name() const;
	const std::vector<TypeRef> get_parameter_types() const;
	bool compare_arguments(const std::vector<TypeRef>& argument_types);
	const TypeRef get_return_type() const;
	size_t get_index() const;
};