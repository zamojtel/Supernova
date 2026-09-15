OverloadMatch::OverloadMatch(MatchStatus s, IRFunction* fn) : m_status{ s }, m_fn{fn} {}

OverloadMatch::OverloadMatch() : m_status{MatchStatus::NO_MATCH}, m_fn{nullptr} {}

bool OverloadMatch::is_valid() {
	return m_status == MatchStatus::RESOLVED && m_fn != nullptr;
}

MatchStatus OverloadMatch::get_status() { return m_status; }

IRFunction* OverloadMatch::get_function(){ return m_fn; }