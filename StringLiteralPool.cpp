
StringRef StringLiteralPool::get_or_add(const std::string& text) {
	auto it = m_literals.find(text);

	if (it != m_literals.end())
		return it->second;

	StringRef ref = m_storage.add_string(reinterpret_cast<const uint8_t*>(text.data()),text.size());
	m_literals.try_emplace(text,ref);
	return ref;
}