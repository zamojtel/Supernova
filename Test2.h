
class Test2 {
private:
	std::string m_formula;
	lua_State* m_L = nullptr;
	std::vector<double> m_input;
	std::vector<double> m_jit_output; 
	std::vector<double> m_lua_output; 
public:
	using FormulaFn = double(*)(double);
	Test2(const std::string& formula,std::vector<double>& v);
	Test2(const Test2&) = delete;
	~Test2();
	std::string generate_specialized_code() const;
	std::string generate_lua_code() const;
	void compile_lua(const std::string& code);
	void run_lua_test();
	void run_formula_test(FormulaFn fn);
	bool verify_results();
	const std::string& get_formula() const;

	using MapArrayFn = void(*)(double*,double*,int);
	void run_formula_array_test(MapArrayFn fn);
	void run_lua_array_test();
	void fetch_lua_array_output();
	void clear_outputs();
};
//const char* code = R"(
//    function fun(x)
//        return x * 2
//    end
//)";
