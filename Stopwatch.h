
class Stopwatch {
private:
	using Clock = std::chrono::steady_clock;
	using TimePoint = std::chrono::time_point<Clock>;
	TimePoint m_start;
public:
	void start();
	double stop();
};