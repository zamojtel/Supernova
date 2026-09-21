
// move to another file
template <class To, class From>
std::optional<To> safe_numeric_cast(From value) {
    static_assert(std::is_arithmetic_v<From>, "From must be arithmetic");
    static_assert(std::is_arithmetic_v<To>, "To must be arithmetic");

    if constexpr (std::is_integral_v<From> && std::is_integral_v<To>) {
        if constexpr (std::is_signed_v<From> == std::is_signed_v<To>) {
            From s1 = static_cast<From>(std::numeric_limits<To>::min());
            From s2 = static_cast<From>(std::numeric_limits<To>::max());

            if (value < s1 ||
                value > s2 ){
                return std::nullopt;
            }
        }
     
        else if constexpr (std::is_signed_v<From> && !std::is_signed_v<To>) {
            if (value < 0) {
                return std::nullopt;
            }
            using UFrom = std::make_unsigned_t<From>;
            if (static_cast<UFrom>(value) >
                static_cast<UFrom>(std::numeric_limits<To>::max())) {
                return std::nullopt;
            }
        }

        else {
            using UTo = std::make_unsigned_t<To>;
       
            if (value >
                static_cast<UTo>(std::numeric_limits<To>::max())) {
                return std::nullopt;
            }
        }

        return static_cast<To>(value);
    }

    else if constexpr (std::is_floating_point_v<From> && std::is_integral_v<To>) {
        if (!std::isfinite(value)) {
            return std::nullopt;
        }

        long double v = static_cast<long double>(value);

        if (v < static_cast<long double>(std::numeric_limits<To>::min()) ||
            v > static_cast<long double>(std::numeric_limits<To>::max())) {
            return std::nullopt;
        }

 
        if (std::trunc(v) != v) {
            return std::nullopt;
        }

        return static_cast<To>(value);
    }


    else if constexpr (std::is_integral_v<From> && std::is_floating_point_v<To>) {
        // sprawdzamy tylko czy nie wyjdziemy w nieskoñczonoœæ po konwersji
        long double v = static_cast<long double>(value);

     
        if (v > static_cast<long double>(std::numeric_limits<To>::max()) ||
            v < -static_cast<long double>(std::numeric_limits<To>::max())) {
            return std::nullopt; 
        }

        return static_cast<To>(value);
    }
  
    else if constexpr (std::is_floating_point_v<From> && std::is_floating_point_v<To>) {
        if (!std::isfinite(value)) {
            return std::nullopt; 
        }

        long double v = static_cast<long double>(value);
        if (v > static_cast<long double>(std::numeric_limits<To>::max()) ||
            v < -static_cast<long double>(std::numeric_limits<To>::max())) {
            return std::nullopt;
        }

        return static_cast<To>(value);
    }


    else {

        if constexpr (std::is_same_v<To, bool>) {
            return static_cast<bool>(value);
        }
        else if constexpr (std::is_same_v<From, bool>) {
            return static_cast<To>(value ? 1 : 0);
        }
        else {
  
            return static_cast<To>(value);
        }
    }
}

ConstantValue ConstantValue::unsafe_convert(IRBasicType convert_to) const {
    IRBasicType to = convert_to;

    switch (to)
    {
    case IRBasicType::INT8:
        return from_optional<int8_t>(unsafe_convert_value_to<int8_t>());
    case IRBasicType::INT16:
        return from_optional<int16_t>(unsafe_convert_value_to<int16_t>());
    case IRBasicType::INT32:
        return from_optional<int32_t>(unsafe_convert_value_to<int32_t>());
    case IRBasicType::INT64:
        return from_optional<int64_t>(unsafe_convert_value_to<int64_t>());
    case IRBasicType::UINT8:
        return from_optional<uint8_t>(unsafe_convert_value_to<uint8_t>());
    case IRBasicType::UINT16:
        return from_optional<uint16_t>(unsafe_convert_value_to<uint16_t>());
    case IRBasicType::UINT32:
        return from_optional<uint32_t>(unsafe_convert_value_to<uint32_t>());
    case IRBasicType::UINT64:
        return from_optional<uint64_t>(unsafe_convert_value_to<uint64_t>());
    case IRBasicType::FLOAT:
        return from_optional<float>(unsafe_convert_value_to<float>());
    case IRBasicType::DOUBLE:
        return from_optional<double>(unsafe_convert_value_to<double>());
    case IRBasicType::BOOL:
        return from_optional<bool>(unsafe_convert_value_to<bool>());
    case IRBasicType::VOID:
    default:
        throw std::runtime_error("can't convert value of this type");
        break;
    }
}

