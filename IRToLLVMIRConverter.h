
class IRToLLVMIRConverter {
private:
	std::unique_ptr<llvm::LLVMContext> m_context;
	std::unique_ptr<llvm::Module> m_module;
	llvm::Function* m_current_fn{};
	llvm::IRBuilder<>* m_builder{};
	std::vector<llvm::BasicBlock*> m_llvm_basic_blocks;
	std::vector<llvm::Function*> m_llvm_functions;
	IRProgram *m_ir_program;
	const std::string m_prefix_for_function;

	std::vector<llvm::Constant*> m_llvm_constants;
	std::vector<llvm::GlobalVariable*> m_global_variables;
	//std::vector<llvm::Value*> m_variable_values;
	std::vector<llvm::Value*> m_variables;
	std::vector<llvm::Value*> m_triple_values;
public:
	IRToLLVMIRConverter(IRProgram* ir_prog);
	llvm::orc::ThreadSafeModule convert();
	void convert_function(IRFunction* current_fn);
	void create_llvm_function(IRFunction* current_fn);
	void create_llvm_basic_blocks(IRFunction* current_fn);
	llvm::Value* get_operand_value(const IROperand& op);
	llvm::Value* auto_cast(llvm::Value* src, llvm::Type* dstTy,bool srcIsSigned, bool dstIsSigned);
	void convert_arithmetic_operation(llvm::Instruction::BinaryOps op_code, IRTriple* triple);
	llvm::Type* get_llvm_type(IRBasicType type) const;
	llvm::Type* get_llvm_type(const TypeRef& type) const;
	llvm::CallInst* get_function_call_instance(IRTriple* triple, void* fn_address);
};