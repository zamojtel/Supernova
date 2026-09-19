
void test_string_storage() {
	std::cout << "\nFor testing\n";
	StringStorage storage;
	StringRef empty_string = storage.add_string(nullptr, 0);
	size_t length = empty_string.get_bytes_length();
	const uint8_t* result = empty_string.get_data();
	if (length == 0)
		std::cout << "String is empty\n";
	else
		std::cout << "wrong length of an empty string\n";

	const uint8_t abc[] = { 'a','b','c' };
	const StringRef ref1 = storage.add_string(abc, sizeof(abc));

	if (ref1.get_bytes_length() == 3) {
		if (memcmp(ref1.get_data(), abc, sizeof(abc)) == 0)
			std::cout << "ref1 string representation is correct!\n";
		else
			std::cout << "ref1 wrong represenatation\n";
	}
	else
		std::cout << "ref1 wrong length\n";

	//"Aą🙂"
	const uint8_t second_str_with_emoji[] = { 0x41, 0xC4, 0x85, 0xF0, 0x9F, 0x99, 0x82 };
	StringRef ref2 = storage.add_string(second_str_with_emoji, 7);

	if (ref2.get_bytes_length() == 7) {
		if (memcmp(ref2.get_data(), second_str_with_emoji, sizeof(second_str_with_emoji)) == 0)
			std::cout << "ref2 string representation is correct!\n";
		else
			std::cout << "ref2 string wrong representation\n";
	}
	else
		std::cout << "ref2 wrong length\n";

	const uint8_t with_zero[] = { 'a',0,'b' };
	const StringRef ref3 = storage.add_string(with_zero, sizeof(with_zero));
	if (ref3.get_bytes_length() != sizeof(with_zero) || memcmp(ref3.get_data(), with_zero, sizeof(with_zero)) != 0)
		throw std::runtime_error("Embedded zero test failed");

	std::cout << "embedded zero test passed" << std::endl;

	const uint8_t* original_address = ref1.get_data();

	for (size_t i = 0; i < 1000; i++) {
		std::string new_string = "string_" + std::to_string(i);
		storage.add_string(reinterpret_cast<const uint8_t*>(new_string.data()), new_string.size());
	}

	if (
		ref1.get_data() != original_address ||
		ref1.get_bytes_length() != sizeof(abc) ||
		memcmp(ref1.get_data(), abc, sizeof(abc)) != 0
		) {
		throw std::runtime_error("String stability test failed");
	}

	std::cout << "string stability test passed!\n";
}

void test_string_pool() {
	StringLiteralPool pool;
	const StringRef a = pool.get_or_add("abc");
	const StringRef b = pool.get_or_add("abc");
	const StringRef c = pool.get_or_add("xyz");

	if (a.get_data() != b.get_data()) {
		throw std::runtime_error("identical literals are not shared\n");
	}

	if (a.get_data() == c.get_data()) {
		throw std::runtime_error("Different literals share one object");
	}

	std::cout << "String literal pool test passed\n";
}