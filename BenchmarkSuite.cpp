
BenchmarkSuite::BenchmarkSuite() {
	m_clang_sse2_dll = LoadLibraryA("ClangAOT_SSE2.dll");
	if (!m_clang_sse2_dll)
		throw std::runtime_error("could not load dll file");

	m_clang_avx2_dll = LoadLibraryA("ClangAOT_AVX2.dll");
	if (!m_clang_avx2_dll)
		throw std::runtime_error("could not load dll file");
}

BenchmarkSuite::~BenchmarkSuite() {
	if (m_clang_sse2_dll)
		FreeLibrary(m_clang_sse2_dll);

	if (m_clang_avx2_dll)
		FreeLibrary(m_clang_avx2_dll);
}

void BenchmarkSuite::run_sorting_baseline(const fs::path& tests_path) {
	Stopwatch stopwatch;

	int n = 1e4;
	std::vector<int> big_array(n);
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> pick_random(0, n);

	for (int& value : big_array)
		value = pick_random(generator);

	using SortFn = void(*)(int*, int);
	SupernovaCompiler bubble_sn;
	std::string bubble_sort_code = Tester::read_entire_file(tests_path /"Benchmarks" / "bubble_sort.txt");
	stopwatch.start();
	bubble_sn.compile(bubble_sort_code,false);
	IRDataTypeManager* dtm = bubble_sn.get_dtm();
	std::vector<TypeRef> bubble_sort_parameter_types = { dtm->add_pointer(dtm->get_int()) , dtm->get_int() };
	SortFn bubble_sort = bubble_sn.get_function<SortFn>("bubble_sort",bubble_sort_parameter_types);
	double bubble_compile_ms = stopwatch.stop();

	SupernovaCompiler merge_sn;
	std::string merge_sort_code = Tester::read_entire_file(tests_path / "Benchmarks" / "merge_sort.txt");
	stopwatch.start();
	merge_sn.compile(merge_sort_code,false);
	dtm = merge_sn.get_dtm();
	std::vector<TypeRef> merge_sort_parameter_types = { dtm->add_pointer(dtm->get_int()) , dtm->get_int() };
	SortFn merge_sort = merge_sn.get_function<SortFn>("merge_sort",merge_sort_parameter_types);
	double merge_compile_ms = stopwatch.stop();

	SortFn bubble_sort_aot_sse2 = load_dll_fn<SortFn>(m_clang_sse2_dll,"bubble_sort_aot");
	SortFn bubble_sort_aot_avx2 = load_dll_fn<SortFn>(m_clang_avx2_dll, "bubble_sort_aot");
	
	SortFn merge_sort_aot_sse2 = load_dll_fn<SortFn>(m_clang_sse2_dll,"merge_sort_aot");
	SortFn merge_sort_aot_avx2 = load_dll_fn<SortFn>(m_clang_avx2_dll, "merge_sort_aot");


	std::vector<int> bubble_working(n);
	auto reset_bubble = [&]() { bubble_working = big_array; };

	m_benchmarker.run_benchmark("Suite0_Sorting", "bubble_sort_MSVC", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { BenchmarkAlgorithms::bubble_sort2(bubble_working.data(), n); },reset_bubble);
	m_benchmarker.run_benchmark("Suite0_Sorting", "bubble_sort_aot_sse2", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { bubble_sort_aot_sse2(bubble_working.data(), n);  },reset_bubble);
	m_benchmarker.run_benchmark("Suite0_Sorting", "bubble_sort_aot_avx2", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { bubble_sort_aot_avx2(bubble_working.data(), n); },reset_bubble);
	m_benchmarker.run_benchmark("Suite0_Sorting", "bubble_sort_Supernova_JIT", bubble_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { bubble_sort(bubble_working.data(), n); }, reset_bubble);

	int n_merge = 200000;
	std::vector<int> merge_master(n_merge);
	for (int& value : merge_master)
		value = pick_random(generator);

	std::vector<int> merge_working(n_merge);
	auto reset_merge = [&]() { merge_working = merge_master; };

	m_benchmarker.run_benchmark("Suite0_Sorting", "merge_sort_MSVC", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { BenchmarkAlgorithms::merge_sort(merge_working.data(), n_merge); },reset_merge);
	m_benchmarker.run_benchmark("Suite0_Sorting", "merge_sort_aot_sse2", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { merge_sort_aot_sse2(merge_working.data(), n_merge);  },reset_merge);
	m_benchmarker.run_benchmark("Suite0_Sorting", "merge_sort_aot_avx2", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { merge_sort_aot_avx2(merge_working.data(), n_merge); },reset_merge);
	m_benchmarker.run_benchmark("Suite0_Sorting", "merge_sort_Supernova_JIT", merge_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { merge_sort(merge_working.data(), n_merge); }, reset_merge);
}

