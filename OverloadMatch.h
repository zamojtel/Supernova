enum class MatchStatus {
	NO_MATCH,
	AMBIGUOUS,
	RESOLVED,
};

class OverloadMatch {
private:
	MatchStatus m_status;
	IRBaseFunction* m_fn;
public:
	OverloadMatch();
	OverloadMatch(MatchStatus s, IRBaseFunction* fn);
	bool is_valid();
	IRBaseFunction* get_function();
	MatchStatus get_status();
};