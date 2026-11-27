
Test4::Test4(int width, int height, float thresh, float spill_limit, float gain) :m_width{ width }, m_height{ height }, m_thresh{ thresh }, m_spill_limit{ spill_limit }, m_num_pixels{ width * height }, m_gain{gain} {
	assert(m_num_pixels%8==0);
	m_fg_r.resize(m_num_pixels);
	m_fg_g.resize(m_num_pixels);
	m_fg_b.resize(m_num_pixels);
	
	m_bg_r.resize(m_num_pixels);
	m_bg_g.resize(m_num_pixels);
	m_bg_b.resize(m_num_pixels);

	m_out_r.resize(m_num_pixels);
	m_out_g.resize(m_num_pixels);
	m_out_b.resize(m_num_pixels);

	m_jit_out_r.resize(m_num_pixels);
	m_jit_out_g.resize(m_num_pixels);
	m_jit_out_b.resize(m_num_pixels);

	RandomNumberGenerator rng;
	for (size_t i = 0; i < m_num_pixels;i++) {
		m_fg_r[i] = rng.pick_from_a_to_b(0.0f, 1.0f);
		m_fg_g[i] = rng.pick_from_a_to_b(0.0f, 1.0f);
		m_fg_b[i] = rng.pick_from_a_to_b(0.0f, 1.0f);
		
		m_bg_r[i] = rng.pick_from_a_to_b(0.0f, 1.0f);
		m_bg_g[i] = rng.pick_from_a_to_b(0.0f, 1.0f);
		m_bg_b[i] = rng.pick_from_a_to_b(0.0f, 1.0f);
	}
}
//static void chroma_key(float* fg_r, float* fg_g, float* fg_b, float* bg_r, float* bg_g, float* bg_b, float* out_r, float* out_g, float* out_b, int num_pixels, float thresh, float spill_limit, float gain);
void Test4::run() {
	BenchmarkAlgorithms::chroma_key(m_fg_r.data(),m_fg_g.data(),m_fg_b.data(),m_bg_r.data(),m_bg_g.data(),m_bg_b.data(),m_out_r.data(),m_out_g.data(),m_out_b.data(),m_num_pixels,m_thresh,m_spill_limit,m_gain);
}

void Test4::run_aot(ChromaFn fn) {
	if (fn)
		fn(m_fg_r.data(), m_fg_g.data(), m_fg_b.data(), m_bg_r.data(), m_bg_g.data(), m_bg_b.data(), m_jit_out_r.data(), m_jit_out_g.data(), m_jit_out_b.data(), m_num_pixels, m_thresh, m_spill_limit, m_gain);
}

void Test4::run_simd_jit(ChromaFn fn) {
	if (fn)
		fn(m_fg_r.data(), m_fg_g.data(), m_fg_b.data(), m_bg_r.data(), m_bg_g.data(), m_bg_b.data(), m_jit_out_r.data(), m_jit_out_g.data(), m_jit_out_b.data(), m_num_pixels/8, m_thresh, m_spill_limit, m_gain);
}


void Test4::run_specialized_jit(SpecChromaFn sfn) {
	if (sfn)
		sfn(m_fg_r.data(), m_fg_g.data(), m_fg_b.data(), m_bg_r.data(), m_bg_g.data(), m_bg_b.data(), m_jit_out_r.data(), m_jit_out_g.data(), m_jit_out_b.data());
}

std::string Test4::generate_specialized_code() {
	return std::format(R"(
	void chroma_key_spec(float[8]* fg_r, float[8]* fg_g, float[8]* fg_b, float[8]* bg_r, float[8]* bg_g, float[8]* bg_b, float[8]* out_r, float[8]* out_g, float[8]* out_b) {{
			for (int i = 0; i < {0}; i++) {{
			float[8] fr = fg_r[i];
			float[8] fg = fg_g[i];
			float[8] fb = fg_b[i];

			float[8] br = bg_r[i];
			float[8] bg = bg_g[i];
			float[8] bb = bg_b[i];

			float[8] avg_rb = (fr + fb) * 0.5f;
			float[8] excess = fg - avg_rb;

			bool[8] is_bg = excess > ({1:.8f}f);
			float[8] g_clean = select(excess > ({2:.8f}f), avg_rb + ({2:.8f}f), fg);

			out_r[i] = select(is_bg, br, fr * ({3:.8f}f));
			out_g[i] = select(is_bg, bg, g_clean * ({3:.8f}f));
			out_b[i] = select(is_bg, bb, fb * ({3:.8f}f));
		}}
	}}
	)", m_num_pixels / 8, m_thresh, m_spill_limit, m_gain);
}

void Test4::clear_jit_output() {
	std::fill(m_jit_out_r.begin(), m_jit_out_r.end(), 0.0f);
	std::fill(m_jit_out_g.begin(), m_jit_out_g.end(), 0.0f);
	std::fill(m_jit_out_b.begin(), m_jit_out_b.end(), 0.0f);
}

bool Test4::verify_results() const {
	float epsilon = 1e-5f;
	for (size_t i = 0; i < m_num_pixels;i++) {
		if (std::abs(m_out_r[i] - m_jit_out_r[i]) > epsilon)
			return false;

		if (std::abs(m_out_g[i] - m_jit_out_g[i]) > epsilon)
			return false;

		if (std::abs(m_out_b[i] - m_jit_out_b[i]) > epsilon)
			return false;
	}

	return true;
}