
class Interpreter {
private:
	IRProgram* m_ir_program = nullptr;
	IRFunction* m_current_function = nullptr;
	std::vector<IROperand> m_fn_arguments;
	std::vector<ConstantValue> m_global_variables;
	IRInterpreterListener* m_listener = nullptr;
	std::list<IRStackFrame> m_frames;
	IRStackFrame* m_current_frame = nullptr;
public:
	Interpreter(IRProgram *p,IRFunction *fn,std::vector<IROperand> &fn_arguments);
	ConstantValue execute_arithmetic_operation(const TypeRef& type, IROperation op, ConstantValue& cv1, ConstantValue& cv2);
	ConstantValue execute_cmp_operation(IROperation op, ConstantValue& cv1, ConstantValue& cv2);
	ConstantValue get_operand_value(const IROperand& op);
	IRStackFrame* add_frame(IRBasicBlock* blk, IRTriple* r_t,size_t triple_count , size_t l_var_count);
	void pop_frame();
	void start();
	template <class T>
	bool execute_cmp_operation(T cv1, T cv2, IROperation operation);
	template <class T>
	T execute_arithmetic_operation(T cv1, T cv2,IROperation operation);
	void set_listener(IRInterpreterListener *l);
	
};