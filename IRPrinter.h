
class IRFunction;
class IRTriple;
class IRVariable;
class IRConstant;
class IROperand;
enum class IRBasicType;
enum class IROperation;

class IRPrinter {
private:
public:
	std::string ir_operation_to_string(const IROperation op) const;
	void print_variable(const IRVariable* v);
	void print_variables(const IRFunction& p);
	void print_ir_representation(IRProgram& p);
	void print_triple(IRTriple* triple);
	void print_constant(IRConstant* c) const;
	void print_operand(const IROperand& op) const;
	void print_errors(const IRErrorCollector& c);
	void print_all_data_types_with_size(IRProgram& p);
	void print_memory_layout_for_fn(const IRFunction* f) const;
	void print_memory_layout(const IRProgram& p) const;
};