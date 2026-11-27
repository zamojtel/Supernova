
class Biquad {
private:
	float m_b0 = 0.0f;
	float m_b1 = 0.0f;
	float m_b2 = 0.0f;
	float m_a1 = 0.0f;
	float m_a2 = 0.0f;
	float m_x1 = 0.0f;
	float m_x2 = 0.0f;
	float m_y1 = 0.0f;
	float m_y2 = 0.0f;
	std::vector<float> m_coef;
	bool m_enabled = true;
public:
	Biquad() = default;
	Biquad(float b0, float b1, float b2, float a1, float a2);
	inline float process(float x0);
	void reset();
	void set_coef(float b0, float b1, float b2, float a1, float a2);
	void generate_random_coef();
	bool is_enabled() const;
	void set_enabled(bool value);
	float get_b0();
	float get_b1();
	float get_b2();
	float get_a1();
	float get_a2();
	float get_x1();
	float get_x2();
	float get_y1();
	float get_y2();
};