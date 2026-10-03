
class IRExternalFunction : public IRBaseFunction {
public:
	void* m_fn_ptr;
	std::function<void(void**, void*)> m_caller;
	IRExternalFunction(const std::string& name,const TypeRef& return_type);
	// wskazniki do argumentow, wskaznik do wartoœci zwracanej
	// std::function<void(void**,void*)>
	IRExternalFunction(const std::string& name,void* fn_ptr, const TypeRef& return_type, const std::vector<TypeRef>& parameter_types, std::function<void(void**, void*)> caller);
	std::vector<TypeRef> get_paramater_type();
	IROperandType get_operand_type() const override;
	IROperand get_operand() override;
};