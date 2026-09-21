
class IRConstant : public IRUsedObject {
private:
	size_t m_index;
	ConstantValue m_constant_value;
	StringRef m_string_ref;
	TypeRef m_data_type;
public:
	IRConstant(size_t index,const ConstantValue& cv,const TypeRef& ref);
	IRConstant(size_t index,const StringRef& str_ref,const TypeRef& ref);
	const ConstantValue& get_value();
	const StringRef& get_string_ref();
	const TypeRef& get_data_type() const;
	size_t get_index() const;
	IROperandType get_operand_type() const;
	IROperand get_operand() override;
	uint8_t* get_address();
};