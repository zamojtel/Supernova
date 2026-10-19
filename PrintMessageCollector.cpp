
void PrintMessageCollector::print_called(const std::string& s) {
	m_messages.push_back(s);
}

const std::vector<std::string> PrintMessageCollector::get_messages() const {
	return m_messages;
}

void PrintMessageCollector::clear() {
	m_messages.clear();
}