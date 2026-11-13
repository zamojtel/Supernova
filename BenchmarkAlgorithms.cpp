
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

void BenchmarkAlgorithms::merge_sort_impl(std::vector<int>& a, std::vector<int>& temp, std::size_t left, std::size_t right) {
	if (right - left <= 1)
		return;

	const size_t mid = left + (right - left) / 2;

	merge_sort_impl(a, temp, left, mid);
	merge_sort_impl(a, temp, mid, right);

	size_t i = left, j = mid, k = left;

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

	for (size_t p = left; p < right; ++p)
		a[p] = temp[p];
}

void BenchmarkAlgorithms::merge_sort(std::vector<int>& a) {
	std::vector<int> temp(a.size());
	merge_sort_impl(a, temp, 0, a.size());
}