
	//IRToLLVMIRConverter
class IRToLLVMIRConverter {
private:
	// one module contains many functions
	llvm::Module* m_module{};
	// one to rule them all 
	llvm::LLVMContext* m_context{};
	llvm::Function* m_current_fn{};
	llvm::IRBuilder<>* m_builder{};
	std::vector<llvm::BasicBlock*> m_llvm_basic_blocks;
	// 
	std::vector<llvm::Function*> m_llvm_functions;
	IRProgram *m_ir_program;

	std::vector<llvm::Constant*> m_llvm_constants;
	std::vector<llvm::Value*> m_variable_values;
	// based on global_index its global position in the IR Rep.
	std::vector<llvm::Value*> m_triple_values;
public:
	//IRToLLVMIRConverter(IRProgram* ir_prog) : m_ir_program{ ir_prog },m_llvm_constants(ir_prog->get_constants().size()),m_variable_values(ir_prog->get_variables().size()){
	// Everything is within a function now, vars constants etc;
	IRToLLVMIRConverter(IRProgram* ir_prog) : m_ir_program{ ir_prog } {
		size_t counter = 0;
		auto& fn_map = m_ir_program->get_functions();
		for (auto &[name,vec_fn] : fn_map)
			counter += vec_fn.size();

		m_llvm_functions.resize(counter);

		int triples_count = 0;
	}

	void convert();
	void convert_function(IRFunction* current_fn);
	void create_llvm_function(IRFunction* current_fn);
	void create_llvm_basic_blocks(IRFunction* current_fn);
	llvm::Value* get_operand_value(const IROperand& op);
	//llvm::Value* auto_cast(llvm::IRBuilder<>& b, llvm::Value* src, llvm::Type* dstTy,bool srcIsSigned, bool dstIsSigned);
	llvm::Value* auto_cast(llvm::Value* src, llvm::Type* dstTy,bool srcIsSigned, bool dstIsSigned);
	void convert_arithmetic_operation(llvm::Instruction::BinaryOps op_code, IRTriple* triple);
	llvm::Type* get_llvm_type(IRBasicType type) const;
};