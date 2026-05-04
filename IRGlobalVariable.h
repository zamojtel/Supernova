
class IRGlobalVariable :public IRVariable {
private:
public:
	// move everything to cpp file 
	IRGlobalVariable(const std::string& i,const TypeRef& t, size_t in) : IRVariable{i,t,in} {};
	bool is_global() const { return true; }
};