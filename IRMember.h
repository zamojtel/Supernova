
class IRMember  {
private:
	TypeRef m_data_type;
	std::string m_name;
	size_t m_offset;
public:
	IRMember(const TypeRef& ref_type, const std::string& f_name) : m_data_type{ ref_type }, m_name{ f_name }, m_offset{0} {}
	const TypeRef& get_data_type() const;
	const std::string get_field_name() const;
	size_t get_offset() const;
	void set_offset(size_t offset);
};