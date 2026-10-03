
class FunctionNames {
public:
	static std::string get_internal_name(const std::string& name) {
		return m_internal_prefix+name;
	}
	static constexpr char m_global_fn[] = "_global_function";
	static constexpr char m_main_fn[] = "main";
private:
	static constexpr char m_internal_prefix[] = ".supernova.internal.";
};