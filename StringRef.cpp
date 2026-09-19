
StringRef::StringRef(const uint8_t* ptr) :m_data{ ptr } {}

size_t StringRef::get_bytes_length() const {
	uint32_t length;
	memcpy(&length, m_data, sizeof(length));
	return length;
}

const uint8_t* StringRef::get_data() const {
	return m_data+StringLayout::m_header_size;
}
const uint8_t* StringRef::get_object_address() const {
	return m_data;
}