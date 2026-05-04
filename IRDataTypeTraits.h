


//// integers 
// INT8, // 0
// INT16, // 1 
// INT32, // 2 
// INT64, // 3
// UINT8, // 4
// UINT16, // 5
// UINT32, // 6
// UINT64, // 7
//// floating point values 
// FLOAT, // 8
// DOUBLE, // 9
//// boolean
// BOOL, // 10
// STRING // 11
// ERROR, // 12
// VOID, // 13

// 0 it will hold the information about a single type of data
struct IRDataTypeTraits {
	// size in bytes 
	int size;
	static bool is_floating_point(IRBasicType type);
	static bool is_integer(IRBasicType type);
	static bool is_boolean(IRBasicType type);
	static bool is_unsigned(IRBasicType type);
	static bool is_signed(IRBasicType type);

	static std::string get_name(const IRBasicType type);
};


extern std::array<const IRDataTypeTraits,(size_t)IRBasicType::NUMBER_OF_TYPES> ir_data_type_traits;