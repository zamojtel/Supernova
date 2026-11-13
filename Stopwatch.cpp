
void Stopwatch::start() {
	m_start = Clock::now();
}

double Stopwatch::stop() {
	TimePoint end = Clock::now();
	double milliseconds = std::chrono::duration<double,std::milli>(end - m_start).count();
	return milliseconds;
}