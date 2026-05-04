class IRProgram;

class IRChecker {
private:
	IRCheckerListener* m_listener = nullptr;
	IRProgram* m_ir_program;
	IRDataTypeManager* m_dtm;
public:
	IRChecker(IRProgram* p);
	void check_triple(IRTriple* triple);
	bool check_operand_types(const IROperand& op1, const IROperand& op2) const;
	//bool check_data_type_size(IRBasicType type1,IRBasicType type2) const;
	bool check_data_type_size(const TypeRef& type1, const TypeRef& type2) const;
	//bool is_arithmetic_operation_possible(const TypeRef& r1,const TypeRef& r2) const;
	TypeRef check_arithmetic_operation_possible(IRTriple *triple) const;
	size_t get_number_of_operands_for_operation(IROperation op);
	void deduce_triple_data_type(IRTriple* triple);
	void set_listener(IRCheckerListener* listener);
	void check_function(IRFunction* fn);
};