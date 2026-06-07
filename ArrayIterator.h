
class ArrayIterator {
private:
	uint8_t* m_start;
	size_t m_current_index;
	uint8_t* m_current_address;
	TypeRef m_element_type;
	size_t m_element_size;
	size_t m_count;
public:
	ArrayIterator(uint8_t* start,TypeRef type);
	void next();
	size_t get_count();
	uint8_t* operator*() const;
	TypeRef get_element_type();
};