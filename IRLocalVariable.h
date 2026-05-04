

class IRLocalVariable : public IRVariable {
private:
public:
	IRLocalVariable(const std::string& i,const TypeRef& t, size_t in) : IRVariable{ i,t,in } {};
	bool is_global() const { return false; }
};
