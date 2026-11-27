
void Test1::apply_mask(const float* in,float * out,int row,int col,int width,int height,const float* kernel, int k) {
	int center_row = k;
	int center_col = k;
	int index = row * width + col;
	int kernel_position = 0;
	float result = 0;

	for (int row_pos = -k; row_pos <= k;row_pos++) {
		int current_row_in = row + row_pos;
		int current_col_in = col + - k;
		int current_index_in = current_row_in * width + current_col_in;
		size_t size = 2 * k + 1;

		for (int i = 0; i < size ;i++) {
			result += in[current_index_in] * kernel[kernel_position];
			kernel_position++;
			current_index_in++;
		}
	}

	out[index] = result;
}

void Test1::convolve() {
	int k = m_kernel_size / 2;
	for (int row = k; row < m_height-k;row++) {
		for (int col = k; col < m_width - k; col++) {
			apply_mask(m_red_canal.data(),m_red_output_canal.data(), row, col, m_width, m_height, m_kernel.data(), k);
			apply_mask(m_green_canal.data(),m_green_output_canal.data(), row, col, m_width, m_height, m_kernel.data(), k);
			apply_mask(m_blue_canal.data(),m_blue_output_canal.data(), row, col, m_width, m_height, m_kernel.data(), k);
		}
	}
}

void Test1::convolve_jit(ConvFn fn) {
	fn(m_red_canal.data(),m_green_canal.data(),m_blue_canal.data(),m_jit_red_out_canal.data(),m_jit_green_out_canal.data(),m_jit_blue_out_canal.data(),m_width,m_height,m_kernel.data(), m_kernel_size / 2);
}

bool Test1::verify_results() const {
	float epsilon = 1e-4f;
	bool same = true;
	for (size_t i = 0; i < m_height*m_width;i++) {
		float diff_red = std::abs(m_red_output_canal[i] - m_jit_red_out_canal[i]);
		float diff_blue = std::abs(m_blue_output_canal[i] - m_jit_blue_out_canal[i]);
		float diff_green = std::abs(m_green_output_canal[i] - m_jit_green_out_canal[i]);

		if(diff_red > epsilon || diff_blue > epsilon || diff_green > epsilon ){
			same = false;
			break;
		}
	}
	return same;
}

Test1::Test1(int width, int height, int kernel_size) : m_width{ width }, m_height{ height }, m_kernel_size{kernel_size} {
	size_t size = width * height;
	m_blue_canal.resize(size);
	m_green_canal.resize(size);
	m_red_canal.resize(size);
	m_alfa_canal.resize(size);

	m_blue_output_canal.resize(size);
	m_green_output_canal.resize(size);
	m_red_output_canal.resize(size);
	m_alfa_output_canal.resize(size);

	m_jit_blue_out_canal.resize(size);
	m_jit_green_out_canal.resize(size);
	m_jit_red_out_canal.resize(size);
	m_jit_alfa_out_canal.resize(size);

	std::mt19937 gen(42);
	std::uniform_real_distribution<float> dist(0.0f, 1.0f);

	m_kernel.resize(m_kernel_size*m_kernel_size);
	for (int index = 0; index < kernel_size*kernel_size; index++)
		m_kernel[index] = dist(gen);

	int index = 0;
	for (size_t i = 0; i < m_width; i++) {
		for (size_t j = 0; j < m_height; j++) {
			float r = dist(gen);
			float g = dist(gen);
			float b = dist(gen);
			float alfa = dist(gen);

			m_red_canal[index] = r;
			m_green_canal[index] = g;
			m_blue_canal[index] = b;
			m_alfa_canal[index] = alfa;
			index++;
		}
	}
}

// sepcialized version of the code
std::string Test1::generate_specialized_code() const {
	int k = m_kernel_size / 2;
	int row_limit = m_height - k;
	int col_limit = m_width - k;
	std::string kernel_ops;
	int kernel_pos = 0;

	// calculating 
	for (int row_pos = -k; row_pos <= k; row_pos++) {
		for (int col_pos = -k; col_pos <= k;col_pos++) {
			float w = m_kernel[kernel_pos++];
			if (std::abs(w) < 1e-7f)
				continue;
			int offset = row_pos * m_width + col_pos;
			char sign = (w >= 0.0f) ? '+' : '-';
			std::string index_expr;
			if (offset == 0)
				index_expr = "idx";
			else if (offset > 0)
				index_expr = std::format("idx + {}", offset);
			else
				index_expr = std::format("idx - {}", std::abs(offset));

			kernel_ops += std::format("result = result {} in[{}] * {:.6f}f;\n", sign, index_expr, std::abs(w));
		}
	}

	std::string code = std::format(R"(
		void convolve_spec_ch(float* in,float* out) {{
			for (int64 row = {0} ; row < {1} ; row++) {{
				for (int64 col = {0} ; col < {2} ; col++) {{
					int64 idx = row * {3} + col;
					float result = 0.0f;
					{4}
					out[idx] = result;
				}}
			}}
		}}

		void convolve_spec(float* r_in,float* g_in,float* b_in,float* r_out,float* g_out,float* b_out){{
			convolve_spec_ch(r_in,r_out);
			convolve_spec_ch(g_in,g_out);
			convolve_spec_ch(b_in,b_out);
		}}
		)",k,row_limit,col_limit,m_width,kernel_ops);
	return code;
}

void Test1::clear_jit_outputs() {
	std::fill(m_jit_red_out_canal.begin(), m_jit_red_out_canal.end(), 0.0f);
	std::fill(m_jit_green_out_canal.begin(), m_jit_green_out_canal.end(), 0.0f);
	std::fill(m_jit_blue_out_canal.begin(), m_jit_blue_out_canal.end(), 0.0f);
}

void Test1::convolve_specialized_jit(SpecConvFn fn) {
	fn(
		m_red_canal.data(),
		m_green_canal.data(),
		m_blue_canal.data(),
		m_jit_red_out_canal.data(),
		m_jit_green_out_canal.data(),
		m_jit_blue_out_canal.data()
	);
}

void Test1::set_sparse_kernel() {
	int k = m_kernel_size / 2;
	int index = 0;
	for (size_t i = 0; i < m_kernel_size;i++) {
		for (size_t j = 0; j < m_kernel_size;j++) {
			if (!(i == k || j == k)) 
				m_kernel[index] = 0;
			index++;
		}
	}
}