void BenchmarkSuite::run_convolution_2d(const fs::path& tests_path) {
	
	Stopwatch stopwatch;
	Test1::ConvFn conv_sse2 = load_dll_fn<Test1::ConvFn>(m_clang_sse2_dll, "convolve_2d_aot");
	Test1::ConvFn conv_avx2 = load_dll_fn<Test1::ConvFn>(m_clang_avx2_dll, "convolve_2d_aot");

	SupernovaCompiler conv_dense_sn;
	std::string conv_dense_code = Tester::read_entire_file(tests_path / "Benchmarks" / "convolve_2d.txt");

	stopwatch.start();
	conv_dense_sn.compile(conv_dense_code,false);
	IRDataTypeManager* dtm = conv_dense_sn.get_dtm();
	std::vector<TypeRef> conv_dense_parameter_types = { 
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),	
		dtm->get_int(),
		dtm->get_int(),
		dtm->add_pointer(dtm->get_float()),	
		dtm->get_int()
	};

	Test1::ConvFn conv_dense = conv_dense_sn.get_function<Test1::ConvFn>("convolve", conv_dense_parameter_types);
	double unspec_conv_dense_compile_ms = stopwatch.stop();

	Test1 test(1920,1080,5);
	SupernovaCompiler spec_conv_dense_ss;
	std::string spec_conv_dense_code = test.generate_specialized_code();
	stopwatch.start();
	spec_conv_dense_ss.compile(spec_conv_dense_code,false);
	dtm = spec_conv_dense_ss.get_dtm();

	std::vector<TypeRef> spec_conv_dense_parameter_types = {
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float())
	};

	Test1::SpecConvFn spec_conv_dense = spec_conv_dense_ss.get_function<Test1::SpecConvFn>("convolve_spec",spec_conv_dense_parameter_types);
	double spec_conv_dense_compile_ms = stopwatch.stop();

	m_benchmarker.run_benchmark("Suite1_Conv2D_Dense", "conv2d_dense_MSVC", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.convolve(); });
	test.clear_jit_outputs();
	m_benchmarker.run_benchmark("Suite1_Conv2D_Dense", "conv2d_dense_Clang_SSE2", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.convolve_jit(conv_sse2); });
	if (!test.verify_results())
		std::cout << "Wrong results " << std::endl;
	test.clear_jit_outputs();
	m_benchmarker.run_benchmark("Suite1_Conv2D_Dense", "conv2d_dense_Clang_AVX2", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.convolve_jit(conv_avx2); });
	if (!test.verify_results())
		std::cout << "Wrong results " << std::endl;
	test.clear_jit_outputs();
	m_benchmarker.run_benchmark("Suite1_Conv2D_Dense", "conv2d_dense_Supernova_Unspec", unspec_conv_dense_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.convolve_jit(conv_dense); });
	if (!test.verify_results()) {
		std::cout << "Wrong results " << std::endl;
	}
	test.clear_jit_outputs();
	m_benchmarker.run_benchmark("Suite1_Conv2D_Dense", "conv2d_dense_Supernova_Spec", spec_conv_dense_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.convolve_specialized_jit(spec_conv_dense); });
	if (!test.verify_results())
		std::cout << "Wrong results " << std::endl;
	test.clear_jit_outputs();

	test.set_sparse_kernel();

	SupernovaCompiler conv_sparse_sn;
	std::string conv_sparse_code = test.generate_specialized_code();
	stopwatch.start();
	conv_sparse_sn.compile(conv_sparse_code,false);
	dtm = conv_sparse_sn.get_dtm();
	std::vector<TypeRef> spec_conv_sparse_parameter_types = {
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float())
	};

	Test1::SpecConvFn spec_conv_sparse = conv_sparse_sn.get_function<Test1::SpecConvFn>("convolve_spec",spec_conv_sparse_parameter_types);
	double spec_conv_sparse_compile_ms = stopwatch.stop();

	m_benchmarker.run_benchmark("Suite1_Conv2D_Sparse", "conv2d_sparse_MSVC", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.convolve(); });
	test.clear_jit_outputs();
	m_benchmarker.run_benchmark("Suite1_Conv2D_Sparse", "conv2d_sparse_Clang_SSE2", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.convolve_jit(conv_sse2); });
	if (!test.verify_results())
		std::cout << "Wrong results " << std::endl;
	test.clear_jit_outputs();
	m_benchmarker.run_benchmark("Suite1_Conv2D_Sparse", "conv2d_sparse_Clang_AVX2", 0.0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.convolve_jit(conv_avx2); });
	if (!test.verify_results())
		std::cout << "Wrong results " << std::endl;
	test.clear_jit_outputs();
	// works with 
	m_benchmarker.run_benchmark("Suite1_Conv2D_Sparse", "conv2d_sparse_Supernova_Unspec", unspec_conv_dense_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.convolve_jit(conv_dense); });
	if (!test.verify_results()) 
		std::cout << "Wrong results " << std::endl;
	test.clear_jit_outputs();
	m_benchmarker.run_benchmark("Suite1_Conv2D_Sparse", "conv2d_sparse_Supernova_Spec", spec_conv_sparse_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.convolve_specialized_jit(spec_conv_sparse); });
	if (!test.verify_results())
		std::cout << "Wrong results " << std::endl;
	test.clear_jit_outputs();
}

