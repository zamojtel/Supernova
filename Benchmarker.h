
class Benchmarker {
private:
	Stopwatch m_stopwatch;
	double m_longest_test_time_taken=-1;
public:
	class BenchmarkResult {
	public:
		std::string m_test_name;
		std::string m_suite_name;
		double m_compile_time_ms = 0.0;
		double m_median_exec_ms = 0.0;
		double m_mean_exec_ms = 0.0;
		double m_min_exec_ms = 0.0;
		double m_time_taken = m_median_exec_ms;
		size_t m_peak_ram_kb_usage = 0;
		BenchmarkResult() :m_test_name{ "unkown" }, m_time_taken{-1} {}
		BenchmarkResult(const std::string& test_name) :m_test_name{ test_name } {}
		void set_time_taken(double time_taken) { m_time_taken = time_taken; };
	};

	std::vector<BenchmarkResult> m_results;
	// it will run a loop warmup_runs without a stoper
	// and then measured_runs with the stoper collecting samples
	// to a vector 
	void run_benchmark(const std::string& suite_name, const std::string& test_name, double compile_time_ms, int warmup_runs, int measured_runs, const std::function<void()>& fn, const std::function<void()>& before_each = nullptr);
	void export_to_csv(const std::string& file_path);
	void start_test(const std::string& test_name);
	void stop_test();
	void print_summary();
};