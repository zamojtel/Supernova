
class BenchmarkAlgorithms {
public:
	static int fib(int n);
	static void bubble_sort(std::vector<int>& arr);
	static void bubble_sort2(int* arr, int size);
	static bool is_sorted(const std::vector<int>& v);
	static void merge_sort_impl(std::vector<int>& a, std::vector<int>& temp, std::size_t left, std::size_t right);
	static void merge_sort(std::vector<int>& a);
};