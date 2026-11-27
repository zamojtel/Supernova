
Test2::Test2(const std::string& formula, std::vector<double>& v) : m_formula{ formula }, m_input{v}, m_jit_output(v.size()), m_lua_output(v.size()) {
	m_L = luaL_newstate();
	luaL_openlibs(m_L);
	// plus co robi co
	int n = static_cast<int>(m_input.size());
	// tworzymy tablicê o rozmiarze n (l¹duje na szczycie stosu: -1)
	lua_createtable(m_L, n, 0);
	for (int i = 0; i < n; ++i) {
		lua_pushnumber(m_L, m_input[i]); // liczba wchodzi na -1, tablica przesuwa siê na -2
		lua_rawseti(m_L, -2, i + 1);     // tablica[i + 1] = liczba (i zdejmuje liczbê ze stosu)
	}
	lua_setglobal(m_L, "input_arr");     // zapisuje tablice jako globalna "input_arr" i zdejmuje ze stosu

	// tworzymy pusta tablicê na wyniki jako "output_arr"
	lua_createtable(m_L, n, 0);
	lua_setglobal(m_L, "output_arr");
}

Test2::~Test2() {
	lua_close(m_L);
}

std::string Test2::generate_specialized_code() const {
	std::string code = std::format(R"(
			inline double fun(double x) {{
				return {0} ;
			}}
			
			void map_array(double* in_arr, double* out_arr, int n) {{
				for(int i=0;i<n;i++) {{
					out_arr[i] = fun(in_arr[i]);
				}}
			}}
		)", m_formula);
	return code;
}

std::string Test2::generate_lua_code() const {
	std::string code = std::format(R"(
		function fun(x)
			return {0} ;
		end

		function map_array(n)
			local inp = input_arr
			local outp = output_arr
			local f = fun
			for i = 1, n do
				outp[i] = f(inp[i])
			end
		end
	)",m_formula);

	return code;
}

void Test2::compile_lua(const std::string& code) {
	const char* c = code.data();
	if (luaL_dostring(m_L, c) != LUA_OK) {
		std::cerr << "Lua | compilation error : " << lua_tostring(m_L, -1) << "\n";
		lua_pop(m_L, 1);
	}
}

void Test2::run_lua_test() {
	lua_getglobal(m_L, "fun");
	int fn_idx = lua_gettop(m_L);
	for (size_t i = 0; i < m_input.size();i++) {
		lua_pushvalue(m_L,fn_idx);
		lua_pushnumber(m_L,m_input[i]);
		lua_call(m_L,1,1);

		m_lua_output[i] = lua_tonumber(m_L, -1);
		lua_pop(m_L,1);
	}
	lua_pop(m_L, 1);
}


void Test2::run_formula_test(FormulaFn fn) {
	for (size_t i = 0; i < m_input.size();i++)
		m_jit_output[i] = fn(m_input[i]);
}

const std::string& Test2::get_formula() const {
	return m_formula;
}

bool Test2::verify_results() {
	for (size_t i = 0; i < m_jit_output.size();i++) {
		if (std::abs(m_jit_output[i] - m_lua_output[i]) > 1e-9)
			return false;
	}

	return true;
}


void Test2::run_formula_array_test(MapArrayFn fn) {
	fn(m_input.data(),m_jit_output.data(),static_cast<int>(m_input.size()));
}

void Test2::run_lua_array_test() {
	lua_getglobal(m_L, "map_array");
	lua_pushinteger(m_L,static_cast<int>(m_input.size()));
	lua_call(m_L, 1, 0);
}

void Test2::fetch_lua_array_output() {
	lua_getglobal(m_L, "output_arr");
	for (size_t i = 0; i < m_lua_output.size();i++) {
		lua_rawgeti(m_L, -1, static_cast<lua_Integer>(i + 1));
		m_lua_output[i] = lua_tonumber(m_L, -1);
		lua_pop(m_L, 1);
	}

	lua_pop(m_L, 1);
}

void Test2::clear_outputs() {
	std::fill(m_jit_output.begin(),m_jit_output.end(),0.0);
	std::fill(m_lua_output.begin(),m_lua_output.end(),0.0);
}