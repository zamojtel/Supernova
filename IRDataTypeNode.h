
class IRDataTypeNode {
private:
	friend class TypeRef;
	size_t m_reference_count;
	std::optional<size_t> m_size;
public:
	IRDataTypeNode();
	virtual IRDataTypeNodeType get_node_type() const = 0;
	// set size in bytes
	void set_size(size_t size_in_bytes);
	std::optional<size_t> get_size();
	virtual size_t calculate_size() ;
	bool has_size() const;
};