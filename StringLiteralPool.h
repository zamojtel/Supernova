
class StringLiteralPool {
private:
	StringStorage m_storage;
	std::unordered_map<std::string,StringRef> m_literals;
public:
	StringRef get_or_add(const std::string& text);
};