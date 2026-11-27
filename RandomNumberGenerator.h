
class RandomNumberGenerator {
private:
	std::mt19937 m_generator;
public:
	RandomNumberGenerator();
	float pick_from_a_to_b(float a, float b);
};