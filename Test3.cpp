
Test3::Test3(int n) : m_n{ n }, m_filters(n) {}

void Test3::generate_signal(size_t khz, size_t signal_length) {
	size_t size = signal_length * khz * 1'000;
	std::mt19937 generator(std::random_device{}());
	std::uniform_real_distribution<float> pick_random(-1.0,1.0);
	m_jit_output_signal.resize(size);
	m_coef.resize(5*m_n);
	m_signal.resize(size);
	m_enabled.assign(m_n, 1);
	m_state.assign(4 * m_n, 0.0f);

	m_output_signal.resize(size);
	for (size_t i = 0; i < size;i++)
		m_signal[i] = pick_random(generator);
	
	for (size_t i = 0; i < m_n; i++) {
		m_filters[i].generate_random_coef();
		m_coef[5 * i] = m_filters[i].get_b0();
		m_coef[5 * i + 1] = m_filters[i].get_b1();
		m_coef[5 * i + 2] = m_filters[i].get_b2();
		m_coef[5 * i + 3] = m_filters[i].get_a1();
		m_coef[5 * i + 4] = m_filters[i].get_a2();
	}
}

void Test3::run() {
	for (size_t j = 0; j < m_signal.size();j++) {
		float signal_j_value = m_signal[j];
		for (size_t i = 0; i < m_filters.size(); i++) {
			if (m_filters[i].is_enabled())
				signal_j_value = m_filters[i].process(signal_j_value);
		}
		m_output_signal[j] = signal_j_value;
	}
}

void Test3::run_jit(BiquadFn fn) {
	if (fn) {
		fn(m_signal.data(),m_jit_output_signal.data(),(int)m_signal.size(),m_coef.data(),m_enabled.data(),m_state.data(),m_n);
	}
}

void Test3::run_specialized_jit(SpecBiquadFn sfn) {
	if (sfn) {
		sfn(m_signal.data(),m_jit_output_signal.data(),(int)m_signal.size(),m_state.data());
	}
}

std::string Test3::generate_specialized_code() {
	std::string init_ops;
	std::string stage_ops;
	std::string save_ops;

	for (int j = 0; j < m_n; j++) {
		if (m_enabled[j] == 0)
			continue;

		int s = 4 * j;
		float b0 = m_filters[j].get_b0();
		float b1 = m_filters[j].get_b1();
		float b2 = m_filters[j].get_b2();
		float a1 = m_filters[j].get_a1();
		float a2 = m_filters[j].get_a2();

		init_ops += std::format(R"(
				float s{0}_x1 = state[{1}];
				float s{0}_x2 = state[{2}];
				float s{0}_y1 = state[{3}];
				float s{0}_y2 = state[{4}];)",
			j, s, s + 1, s + 2, s + 3);

		stage_ops += std::format(R"(
				float y_{0} = ({1:.8f}f) * x0 + ({2:.8f}f) * s{0}_x1 + ({3:.8f}f) * s{0}_x2 - ({4:.8f}f) * s{0}_y1 - ({5:.8f}f) * s{0}_y2;
				s{0}_x2 = s{0}_x1;
				s{0}_x1 = x0;
				s{0}_y2 = s{0}_y1;
				s{0}_y1 = y_{0};
				x0 = y_{0};)",
			j, b0, b1, b2, a1, a2);

		save_ops += std::format(R"(
				state[{1}] = s{0}_x1;
				state[{2}] = s{0}_x2;
				state[{3}] = s{0}_y1;
				state[{4}] = s{0}_y2;)",
			j, s, s + 1, s + 2, s + 3);
	}

	return std::format(R"(
				void biquad_cascade_spec(float* in, float* out, int num_samples, float* state) {{
				{0}
					for (int i = 0; i < num_samples; i = i + 1) {{
						float x0 = in[i];
				{1}
						out[i] = x0;
					}}
				{2}
				}})",
		init_ops, stage_ops, save_ops);
}

void Test3::reset_state() {
	for (size_t i = 0; i < m_filters.size();i++)
		m_filters[i].reset();
	std::fill(m_state.begin(), m_state.end(), 0);
}

void Test3::clear_jit_outputs() {
	std::fill(m_jit_output_signal.begin(),m_jit_output_signal.end(),0);
}

void Test3::set_sparse_bands() {
	for (size_t i = 0; i < m_filters.size();i++) {
		if (i%3!=0) {
			m_filters[i].set_enabled(false);
			m_enabled[i] = 0;
		}
	}
}

bool Test3::verify_results() const {
	float epsilon = 1e-3f;
	for (size_t i = 0; i < m_signal.size();i++) {
		if (std::abs(m_output_signal[i] - m_jit_output_signal[i]) > epsilon)
			return false;
	}
	return true;
}