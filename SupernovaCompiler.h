
class SupernovaCompiler {
private:
	std::unique_ptr<llvm::orc::LLJIT> m_jit;
	bool m_verbose = true;
public:
	IRProgram m_ir_program;
	SupernovaCompiler();
	void compile(const std::string& source_code,bool verbose = true);
	template <class T>
	T get_function(const std::string& fn_name, const std::vector<TypeRef>& argument_types);
	IRDataTypeManager* get_dtm();
};