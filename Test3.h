
class Test3 {
private:
	int m_n;
	std::vector<float> m_coef;
	Test3(const std::vector<float> coef);
	std::vector<float> m_signal;
	std::vector<float> m_output_signal;
	std::vector<Biquad> m_filters;
	std::vector<int> m_enabled;
	std::vector<float> m_state;
	std::vector<float> m_jit_output_signal;
public:
	using BiquadFn = void(*)(float*, float*, int, float*, int*, float*, int);
	using SpecBiquadFn = void(*)(float*, float*, int, float*);
	Test3(int n);
	void run();
	void generate_signal(size_t khz,size_t signal_length);
	void run_jit(BiquadFn fn);
	void run_specialized_jit(SpecBiquadFn sfn); 
	std::string generate_specialized_code();
	void reset_state();
	void clear_jit_outputs();
	void set_sparse_bands();
	bool verify_results() const;
};