

class TestInterpreterListener : public IRInterpreterListener {
private:
	size_t m_assertions_falied;
	size_t m_assertions_succeded;
	std::vector<std::string> m_printed_messages;
	std::vector<bool> m_results;
public:
	TestInterpreterListener() : m_assertions_falied{ 0 }, m_assertions_succeded{ 0 } {}

	void assertion_failed(size_t line_number, const std::string& error_msg) {
		m_assertions_falied++;
		std::string msg = std::format("{}: {}", line_number, error_msg);
		std::cout << msg << std::endl;
	}

	void assertion_succeded() {
		m_assertions_succeded++;
	}

	std::vector<bool>& get_results() {
		return m_results;
	}

	void print_called(const ConstantValue& v) override {
		std::string msg = v.to_string();
		std::cout << "PRINT: " << msg << std::endl;
		m_printed_messages.push_back(msg);
	}

	// no need for now
	void function_call_start(const std::vector<ConstantValue>& args, IRFunction* fn) override {}
	void function_call_end(IRFunction* fn, const ConstantValue& val) override {}

	size_t get_number_of_assertions_falied() { return m_assertions_falied; }
	std::vector<std::string>& get_messages() { return m_printed_messages; }
};

namespace fs = std::filesystem;
class Tester {
private:
	std::string m_source_dir;
	std::string m_expected_dir;
public:
	std::vector<std::string> read_expected_lines(const fs::path& file_path);
	Tester(const std::string& source_dir,const std::string& expected_dir);
	void run_all_tests(const std::vector<std::string>& test_names);
	bool run_single_test(const fs::path& source_file,const fs::path& expected_path);
	std::string read_entire_file(const fs::path& file_path);
};
