
class StringStorage {
private:
	std::vector<const uint8_t*> m_strings;
public:
	StringStorage();
	StringStorage(const StringStorage&) = delete;
	StringStorage& operator=(const StringStorage&) = delete;
	~StringStorage();

	StringRef add_string(const uint8_t* ptr, size_t byte_size);
};