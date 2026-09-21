
class StringRef {
private:
	const uint8_t* m_data;
public:
	StringRef();
	StringRef(const uint8_t* ptr);
	size_t get_bytes_length() const;
	const uint8_t* get_data() const;
	uint8_t * get_pointer_address();
};