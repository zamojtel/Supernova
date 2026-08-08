// AbstractSyntaxTreeTypes
enum class OperationType {
	ADD,
	SUB,
	DIV,
	MUL,
	MOD,
	GT, // >
	GE, // >=
	LT, // <
	LE, // <=
	EQ, // ==
	NEQ,   // !=
	BITWISE_AND, // &
	BITWISE_OR, // |
	BITWISE_XOR, // ^
	BITWISE_NOT, // ~
	LEFT_SHIFT,	// <<
	RIGHT_SHIFT, // >>
};