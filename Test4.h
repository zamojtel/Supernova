
class Test4 {
private:
	int m_width;
	int m_height;
	int m_num_pixels;
	float m_thresh;
	float m_spill_limit;
	float m_gain;
	std::vector<float> m_fg_r;
	std::vector<float> m_fg_g;
	std::vector<float> m_fg_b;

	std::vector<float> m_bg_r;
	std::vector<float> m_bg_g;
	std::vector<float> m_bg_b;

	std::vector<float> m_out_r;
	std::vector<float> m_out_g;
	std::vector<float> m_out_b;

	std::vector<float> m_jit_out_r;
	std::vector<float> m_jit_out_g;
	std::vector<float> m_jit_out_b;
public:
	using ChromaFn = void(*)(float*, float*, float*, float*, float*, float*, float*, float*, float*, int, float, float, float);
	using SpecChromaFn = void(*)(float*, float*, float*, float*, float*, float*, float*, float*, float*);
	Test4(int width, int height, float thresh = 0.08f, float spill_limit = 0.02f, float gain = 1.15f);

	void run();
	void run_aot(ChromaFn fn);
	void run_simd_jit(ChromaFn fn);
	void run_specialized_jit(SpecChromaFn sfn);
	std::string generate_specialized_code();
	void clear_jit_output();
	bool verify_results() const;
};