void BenchmarkSuite::run_formula(const fs::path& tests_path) {
	int n = 1000000;
	std::vector<double> big_array(n);
	std::mt19937 generator(std::random_device{}());
	std::uniform_real_distribution<double> pick_random(-10.0,10.0);

	for (double& value : big_array)
		value = pick_random(generator);

	Test2 test2("(x * x * 0.5 + x * 1.25 - 0.75) / (x * x + 1.0)", big_array);

	Stopwatch stopwatch;
	SupernovaCompiler formula_sn;
	std::string specialized_code = test2.generate_specialized_code();
	stopwatch.start();
	formula_sn.compile(specialized_code,false);
	IRDataTypeManager* dtm = formula_sn.get_dtm();
	std::vector<TypeRef> parameter_types{
		dtm->get_double(),
	};

	Test2::FormulaFn formula_fn = formula_sn.get_function<Test2::FormulaFn>("fun",parameter_types);
	std::vector<TypeRef> map_array_parameter_type{ dtm->add_pointer(dtm->get_double()), dtm->add_pointer(dtm->get_double()), dtm->get_int() };
	Test2::MapArrayFn map_array_fn = formula_sn.get_function<Test2::MapArrayFn>("map_array", map_array_parameter_type);

	double spec_supernova_compile_ms = stopwatch.stop();

	std::string lua_code = test2.generate_lua_code();
	stopwatch.start();
	test2.compile_lua(lua_code);
	double lua_compile_ms = stopwatch.stop();

	m_benchmarker.run_benchmark("Suite2_Formula", "formula_Supernova_JIT", spec_supernova_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test2.run_formula_test(formula_fn); });
	m_benchmarker.run_benchmark("Suite2_Formula", "formula_Lua", lua_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test2.run_lua_test(); });
	if (!test2.verify_results()) 
		std::cout << "Wrong results" << std::endl;
	
	test2.clear_outputs();
	m_benchmarker.run_benchmark("Suite2_Formula", "formula_array_Supernova_JIT", spec_supernova_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test2.run_formula_array_test(map_array_fn); });
	m_benchmarker.run_benchmark("Suite2_Formula", "formula_array_Lua", lua_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test2.run_lua_array_test(); });
	test2.fetch_lua_array_output();
	
	if(!test2.verify_results())
		std::cout << "Wrong results" << std::endl;

}

