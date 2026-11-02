
class IRInvalidTypeConstructionException {
private:
	std::string m_msg;
public:
	IRInvalidTypeConstructionException();
	IRInvalidTypeConstructionException(const std::string& msg);
	std::string get_message();
};