class IRVariable {
public:
	std::string m_identifier;
	TypeRef m_data_type;
	size_t m_index;
	IRVariable(const std::string& i,const TypeRef& t, size_t in);
	std::string get_variable_name() const;
	const TypeRef& get_data_type() const;
	size_t get_index() const;
	virtual bool is_global() const = 0;
};