
class IROperand;

class IRTriple : public IRUsedObject {
private:
public:
	IRBasicBlock* m_basic_blk;
	TypeRef m_data_type;
	size_t m_line_number;
	size_t m_global_index;
	size_t m_index;
	std::vector<IROperand> m_operands;
	IROperation m_operation{IROperation::NO_OPERATION};
	// arguments for function call
	size_t m_local_mem_offset{0};

	IRTriple(IRBasicBlock* block, size_t line_number, size_t global_index, size_t local_index);

	size_t get_local_index();
	size_t get_global_index();
	const TypeRef& get_data_type() const;
	IROperation get_ir_operation() const;
	size_t get_line() const;
	std::vector<IROperand> get_function_call_arguments() const;
	size_t get_local_mem_offset() const;
	void set_data(IROperation operation, const std::vector<IROperand>& operands);
	void set_operand(size_t index, IROperand op);
	IROperandType get_operand_type() const;
	IROperand get_operand() override;
	void clear();
};
