
enum class IROperation {
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	ASSIGN,
	INIT_ASSIGN,
	CAST,
	REINTERPRET_CAST,
	RETURN,
	FUNCTION_CALL,
	GT,
	GE,
	LT,
	LE,
	EQ,
	NEQ,
	// Copy helps mostly with post incrementation
	COPY,
	INC,
	DEC,
	BITWISE_AND,
	BITWISE_OR,
	BITWISE_XOR,
	JC, // jump if condition
	JMP, // unconditional jump
	// ARRAY ACCESS
	ADREESS_OF,
	DEREFERENCE,
	ARRAY_ACCESS,
	MEMBER_ACCESS,
	ASSERT,
	PRINT,
	SELECT,
};