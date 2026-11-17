
class Test1 {
private:
	int m_width;
	int m_height;
	int m_kernel_size;
	std::vector<float> m_red_canal;
	std::vector<float> m_green_canal;
	std::vector<float> m_blue_canal;
	std::vector<float> m_alfa_canal;

	std::vector<float> m_red_output_canal;
	std::vector<float> m_green_output_canal;
	std::vector<float> m_blue_output_canal;
	std::vector<float> m_alfa_output_canal;
	std::vector<float> m_kernel;

	std::vector<float> m_jit_red_out_canal;
	std::vector<float> m_jit_green_out_canal;
	std::vector<float> m_jit_blue_out_canal;
	std::vector<float> m_jit_alfa_out_canal;
public:
	using ConvFn = void(*)(float*, float*, float*, float*, float*, float*, int, int, float*, int);
	using SpecConvFn = void(*)(float*, float*, float*, float*, float*, float*);
	Test1(int width, int height, int kernel_size);
	void apply_mask(const float* in, float* out, int row, int col, int width, int height, const float* kernel, int k);
	void convolve();
	void convolve_jit(ConvFn fn);
	bool verify_results() const;
	std::string generate_specialized_code() const;
	void set_sparse_kernel();
	void convolve_specialized_jit(SpecConvFn fn);
	void clear_jit_outputs();
	// x * 2 + 1 - 5 * x 
};