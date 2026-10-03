class IRBaseFunction : public IRUsedObject {
public:
	enum class Kind {
		INTERNAL,
		EXTERNAL
	};

	std::string m_identifier;
	Kind m_kind;
	std::vector<TypeRef> m_parameter_types;
	TypeRef m_return_type;
	IRBaseFunction(const std::string& name, const std::vector<TypeRef>& types,const TypeRef& return_type,Kind kind);
	const std::string& get_name() const;
	const std::vector<TypeRef> get_parameter_types() const;
	bool compare_arguments(const std::vector<TypeRef>& argument_types);
	const TypeRef get_return_type() const;
};