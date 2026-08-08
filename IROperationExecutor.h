
class IROperationExecutor {
private:
public:
	void execute_operation(const IROperation operation, const std::vector<TypeRef>& operands_types, const std::vector<uint8_t*>& operands, const TypeRef& res_type, uint8_t* res_addr);
	ConstantValue execute_arithmetic_operation(const TypeRef& type, IROperation op, ConstantValue& cv1, ConstantValue& cv2);
	void execute_shift_operation(const IRBasicType& bt_1, const IRBasicType& bt_2, const IROperation operation, uint8_t* op1, uint8_t* op2, uint8_t* res_addr);
	void execute_arithmetic_operation_on_addresses(const TypeRef& type, IROperation op, const uint8_t* cv1, const uint8_t* cv2, uint8_t* res_addr);
	ConstantValue execute_cmp_operation(IROperation op, ConstantValue& cv1, ConstantValue& cv2);
	template <class T>
	void execute_unary_operation(IROperation operation, uint8_t* op1, uint8_t* res_addr);
	void execute_unary_operation(IROperation operation, IRBasicType bt, uint8_t* op1, uint8_t* res_addr);

	template <class T>
	void exec_shift_operation(const IROperation operation, uint8_t* op1, uint64_t op2, uint8_t* res_addr);

	template <class T>
	bool execute_cmp_operation(T cv1, T cv2, IROperation operation);
	void execute_cmp_operation_on_addresses(IROperation op, const TypeRef& type, uint8_t* cv1, uint8_t* cv2, uint8_t* res_addr);

	template <class T>
	T execute_arithmetic_operation(T cv1, T cv2, IROperation operation);

	void execute_bitwise_operation(const IRBasicType& type, IROperation operation, const uint8_t* cv1, const uint8_t* cv2, uint8_t* res_addr);

	template <class T>
	T execute_bitwise_operation(T val_1, T val_2, IROperation operation);

	template <class To>
	std::optional<To> convert_value_to(ConstantValue& v) const;
};