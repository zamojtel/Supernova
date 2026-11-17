void Benchmarker::start_test(const std::string& test_name) {
	std::cout << "Starting test " << test_name << std::endl;
	BenchmarkResult benchmark_result{test_name};
	m_results.push_back(benchmark_result);
	m_stopwatch.start();
}

void Benchmarker::stop_test() {
	double elapsed = m_stopwatch.stop();
	m_longest_test_time_taken = std::max(m_longest_test_time_taken,elapsed);
	m_results.back().set_time_taken(elapsed);
}

void Benchmarker::print_summary() {
	std::sort(m_results.begin(), m_results.end(), [](const BenchmarkResult& br1, const BenchmarkResult& br2) { return br1.m_time_taken < br2.m_time_taken; });
	std::cout << "Tests from the shortest to the longest" << std::endl;
	for (size_t i = 0; i < m_results.size();i++)
		std::cout << m_results[i].m_test_name << " time taken " << m_results[i].m_time_taken <<" "<< (m_results[i].m_time_taken / m_longest_test_time_taken*1.0l)*100<< " % " << std::endl;
}

void Benchmarker::run_benchmark(const std::string& suite_name, const std::string& test_name, double compile_time_ms, int warmup_runs, int measured_runs, const std::function<void()>& fn,const std::function<void()>& before_each) {
	if (measured_runs <= 0)
		return;

	for (size_t i = 0; i < warmup_runs; i++) {
		if (before_each)
			before_each();
		fn();
	}

	Stopwatch stopwatch;
	std::vector<double> samples(measured_runs);
	for (size_t j = 0; j < measured_runs;j++) {
		if (before_each)
			before_each();

		stopwatch.start();
		fn();
		double elapsed_time = stopwatch.stop();
		samples[j] = elapsed_time;
	}

	std::sort(samples.begin(),samples.end());
	double sum = 0;
	for (double s : samples)
		sum += s;

	BenchmarkResult result(test_name);
	result.m_suite_name = suite_name;
	int mid = measured_runs / 2;
	
	result.m_compile_time_ms = compile_time_ms;
	result.m_median_exec_ms = measured_runs % 2 == 0 ? (samples[mid] + samples[mid - 1]) / 2 : samples[mid];
	result.m_mean_exec_ms = sum / measured_runs;
	result.m_min_exec_ms = samples[0];
	result.m_time_taken = result.m_median_exec_ms;

	// reading memory usage from windows
	size_t working_set_kb;
	size_t peak_ram_kb = 0;
	PROCESS_MEMORY_COUNTERS pmc{};
	if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
		working_set_kb = pmc.WorkingSetSize / 1024;
		peak_ram_kb = pmc.PeakWorkingSetSize / 1024;
	}

	result.m_peak_ram_kb_usage = peak_ram_kb;
	m_longest_test_time_taken = std::max(m_longest_test_time_taken,result.m_time_taken);
	m_results.push_back(result);
}

void Benchmarker::export_to_csv(const std::string& file_path) {
	std::ofstream file(file_path);
	if (!file.is_open())
		return;

	file << "suite,test_name,compile_ms,median_exec_ms,mean_exec_ms,min_exec_ms,peak_ram_kb\n";
	for (const auto& result : m_results) {
		file << result.m_suite_name << ","<<result.m_test_name<<","<< result.m_compile_time_ms << "," << result.m_median_exec_ms
			<< "," << result.m_mean_exec_ms << "," << result.m_min_exec_ms << "," << result.m_peak_ram_kb_usage << '\n';
	}
}