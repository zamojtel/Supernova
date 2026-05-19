
// move to another file
template <class To, class From>
std::optional<To> safe_numeric_cast(From value) {
    static_assert(std::is_arithmetic_v<From>, "From must be arithmetic");
    static_assert(std::is_arithmetic_v<To>, "To must be arithmetic");

    // ----- CASE 1: int -> int -----
    if constexpr (std::is_integral_v<From> && std::is_integral_v<To>) {
        // a) oba maj¹ ten sam "signedness"
        if constexpr (std::is_signed_v<From> == std::is_signed_v<To>) {
            From s1 = static_cast<From>(std::numeric_limits<To>::min());
            From s2 = static_cast<From>(std::numeric_limits<To>::max());

            if (value < s1 ||
                value > s2 ){
                return std::nullopt; // wyjœcie poza zakres typu docelowego
            }
        }
        // b) From signed, To unsigned
        else if constexpr (std::is_signed_v<From> && !std::is_signed_v<To>) {
            if (value < 0) {
                return std::nullopt; // liczba ujemna nie mieœci siê w typie bez znaku
            }
            using UFrom = std::make_unsigned_t<From>;
            if (static_cast<UFrom>(value) >
                static_cast<UFrom>(std::numeric_limits<To>::max())) {
                return std::nullopt;
            }
        }
        // c) From unsigned, To signed
        else { // (!signed_v<From> && signed_v<To>)
            using UTo = std::make_unsigned_t<To>;
            // dolna granica To jest <= 0, wiêc tylko górn¹ trzeba pilnowaæ
            if (value >
                static_cast<UTo>(std::numeric_limits<To>::max())) {
                return std::nullopt;
            }
        }

        return static_cast<To>(value);
    }

    // ----- CASE 2: float -> int -----
    else if constexpr (std::is_floating_point_v<From> && std::is_integral_v<To>) {
        if (!std::isfinite(value)) {
            return std::nullopt; // NaN / inf
        }

        long double v = static_cast<long double>(value);

        // sprawdŸ zakres
        if (v < static_cast<long double>(std::numeric_limits<To>::min()) ||
            v > static_cast<long double>(std::numeric_limits<To>::max())) {
            return std::nullopt;
        }

        // wymagamy, ¿eby wartoœæ by³a "ca³kowita" (¿eby nie ucinaæ czêœci u³amkowej)
        if (std::trunc(v) != v) {
            return std::nullopt;
        }

        return static_cast<To>(value);
    }

    // ----- CASE 3: int -> float -----
    else if constexpr (std::is_integral_v<From> && std::is_floating_point_v<To>) {
        // sprawdzamy tylko czy nie wyjdziemy w nieskoñczonoœæ po konwersji
        long double v = static_cast<long double>(value);

        // zakres dodatni i ujemny (float/double nie maj¹ sensownego min() sym.)
        if (v > static_cast<long double>(std::numeric_limits<To>::max()) ||
            v < -static_cast<long double>(std::numeric_limits<To>::max())) {
            return std::nullopt; // posz³oby w +/-inf
        }

        return static_cast<To>(value);
    }
    // ----- CASE 4: float -> float -----
    else if constexpr (std::is_floating_point_v<From> && std::is_floating_point_v<To>) {
        if (!std::isfinite(value)) {
            return std::nullopt; // NaN / inf
        }

        long double v = static_cast<long double>(value);
        if (v > static_cast<long double>(std::numeric_limits<To>::max()) ||
            v < -static_cast<long double>(std::numeric_limits<To>::max())) {
            return std::nullopt; // overflow po konwersji
        }

        return static_cast<To>(value);
    }

    // ----- CASE 5: bool i inne egzotyki -----
    else {
        // bool -> liczba i liczba -> bool s¹ zawsze bezpieczne semantycznie:
        // false -> 0, true -> 1
        if constexpr (std::is_same_v<To, bool>) {
            return static_cast<bool>(value);
        }
        else if constexpr (std::is_same_v<From, bool>) {
            return static_cast<To>(value ? 1 : 0);
        }
        else {
            // fallback (teoretycznie nie powinniœmy tu trafiæ,
            // bo pokryliœmy wszystkie arithmetic)
            return static_cast<To>(value);
        }
    }
}

ConstantValue ConstantValue::convert(IRBasicType convert_to) const {
    IRBasicType to = convert_to;

    switch (to)
    {
    case IRBasicType::INT8:
        return from_optional<int8_t>(convert_value_to<int8_t>());
    case IRBasicType::INT16:
        return from_optional<int16_t>(convert_value_to<int16_t>());
    case IRBasicType::INT32:
        return from_optional<int32_t>(convert_value_to<int32_t>());
    case IRBasicType::INT64:
        return from_optional<int64_t>(convert_value_to<int64_t>());
    case IRBasicType::UINT8:
        return from_optional<uint8_t>(convert_value_to<uint8_t>());
    case IRBasicType::UINT16:
        return from_optional<uint16_t>(convert_value_to<uint16_t>());
    case IRBasicType::UINT32:
        return from_optional<uint32_t>(convert_value_to<uint32_t>());
    case IRBasicType::UINT64:
        return from_optional<uint32_t>(convert_value_to<uint32_t>());
    case IRBasicType::FLOAT:
        return from_optional<float>(convert_value_to<float>());
    case IRBasicType::DOUBLE:
        return from_optional<double>(convert_value_to<double>());
    case IRBasicType::BOOL:
        return from_optional<bool>(convert_value_to<bool>());
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
        msg = std::format("{}",std::to_string(get_value<bool>()));
        //return std::to_string(get_value<bool>());
        return msg;
    }
    case IRBasicType::DOUBLE: {

        double value = get_value<double>();
        if (std::floor(value) == value)
            return std::format("{:.0f}", value);

        msg = std::format("{}",value);
        return msg;
    }
    case IRBasicType::FLOAT: {
        float value = get_value<float>();
        if (std::floor(value) == value)
            return std::format("{:.0f}", value);

        msg = std::format("{}", value);
        return msg;
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
    default:
        throw std::runtime_error("unknown type can't convert to string");
    }
}

//const uint8_t* ConstantValue::get_address() const {
//    return reinterpret_cast<uint8_t*>(m_data);
//}
const uint8_t* ConstantValue::get_address() const {
    return reinterpret_cast<const uint8_t*>(&m_data);
}