ConstantValue ConstantValue::safe_convert(IRBasicType convert_to) const {
    IRBasicType to = convert_to;

    switch (to)
    {
    case IRBasicType::INT8:
        return from_optional<int8_t>(safe_convert_value_to<int8_t>());
    case IRBasicType::INT16:
        return from_optional<int16_t>(safe_convert_value_to<int16_t>());
    case IRBasicType::INT32:
        return from_optional<int32_t>(safe_convert_value_to<int32_t>());
    case IRBasicType::INT64:
        return from_optional<int64_t>(safe_convert_value_to<int64_t>());
    case IRBasicType::UINT8:
        return from_optional<uint8_t>(safe_convert_value_to<uint8_t>());
    case IRBasicType::UINT16:
        return from_optional<uint16_t>(safe_convert_value_to<uint16_t>());
    case IRBasicType::UINT32:
        return from_optional<uint32_t>(safe_convert_value_to<uint32_t>());
    case IRBasicType::UINT64:
        return from_optional<uint64_t>(safe_convert_value_to<uint64_t>());
    case IRBasicType::FLOAT:
        return from_optional<float>(safe_convert_value_to<float>());
    case IRBasicType::DOUBLE:
        return from_optional<double>(safe_convert_value_to<double>());
    case IRBasicType::BOOL:
        return from_optional<bool>(safe_convert_value_to<bool>());
    case IRBasicType::VOID:
    default:
        throw std::runtime_error("can't convert value of this type");
        break;
    }
}

std::string ConstantValue::to_string() const {
    if (!m_data_type.has_value())
        return "No value has been set";

    std::string msg;
    switch (get_basic_type())
    {
    case IRBasicType::BOOL: {
        msg = std::format("{}", std::to_string(get_value<bool>()));
        return msg;
    }
    case IRBasicType::DOUBLE: {

        double value = get_value<double>();
        if (std::floor(value) == value)
            return std::format("{:.0f}", value);

        msg = std::format("{}", value);
        return msg;
    }
    case IRBasicType::FLOAT: {
        float value = get_value<float>();
        if (std::floor(value) == value)
            return std::format("{:.0f}", value);

        msg = std::format("{}", value);
        return msg;
    }
    case IRBasicType::CHAR:
    {
        //std::string s{ get_value<char>() };
        return std::string(1, get_value<char>());
    }
    case IRBasicType::INT8:
        return std::to_string(get_value<int8_t>());
    case IRBasicType::INT16:
        return std::to_string(get_value<int16_t>());
    case IRBasicType::INT32:
        return std::to_string(get_value<int32_t>());
    case IRBasicType::INT64:
        return std::to_string(get_value<int64_t>());
    case IRBasicType::UINT8:
        return std::to_string(get_value<uint8_t>());
    case IRBasicType::UINT16:
        return std::to_string(get_value<uint16_t>());
    case IRBasicType::UINT32:
        return std::to_string(get_value<uint32_t>());
    case IRBasicType::UINT64:
        return std::to_string(get_value<uint64_t>());
    case IRBasicType::STRING: {
        const StringRef ref = get_value<StringRef>();
        return std::string(reinterpret_cast<const char *>(ref.get_data()),ref.get_bytes_length());
    }
    default:
        throw std::runtime_error("unknown type can't convert to string");
    }
}

uint8_t* ConstantValue::get_address() {
    return reinterpret_cast<uint8_t*>(&m_data);
}