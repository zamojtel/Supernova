
IRExternalFunction::IRExternalFunction(const std::string& name,const TypeRef& return_type) : IRBaseFunction(name,{},return_type,IRBaseFunction::Kind::EXTERNAL), m_fn_ptr{ nullptr } {}

IRExternalFunction::IRExternalFunction(const std::string& name,void* fn_ptr, const TypeRef& return_type, const std::vector<TypeRef>& parameter_types, std::function<void(void**, void*)> caller) 
	: IRBaseFunction(name, parameter_types, return_type, IRBaseFunction::Kind::EXTERNAL), m_fn_ptr{ fn_ptr }, m_caller{caller}
{}

IROperandType IRExternalFunction::get_operand_type() const { return IROperandType::EXTERNAL_FUNCTION; }

IROperand IRExternalFunction::get_operand() { return IROperand{ this }; }
