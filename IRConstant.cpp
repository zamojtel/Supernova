
IRConstant::IRConstant(size_t i, const ConstantValue& cv, const TypeRef& ref) :m_index{ i }, m_constant_value{ cv }, m_data_type{ref} {}

const TypeRef& IRConstant::get_data_type() const { return m_data_type; }

const ConstantValue& IRConstant::get_value() { return m_constant_value; }

size_t IRConstant::get_index() const { return m_index; }