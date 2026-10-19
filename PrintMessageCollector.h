

class PrintMessageCollector : public PrintListener {
public:
	std::vector<std::string> m_messages;
	void print_called(const std::string& s) override;
	const std::vector<std::string> get_messages() const;
	void clear();
};