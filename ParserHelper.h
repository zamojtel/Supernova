
class ParserHelper {
public:
	
	enum class IntegerLiteralBase {
		BINARY,
		OCTAL,
		HEXADECIMAL,
		DECIMAL,
	};

	enum class IntegerLiteralSuffix {
		None,
		U,
		L,
		UL
	};

	//uint8_t m_bit_mask;
	// 0 NONE 
	// 1 U
	// 2 L
	// 3 UL <-> LU

	struct ParsedIntegerLiteral {
		static constexpr unsigned int UNSIGNED_FLAG = 1;
		static constexpr unsigned int LONG_FLAG = 2;
		unsigned long long m_value;
		uint8_t m_suffix_bit_mask;
	};

	ConstantNode* parse_integer_literal(const std::string& str) {
		std::string cleaned_str;

		bool is_unsigned = false;
		bool is_long = false;

		for (char c : str) {
			if (c != '_')
				cleaned_str += c;
		}

		unsigned long long converted_value;
		std::string prefix = cleaned_str.substr(0, 2);
		size_t cleaned_str_size = cleaned_str.size();
		uint8_t suffix_bit_mask = 0;
		size_t suffix_len = 0;

		if (cleaned_str_size > 1)
		{
			char last_letter = cleaned_str[cleaned_str_size - 1];
			char next_to_last = cleaned_str[cleaned_str_size - 2];
			bool unsigned_suffix = false;
			bool long_suffix = false;
			if (last_letter == 'u' || last_letter == 'U') {
				is_unsigned = true;
			}
			else if (last_letter == 'l' || last_letter == 'L') {
				is_long = true;
			}

			if (next_to_last == 'u' || next_to_last == 'U') {
				if (is_unsigned == true) {
					throw std::runtime_error("error unsinged");
				}
				is_unsigned = true;
			}
			else if (next_to_last == 'l' || next_to_last == 'L') {
				if (is_long == true) {
					throw std::runtime_error("error long");
				}
				is_long = true;
			}

			if (is_long)
				suffix_bit_mask |= ParsedIntegerLiteral::LONG_FLAG;
			if (is_unsigned)
				suffix_bit_mask |= ParsedIntegerLiteral::UNSIGNED_FLAG;
		}

		IntegerLiteralBase base;

		if (prefix == "0b") {
			converted_value = std::strtoull(cleaned_str.data() + 2, nullptr, 2);
			base = IntegerLiteralBase::BINARY;
		}
		else if (prefix == "0o") {
			converted_value = std::strtoull(cleaned_str.data() + 2, nullptr, 8);
			base = IntegerLiteralBase::OCTAL;
		}
		else if (prefix == "0x") {
			converted_value = std::strtoull(cleaned_str.data() + 2, nullptr, 16);
			base = IntegerLiteralBase::HEXADECIMAL;
		}
		else {
			converted_value = std::strtoull(cleaned_str.data(), nullptr, 10);
			base = IntegerLiteralBase::DECIMAL;
		}

		ConstantValue cv;
		// napisac to jakoœ krócej 
		if (is_long && is_unsigned) {
			cv = ConstantValue{converted_value};
		}
		else if (is_long) {
			if (converted_value <= std::numeric_limits<int64_t>::max()) {
				int64_t casted_value = static_cast<int64_t>(converted_value);
				cv = ConstantValue{ casted_value };
			}
			else if (converted_value <= std::numeric_limits<uint64_t>::max()) {
				uint64_t casted_value = static_cast<uint64_t>(converted_value);
				cv = ConstantValue{ casted_value };
			}
		}
		else if (is_unsigned) {
			if (converted_value <= std::numeric_limits<uint32_t>::max()) {
				uint32_t casted_value = static_cast<uint32_t>(converted_value);
				cv = ConstantValue{ casted_value };
			}
			else if (converted_value <= std::numeric_limits<uint64_t>::max()) {
				uint64_t casted_value = static_cast<uint64_t>(converted_value);
				cv = ConstantValue{ casted_value };
			}
		}
		else {
			if (converted_value <= std::numeric_limits<int32_t>::max()) {
				int32_t casted_value = static_cast<int32_t>(converted_value);
				cv = ConstantValue{ casted_value };
			}
			else if (converted_value <= std::numeric_limits<uint32_t>::max()) {
				uint32_t casted_value = static_cast<uint32_t>(converted_value);
				cv = ConstantValue{ casted_value };
			}
			else if (converted_value <= std::numeric_limits<int64_t>::max()) {
				int64_t casted_value = static_cast<int64_t>(converted_value);
				cv = ConstantValue{ casted_value };
			}
			else if (converted_value <= std::numeric_limits<uint64_t>::max()) {
				uint64_t casted_value = static_cast<uint64_t>(converted_value);
				cv = ConstantValue{ casted_value };
			}
		}

		return new ConstantNode{ cv };
	}
};