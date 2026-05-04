
class IRQualifiersNode : public IRDataTypeNode {
private:
public:
	static constexpr uint8_t CONST = 1;
	static constexpr uint8_t VOLATILE = 2;
	TypeRef m_element;
	uint8_t m_bit_mask;
	// 0 without 
	// 1 CONST
	// 2 VOLATILE
	// 3 CONST VOLATILE
	IRQualifiersNode(const TypeRef& e,uint8_t mask);
	IRDataTypeNodeType get_node_type() const override;
};