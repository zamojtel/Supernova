
class BenchmarkSuite {
private:
	template <typename Fn>
	Fn load_dll_fn(HMODULE dll, const char* name) {
		if (!dll)
			throw std::runtime_error("DLL handle is null");

		FARPROC raw_addr = GetProcAddress(dll, name);
		if (!raw_addr)
			throw std::runtime_error(std::string("function not found in DLL: ") + name);

		return reinterpret_cast<Fn>(raw_addr);
	}

public:
	Benchmarker m_benchmarker;
	HMODULE m_clang_sse2_dll = nullptr;
	HMODULE m_clang_avx2_dll = nullptr;
	BenchmarkSuite();
	~BenchmarkSuite();
	void run_sorting_baseline(const fs::path& tests_path);
	void run_convolution_2d(const fs::path& tests_path);
	void run_formula(const fs::path& tests_path);
	void run_all(const fs::path& tests_path, const std::string& csv_path);
};