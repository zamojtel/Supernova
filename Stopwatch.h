
class Stopwatch {
private:
	using Clock = std::chrono::steady_clock;
	using TimePoint = std::chrono::time_point<Clock>;
	TimePoint m_start;
	TimePoint m_end;
public:
	void start();
	double stop();
};