void BenchmarkSuite::run_biquad_iir(const fs::path& tests_path) {
	Test3::BiquadFn biquad_sse2 = load_dll_fn<Test3::BiquadFn>(m_clang_sse2_dll, "biquad_cascade_aot");
	Test3::BiquadFn biquad_avx2 = load_dll_fn<Test3::BiquadFn>(m_clang_avx2_dll, "biquad_cascade_aot");

	Test3 test(8); 
	test.generate_signal(48, 20);
	auto reset = [&]() { test.reset_state(); };
	Stopwatch stopwatch;
	stopwatch.start();
	std::string code = test.generate_specialized_code();
	SupernovaCompiler spec_dense_biquad_sn;
	spec_dense_biquad_sn.compile(code,false);
	IRDataTypeManager* dtm = spec_dense_biquad_sn.get_dtm();
	std::vector<TypeRef> spec_dense_biquad_parameter_types{ dtm->add_pointer(dtm->get_float()), dtm->add_pointer(dtm->get_float()), dtm->get_int() ,dtm->add_pointer(dtm->get_float())};
	Test3::SpecBiquadFn spec_dense_biquad_fn = spec_dense_biquad_sn.get_function<Test3::SpecBiquadFn>("biquad_cascade_spec", spec_dense_biquad_parameter_types);
	double compile_spec_dense_biquad_ms = stopwatch.stop();

	SupernovaCompiler dense_biquad_sn;
	std::string dense_biquad_code = Tester::read_entire_file(tests_path / "Benchmarks" / "biquad_cascade.txt");

	stopwatch.start();
	dense_biquad_sn.compile(dense_biquad_code, false);
		dtm = dense_biquad_sn.get_dtm();
		std::vector<TypeRef> dense_biquad_parameter_types = {
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_float()),
		dtm->get_int(),
		dtm->add_pointer(dtm->get_float()),
		dtm->add_pointer(dtm->get_int()),
		dtm->add_pointer(dtm->get_float()),
		dtm->get_int()
	};
	Test3::BiquadFn biquad_unspec = dense_biquad_sn.get_function<Test3::BiquadFn>("biquad_cascade", dense_biquad_parameter_types);
	double dense_biquad_compile_ms = stopwatch.stop();

	m_benchmarker.run_benchmark("Suite3_Biquad_Dense", "biquad_dense_MSVC", 0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run(); }, reset);

	m_benchmarker.run_benchmark("Suite3_Biquad_Dense", "biquad_dense_Supernova_Unspec", dense_biquad_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_jit(biquad_unspec); }, reset);
	if (!test.verify_results()) 
		std::cout << "Wrong results\n";
	test.clear_jit_outputs();

	m_benchmarker.run_benchmark("Suite3_Biquad_Dense", "biquad_dense_Supernova_Spec", compile_spec_dense_biquad_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_specialized_jit(spec_dense_biquad_fn); }, reset);
	if (!test.verify_results()) 
		std::cout << "Wrong results\n";
	test.clear_jit_outputs();

	m_benchmarker.run_benchmark("Suite3_Biquad_Dense", "biquad_dense_Clang_SSE2",0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_jit(biquad_sse2); }, reset);
	if (!test.verify_results())
		std::cout << "Wrong results\n";
	test.clear_jit_outputs();

	m_benchmarker.run_benchmark("Suite3_Biquad_Dense", "biquad_dense_Clang_AVX2",0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_jit(biquad_avx2); }, reset);
	if (!test.verify_results())
		std::cout << "Wrong results\n";
	test.clear_jit_outputs();

	test.set_sparse_bands();

	stopwatch.start();
	std::string spec_code = test.generate_specialized_code();
	SupernovaCompiler spec_sparse_biquad_sn;
	spec_sparse_biquad_sn.compile(spec_code, false);
	dtm = spec_sparse_biquad_sn.get_dtm();
	std::vector<TypeRef> spec_sparse_biquad_parameter_types{ dtm->add_pointer(dtm->get_float()), dtm->add_pointer(dtm->get_float()), dtm->get_int() ,dtm->add_pointer(dtm->get_float()) };
	Test3::SpecBiquadFn spec_sparse_biquad_fn = spec_sparse_biquad_sn.get_function<Test3::SpecBiquadFn>("biquad_cascade_spec", spec_sparse_biquad_parameter_types);
	double compile_spec_sparse_biquad_ms = stopwatch.stop();


	m_benchmarker.run_benchmark("Suite3_Biquad_Sparse", "biquad_sparse_MSVC", 0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run(); }, reset);

	m_benchmarker.run_benchmark("Suite3_Biquad_Sparse", "biquad_sparse_Supernova_Unspec", dense_biquad_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_jit(biquad_unspec); }, reset);
	if (!test.verify_results())
		std::cout << "Wrong results\n";
	test.clear_jit_outputs();

	m_benchmarker.run_benchmark("Suite3_Biquad_Sparse", "biquad_sparse_Supernova_Spec", compile_spec_sparse_biquad_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_specialized_jit(spec_sparse_biquad_fn); }, reset);
	if (!test.verify_results())
		std::cout << "Wrong results\n";
	test.clear_jit_outputs();

	m_benchmarker.run_benchmark("Suite3_Biquad_Sparse", "biquad_Sparse_Clang_SSE2", 0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_jit(biquad_sse2); }, reset);
	if (!test.verify_results())
		std::cout << "Wrong results\n";
	test.clear_jit_outputs();

	m_benchmarker.run_benchmark("Suite3_Biquad_Sparse", "biquad_Sparse_Clang_AVX2", 0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_jit(biquad_avx2); }, reset);
	if (!test.verify_results())
		std::cout << "Wrong results\n";
	test.clear_jit_outputs();

}

