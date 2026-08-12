
class Interpreter {
private:
	IRProgram* m_ir_program = nullptr;
	IRFunction* m_current_function = nullptr;
	std::vector<IROperand> m_fn_arguments;
	std::vector<ConstantValue> m_global_variables;
	IRInterpreterListener* m_listener = nullptr;
	std::list<IRStackFrame> m_frames;
	std::vector<uint8_t> m_meomory_for_gl_variables;
	IRStackFrame* m_current_frame = nullptr;
	IROperationExecutor m_operation_executor;
public:
	Interpreter(IRProgram *p,IRFunction *fn,std::vector<IROperand> &fn_arguments);
	ConstantValue get_operand_value(const IROperand& op);
	IRStackFrame* add_frame(IRBasicBlock* blk, IRTriple* r_t,size_t triple_count , size_t l_var_count,size_t total_size);
	void pop_frame();
	void start(IRFunction* fn);
	void set_listener(IRInterpreterListener *l);
	uint8_t* get_operand_address(IROperand op, bool ignore_reference = false);
	template <class To>
	std::optional<To> convert_value_to(ConstantValue& v) const;
};