
void Stopwatch::start() {
	m_start = Clock::now();
}

double Stopwatch::stop() {
	m_end = Clock::now();
	double seconds = std::chrono::duration<double,std::milli>(m_end - m_start).count();
	return seconds;
}