
class Error {
private:
	//std::variant<IRError,SyntaxError,SemanticError> m_current_error;
	std::variant<IRError> m_current_error;
public:
	Error(const IRError& e) :m_current_error{ e } {};
};


