
StringRef::StringRef() :m_data{ nullptr } {}

StringRef::StringRef(const uint8_t* ptr) :m_data{ ptr } {}

size_t StringRef::get_bytes_length() const {
	const uint8_t* p = m_data;
	size_t length = 0;
	while (*p!='\0') {
		length++;
		p++;
	}

	return length;
}

const uint8_t* StringRef::get_data() const {
	return m_data;
}

uint8_t* StringRef::get_pointer_address() {
	return reinterpret_cast<uint8_t*>(&m_data);
}