
class IRConstant {
private:
	size_t m_index;
	ConstantValue m_constant_value;
	TypeRef m_data_type;
public:
	IRConstant(size_t index,const ConstantValue& cv,const TypeRef& ref);
	const ConstantValue& get_value();
	const TypeRef& get_data_type() const;
	size_t get_index() const;
};