void BenchmarkSuite::run_chroma_key_simd(const fs::path& tests_path) {
	Test4 test(1920,1080);

	Test4::ChromaFn chroma_key_sse2 = load_dll_fn<Test4::ChromaFn>(m_clang_sse2_dll, "chroma_key_aot");
	Test4::ChromaFn chroma_key_avx2 = load_dll_fn<Test4::ChromaFn>(m_clang_avx2_dll, "chroma_key_aot");

	SupernovaCompiler chroma_key_sn;
	std::string chroma_key_code = Tester::read_entire_file(tests_path / "Benchmarks" / "chroma_key.txt");
	Stopwatch stopwatch;
	stopwatch.start();
	chroma_key_sn.compile(chroma_key_code, false);
	IRDataTypeManager* dtm = chroma_key_sn.get_dtm();

	TypeRef vec8_ptr = dtm->add_pointer(dtm->add_array(dtm->get_float(), 8));
	std::vector<TypeRef> chroma_key_parameter_types = {
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		dtm->get_int(),
		dtm->get_float(),
		dtm->get_float(),
		dtm->get_float()
	};
	Test4::ChromaFn chroma_key_unspec = chroma_key_sn.get_function<Test4::ChromaFn>("chroma_key", chroma_key_parameter_types);
	double chroma_key_compile_ms = stopwatch.stop();

	stopwatch.start();
	SupernovaCompiler spec_chroma_key_sn;
	std::string spec_code = test.generate_specialized_code();
	spec_chroma_key_sn.compile(spec_code,false);
	dtm = spec_chroma_key_sn.get_dtm();
	vec8_ptr = dtm->add_pointer(dtm->add_array(dtm->get_float(), 8));
	std::vector<TypeRef> spec_chroma_key_parameter_types = {
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
		vec8_ptr,
	};

	Test4::SpecChromaFn chroma_key_spec = spec_chroma_key_sn.get_function<Test4::SpecChromaFn>("chroma_key_spec",spec_chroma_key_parameter_types);
	double spec_chroma_key_compile_ms = stopwatch.stop();

	m_benchmarker.run_benchmark("Suite4_Chroma_Key", "chroma_key_MSVC", 0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run(); });

	m_benchmarker.run_benchmark("Suite4_Chroma_Key","chroma_key_Unspec", chroma_key_compile_ms,WARMUP_RUNS,MEASURED_RUNS, [&]() { test.run_simd_jit(chroma_key_unspec); });
	if (!test.verify_results())
		std::cout << "Wrong results\n";
	test.clear_jit_output();

	m_benchmarker.run_benchmark("Suite4_Chroma_Key", "chroma_key_Supernova_Spec", spec_chroma_key_compile_ms, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_specialized_jit(chroma_key_spec); });
	if (!test.verify_results())
		std::cout << "Wrong results\n";
	test.clear_jit_output();

	m_benchmarker.run_benchmark("Suite4_Chroma_Key", "chroma_key_Clang_SSE2", 0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_aot(chroma_key_sse2); });
	if (!test.verify_results())
		std::cout << "Wrong results\n";
	test.clear_jit_output();

	m_benchmarker.run_benchmark("Suite4_Chroma_Key", "chroma_key_Clang_AVX2", 0, WARMUP_RUNS, MEASURED_RUNS, [&]() { test.run_aot(chroma_key_avx2); });
	if (!test.verify_results())
		std::cout << "Wrong results\n";
	test.clear_jit_output();
}

void BenchmarkSuite::run_all(const fs::path& tests_path, const std::string& csv_path) {
	run_sorting_baseline(tests_path);
	run_convolution_2d(tests_path);
	run_formula(tests_path);
	run_biquad_iir(tests_path);
	run_chroma_key_simd(tests_path);

	m_benchmarker.export_to_csv(csv_path);
	m_benchmarker.print_summary();
}