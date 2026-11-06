
class Benchmarker {
private:
	Stopwatch m_stopwatch;
	double m_longest_test_time_taken=-1;
public:
	class BenchmarkResult {
	public:
		std::string m_test_name;
		double m_time_taken;
		BenchmarkResult() :m_test_name{ "unkown" }, m_time_taken{-1} {}
		BenchmarkResult(const std::string& test_name) :m_test_name{ test_name } {}
		void set_time_taken(double time_taken) { m_time_taken = time_taken; };
	};

	std::vector<BenchmarkResult> m_results;
	void start_test(const std::string& test_name);
	void stop_test();
	void print_summary();
};