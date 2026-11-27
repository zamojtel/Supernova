
RandomNumberGenerator::RandomNumberGenerator() : m_generator{ std::random_device{}() } {}

float RandomNumberGenerator::pick_from_a_to_b(float a, float b) {
	std::uniform_real_distribution<float> pick_random(a,b);
	return pick_random(m_generator);
}