
Biquad::Biquad(float b0, float b1, float b2, float a1, float a2) : m_b0{ b0 }, m_b1{ b1 }, m_b2{ b2 }, m_a1{ a1 }, m_a2{ a2 } {}

void Biquad::set_coef(float b0, float b1, float b2, float a1, float a2) {
	m_b0 = b0;
	m_b1 = b1;
	m_b2 = b2; 
	m_a1 = a1;
	m_a2 = a2;
}

float Biquad::process(float x0) {
	float y0 = m_b0 * x0 + m_b1 * m_x1 + m_b2 * m_x2 - m_a1 * m_y1 - m_a2 * m_y2;
	m_x2 = m_x1;
	m_x1 = x0;
	m_y2 = m_y1;
	m_y1 = y0;
	return y0;
}

void Biquad::reset() {
	m_x1 = 0;
	m_x2 = 0;
	m_y1 = 0;
	m_y2 = 0;
}

void Biquad::generate_random_coef() {
	RandomNumberGenerator generator;
	//float angle = generator.pick_from_a_to_b(1/100.0f,99/100.0f)*std::numbers::pi_v<float>;
	//float radius = generator.pick_from_a_to_b(1/100.0f,99/100.0f);
	float angle = generator.pick_from_a_to_b(0.15f, 0.85f)*std::numbers::pi_v<float>;
	float radius = generator.pick_from_a_to_b(0.30f,0.75f);
	float real = radius * std::cos(angle);
	float img = radius * std::sin(angle);
	m_a1 = -2 * real;
	m_a2 = real * real + img * img;
	// verify if it generates values correctly
	//m_b0 = generator.pick_from_a_to_b(0, 1.0);
	//m_b1 = generator.pick_from_a_to_b(0, 1.0);
	//m_b2 = generator.pick_from_a_to_b(0, 1.0);
	// to keep the amplitude after 8 filters always between [-1,1]
	m_b0 = generator.pick_from_a_to_b(-0.5f,0.5f) * (1.0f - m_a2) * 0.5f;
	m_b1 = generator.pick_from_a_to_b(-0.5f, 0.5f) * (1.0f - m_a2) * 0.5f;
	m_b2 = generator.pick_from_a_to_b(-0.5f, 0.5f) * (1.0f - m_a2) * 0.5f;
}

bool Biquad::is_enabled() const {
	return m_enabled;
}

void Biquad::set_enabled(bool value) {
	m_enabled = value;
}

float Biquad::get_b0() {
	return m_b0;
}

float Biquad::get_b1() {
	return m_b1;
}

float Biquad::get_b2() {
	return m_b2;
}

float Biquad::get_a1() {
	return m_a1;
}

float Biquad::get_a2() {
	return m_a2;
}

float Biquad::get_x1() {
	return m_x1;
}

float Biquad::get_x2() {
	return m_x2;
}

float Biquad::get_y1() {
	return m_y1;
}

float Biquad::get_y2() {
	return m_y2;
}