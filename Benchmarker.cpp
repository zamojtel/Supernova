

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