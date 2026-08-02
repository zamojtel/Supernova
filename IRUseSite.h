
class IRUseSite {
private:
	friend class IRUsedObject;
	IRTriple* m_triple;
	size_t m_operand_index;
public:
	IRUseSite(IRTriple* t,size_t op_i);
};