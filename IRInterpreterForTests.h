
//class IRInterpreterImplForPrintTest : public IRInterpreterListener {
//private:
//	size_t m_assertions_falied;
//	size_t m_assertions_succeded;
//	std::vector<bool> m_assertion_results;
//	std::vector<std::string> m_messages;
//public:
//	IRInterpreterImplForPrintTest() : m_assertions_falied{ 0 }, m_assertions_succeded{ 0 } {}
//
//	void assertion_failed(size_t line_number, const std::string& error_msg) {
//		m_assertions_falied++;
//		std::string msg = std::format("{}: {}", line_number, error_msg);
//		std::cout << msg << std::endl;
//		m_assertion_results.push_back(false);
//	}
//
//	void assertion_succeded() {
//		m_assertions_succeded++;
//		m_assertion_results.push_back(true);
//	}
//
//	void print_called(const ConstantValue& v) override {
//		std::string msg = v.to_string();
//		m_messages.push_back(msg);
//	}
//
//	std::vector<bool>& get_results() {
//		return m_assertion_results;
//	}
//
//	size_t get_number_of_assertions_falied() { return m_assertions_falied; }
//	size_t get_asserts_passed() const { return m_assertions_succeded; }
//	size_t get_asserts_failed() const { return m_assertions_falied; }
//	std::vector<std::string>& get_messages() { return m_messages; }
//};

//class IRInterpreterImplForTest : public IRInterpreterListener {
//private:
//	size_t m_assertions_falied;
//	size_t m_assertions_succeded;
//	std::vector<bool> m_assertion_results;
//public:
//	IRInterpreterImplForTest() : m_assertions_falied{ 0 }, m_assertions_succeded{ 0 } {}
//
//	void assertion_failed(size_t line_number, const std::string& error_msg) {
//		m_assertions_falied++;
//		std::string msg = std::format("{}: {}", line_number, error_msg);
//		std::cout << msg << std::endl;
//		m_assertion_results.push_back(false);
//	}
//
//	void assertion_succeded() {
//		m_assertions_succeded++;
//		m_assertion_results.push_back(true);
//	}
//
//	//void print_called(const ConstantValue& v) override {
//	//	std::string msg = v.to_string();
//	//	m_messages.push_back(msg);
//	//}
//
//	std::vector<bool>& get_results() {
//		return m_assertion_results;
//	}
//	size_t get_number_of_assertions_falied() { return m_assertions_falied; }
//	size_t get_asserts_passed() const { return m_assertions_succeded; }
//	size_t get_asserts_failed() const { return m_assertions_falied; }
//};



class IRInterpreterForTests : public IRInterpreterListener {
	size_t m_assertions_falied;
	size_t m_assertions_succeded;
	std::vector<bool> m_assertion_results;
	std::vector<std::string> m_messages;
public:
	IRInterpreterForTests() : m_assertions_falied{ 0 }, m_assertions_succeded{ 0 } {}

	void assertion_failed(size_t line_number, const std::string& error_msg) {
		m_assertions_falied++;
		std::string msg = std::format("{}: {}", line_number, error_msg);
		std::cout << msg << std::endl;
		m_assertion_results.push_back(false);
	}

	void assertion_succeded() {
		m_assertions_succeded++;
		m_assertion_results.push_back(true);
	}

	void print_called(const ConstantValue& v) override {
		std::string msg = v.to_string();
		m_messages.push_back(msg);
	}

	std::vector<bool>& get_results() {
		return m_assertion_results;
	}

	size_t get_number_of_assertions_falied() { return m_assertions_falied; }
	size_t get_asserts_passed() const { return m_assertions_succeded; }
	size_t get_asserts_failed() const { return m_assertions_falied; }
	std::vector<std::string>& get_messages() { return m_messages; }
};