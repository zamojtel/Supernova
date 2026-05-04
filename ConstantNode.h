
class ConstantNode : public AbstractSyntaxTreeNode {
private:
	friend class TreePrinter;
	ConstantValue m_constant_value;
public:

	ConstantNode(const ConstantValue &c_v) : AbstractSyntaxTreeNode{ TreeNodeType::CONSTANT }, m_constant_value{c_v} {}

	template <class T>
	T get_value() const {
		return m_constant_value.get_value<T>();
	}

	IRBasicType get_data_type() {
		return m_constant_value.get_basic_type();
	}

	const ConstantValue& get_constant_value() { return m_constant_value; }

};