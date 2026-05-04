
class IRCompositeTypeNode : public IRDataTypeNode {
private:
	std::string m_name;
	std::vector<IRMember*> m_field_list;
	bool m_is_finished;
public:
	IRCompositeTypeNode(const std::string& name);
	void add_field(const TypeRef& ref_type, const std::string& f_name);
	std::string get_name() const;
	size_t calculate_size() override;
	IRMember* get_member(const std::string& field_name) const;
	void close();
};

	// 'member
	//	remember
	//	pamietam

	//	'member
	//	'mietam

	//class Member {
	//private:
	//	TypeRef m_ref_type;
	//	std::string m_name;
	//public:
	//	Member(const TypeRef& ref_type, const std::string& f_name) : m_ref_type{ ref_type }, m_name{ f_name } {}
	//};