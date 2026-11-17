
int BenchmarkAlgorithms::fib(int n) {
	if (n <= 1)
		return n;

	return fib(n - 2) + fib(n - 1);
}

void BenchmarkAlgorithms::bubble_sort(std::vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		bool swapped = false;
		for (int j = 1; j < n - i; j++) {
			if (arr[j - 1] > arr[j]) {
				std::swap(arr[j - 1], arr[j]);
				swapped = true;
			}
		}

		if (!swapped)
			return;
	}
}

void BenchmarkAlgorithms::bubble_sort2(int* arr, int size) {
	int n = size;
	for (int i = 0; i < n; i++) {
		bool swapped = false;
		int new_limit = n - i;
		for (int j = 1; j < new_limit; j++) {
			if (arr[j - 1] > arr[j]) {
				std::swap(arr[j - 1], arr[j]);
				swapped = true;
			}
		}

		if (!swapped)
			return;
	}
}

bool BenchmarkAlgorithms::is_sorted(const std::vector<int>& v) {
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i - 1] > v[i])
			return false;
	}
	return true;
}

//void BenchmarkAlgorithms::merge_sort_impl(std::vector<int>& a, std::vector<int>& temp, std::size_t left, std::size_t right) {
//	if (right - left <= 1)
//		return;
//
//	const size_t mid = left + (right - left) / 2;
//
//	merge_sort_impl(a, temp, left, mid);
//	merge_sort_impl(a, temp, mid, right);
//
//	size_t i = left, j = mid, k = left;
//
//	while (i < mid && j < right) {
//		if (a[i] <= a[j])
//			temp[k++] = a[i++];
//		else
//			temp[k++] = a[j++];
//	}
//
//	while (i < mid)
//		temp[k++] = a[i++];
//
//	while (j < right)
//		temp[k++] = a[j++];
//
//	for (size_t p = left; p < right; ++p)
//		a[p] = temp[p];
//}
//
//void BenchmarkAlgorithms::merge_sort(std::vector<int>& a) {
//	std::vector<int> temp(a.size());
//	merge_sort_impl(a, temp, 0, a.size());
//}

void BenchmarkAlgorithms::merge_sort_impl(int* a, int* temp, int left, int right) {
	if (right - left <= 1)
		return;
	int const mid = left + (right - left) / 2;
	merge_sort_impl(a, temp, left, mid);
	merge_sort_impl(a, temp, mid, right);

	int i = left, j = mid, k = left;
	while (i < mid && j < right) {
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i < mid)
		temp[k++] = a[i++];

	while (j < right)
		temp[k++] = a[j++];

	for (int p = left; p < right; ++p)
		a[p] = temp[p];

}

void BenchmarkAlgorithms::merge_sort(int* a, int n) {
	int* temp = (int*)malloc(((uint64_t)n) * sizeof(int));
	merge_sort_impl(a, temp, 0, n);
	free(temp);
}

void BenchmarkAlgorithms::apply_mask(const float* in, float* out, int row, int col, int width, int height, const float* kernel, int k) {
	int center_row = k;
	int center_col = k;
	int index = row * width + col;
	int kernel_position = 0;
	float result = 0;

	for (int row_pos = -k; row_pos <= k; row_pos++) {
		int current_row_in = row + row_pos;
		int current_col_in = col + -k;
		int current_index_in = current_row_in * width + current_col_in;
		size_t size = 2 * k + 1;

		for (int i = 0; i < size; i++) {
			result += in[current_index_in] * kernel[kernel_position];
			kernel_position++;
			current_index_in++;
		}
	}

	out[index] = result;
}

void BenchmarkAlgorithms::convolve_2d(float* red_input_canal, float* green_input_canal, float* blue_input_canal, float* red_output_canal, float* green_output_canal, float* blue_output_canal, int width, int height, float* kernel, int k) {
	for (int row = k; row < height - k; row++) {
		for (int col = k; col < width - k; col++) {
			apply_mask(red_input_canal, red_output_canal, row, col, width, height, kernel, k);
			apply_mask(green_input_canal,green_output_canal, row, col, width, height, kernel, k);
			apply_mask(blue_input_canal,blue_output_canal, row, col, width, height, kernel, k);
		}
	}
}