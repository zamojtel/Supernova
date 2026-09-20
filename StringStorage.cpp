
StringStorage::StringStorage() {}

StringRef StringStorage::add_string(const uint8_t* ptr,size_t byte_size) {
	if (byte_size > (std::numeric_limits<uint32_t>::max)() || byte_size > (std::numeric_limits<size_t>::max)() - 1)
		throw std::runtime_error("string is too long");
	
	uint32_t length = static_cast<uint32_t>(byte_size);

	uint8_t* new_string = new uint8_t[length+1];
	if(byte_size!=0)
		memcpy(new_string,ptr,length);

	new_string[byte_size] = '\0';

	try {
		m_strings.push_back(new_string);
	}
	catch (...) {
		delete[] new_string;
		throw;
	}

	return { new_string };
}

StringStorage::~StringStorage() {
	for (size_t i = 0; i < m_strings.size();i++)
		delete[] m_strings[i];
}