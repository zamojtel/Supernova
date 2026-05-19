
class ConstantValue {
private:
	std::optional<IRBasicType> m_data_type;
	std::variant<uint8_t, uint16_t, uint32_t, uint64_t, int8_t, int16_t, int32_t, int64_t, float, double,bool> m_value;
	uint64_t m_data;
public:
	ConstantValue() {}
	// move to cpp file
	ConstantValue(IRBasicType type, const void* address) : m_data_type{ type } {
		switch (type)
		{
		case IRBasicType::INT8: {
			int8_t value = *reinterpret_cast<const int8_t*>(address);
			m_value = value;
			*reinterpret_cast<int8_t*>(&m_data) = value;
			break;
		}
		case IRBasicType::INT16: {
			int16_t value = *reinterpret_cast<const int16_t*>(address);
			m_value = value;
			*reinterpret_cast<int16_t*>(&m_data) = value;
			break;
		}
		case IRBasicType::INT32:
		{
			int32_t value = *reinterpret_cast<const int32_t*>(address);
			m_value = value;
			*reinterpret_cast<int32_t*>(&m_data) = value;
			break;
		}
		case IRBasicType::INT64:
		{
			int64_t value = *reinterpret_cast<const int64_t*>(address);
			m_value = value;
			*reinterpret_cast<int64_t*>(&m_data) = value;
			break;
		}
		case IRBasicType::UINT8:
		{
			uint8_t value = *reinterpret_cast<const uint8_t*>(address);
			m_value = value;
			*reinterpret_cast<uint8_t*>(&m_data) = value;
			break;
		}
		case IRBasicType::UINT16:
		{
			uint16_t value = *reinterpret_cast<const uint16_t*>(address);
			m_value = value;
			*reinterpret_cast<uint16_t*>(&m_data) = value;
			break;
		}
		case IRBasicType::UINT32:
		{
			uint32_t value = *reinterpret_cast<const uint32_t*>(address);
			m_value = value;
			*reinterpret_cast<uint32_t*>(&m_data) = value;
			break;
		}
		case IRBasicType::UINT64:
		{
			uint64_t value = *reinterpret_cast<const uint64_t*>(address);
			m_value = value;
			*reinterpret_cast<uint64_t*>(&m_data) = value;
			break;
		}
		case IRBasicType::FLOAT:
		{
			float value = *reinterpret_cast<const float*>(address);
			m_value = value;
			*reinterpret_cast<float*>(&m_data) = value;
			break;
		}
		case IRBasicType::DOUBLE:
		{
			double value = *reinterpret_cast<const double*>(address);
			m_value = value;
			*reinterpret_cast<double*>(&m_data) = value;
			break;
		}
		case IRBasicType::BOOL:
		{
			bool value = *reinterpret_cast<const bool*>(address);
			m_value = value;
			*reinterpret_cast<bool*>(&m_data) = value;
			break;
		}
		case IRBasicType::VOID:
			break;
		case IRBasicType::NUMBER_OF_TYPES:
			break;
		default:
			throw std::runtime_error("type is not allowed");
			break;
		}
	}

	ConstantValue(uint8_t v) :m_data_type{ IRBasicType::UINT8 }, m_value{ v } { *reinterpret_cast<uint8_t*>(&m_data) = v; }
	ConstantValue(uint16_t v) :m_data_type{ IRBasicType::UINT16 }, m_value{ v } { *reinterpret_cast<uint16_t*>(&m_data) = v; }
	ConstantValue(uint32_t v) :m_data_type{ IRBasicType::UINT32 }, m_value{ v } { *reinterpret_cast<uint32_t*>(&m_data) = v; }
	ConstantValue(uint64_t v) :m_data_type{ IRBasicType::UINT64 }, m_value{ v } { *reinterpret_cast<uint64_t*>(&m_data) = v; }
	ConstantValue(int8_t v) :m_data_type{ IRBasicType::INT8 }, m_value{ v } { *reinterpret_cast<int8_t*>(&m_data) = v; }
	ConstantValue(int16_t v) :m_data_type{ IRBasicType::INT16 }, m_value{ v } { *reinterpret_cast<int16_t*>(&m_data) = v; }
	ConstantValue(int32_t v) :m_data_type{ IRBasicType::INT32 }, m_value{ v } { *reinterpret_cast<int32_t*>(&m_data) = v; }
	ConstantValue(int64_t v) :m_data_type{ IRBasicType::INT64 }, m_value{ v } { *reinterpret_cast<int64_t*>(&m_data) = v; }
	ConstantValue(float v) :m_data_type{ IRBasicType::FLOAT }, m_value{ v } { *reinterpret_cast<float*>(&m_data) = v; }
	ConstantValue(double v) :m_data_type{ IRBasicType::DOUBLE }, m_value{ v } { *reinterpret_cast<double*>(&m_data) = v; }
	ConstantValue(bool v) :m_data_type{ IRBasicType::BOOL }, m_value{ v } { *reinterpret_cast<bool*>(&m_data) = v; }

	template <class T>
	static ConstantValue from_optional(const std::optional<T> &v) 
	{
		if (v.has_value())
			return ConstantValue(v.value());
		else
			throw std::runtime_error("can't convert from empty optional");
	}

	template <class To>
	std::optional<To> convert_value_to() const {
		if (!is_empty())
			throw std::runtime_error("no type has been set");

		switch (m_data_type.value())
		{
		case IRBasicType::INT8:
			return { safe_numeric_cast<To>(get_value<int8_t>()) };
		case IRBasicType::INT16:
			return { safe_numeric_cast<To>(get_value<int16_t>()) };
		case IRBasicType::INT32: {
			int32_t value = get_value<int32_t>();
			return { safe_numeric_cast<To>(value) };
		}
		case IRBasicType::INT64:
			return { safe_numeric_cast<To>(get_value<int64_t>()) };
		case IRBasicType::UINT8:
			return { safe_numeric_cast<To>(get_value<uint8_t>()) };
		case IRBasicType::UINT16:
			return { safe_numeric_cast<To>(get_value<uint16_t>()) };
		case IRBasicType::UINT32:
			return { safe_numeric_cast<To>(get_value<uint32_t>()) };
		case IRBasicType::UINT64:
			return { safe_numeric_cast<To>(get_value<uint64_t>()) };
		case IRBasicType::FLOAT:
			return { safe_numeric_cast<To>(get_value<float>()) };
		case IRBasicType::DOUBLE:
			return { safe_numeric_cast<To>(get_value<double>()) };
		case IRBasicType::BOOL:
			return { safe_numeric_cast<To>(get_value<bool>()) };
		case IRBasicType::VOID: {
			break;
		}
		default:
			break;
		}
	}

	template <class T>
	T get_value() const {
		if(std::holds_alternative<T>(m_value))
			return std::get<T>(m_value);
		else {
			std::string msg = std::string("can't get value of type: ") + typeid(T).name();
			throw std::runtime_error(msg);
		}
	}

	bool is_empty() const {
		return m_data_type.has_value();
	}

	IRBasicType get_basic_type() const {
		return m_data_type.value();
	}

	ConstantValue convert(IRBasicType convert_to) const;
	// move to cpp 
	std::string to_string() const;

	//uint8_t* get_address() const;
	const uint8_t* get_address() const;
};


std::ostream& operator<<(std::ostream& o, const ConstantValue& val) {
	o << val.to_string();
	return o;
}