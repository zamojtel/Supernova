
void buble_sort(std::vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n ;i++) {
		bool swapped = false;
		for (int j = 1; j < n - i;j++) {
			if (arr[j-1]>arr[j]) {
				std::swap(arr[j-1],arr[j]);
				swapped = true;
			}
		}

		if (!swapped)
			return;
	}
}
