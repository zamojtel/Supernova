enum class MatchStatus {
	NO_MATCH,
	AMBIGUOUS,
	RESOLVED,
};

class OverloadMatch {
private:
	MatchStatus m_status;
	IRFunction* m_fn;
public:
	OverloadMatch();
	OverloadMatch(MatchStatus s, IRFunction* fn);
	bool is_valid();
	IRFunction* get_function();
	MatchStatus get_status();
};