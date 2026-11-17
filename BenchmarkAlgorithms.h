
class BenchmarkAlgorithms {
public:
	static bool is_sorted(const std::vector<int>& v);
	
	static int fib(int n);
	static void bubble_sort(std::vector<int>& arr);
	static void bubble_sort2(int* arr, int size);
	
	static void merge_sort_impl(int* a, int* temp, int left, int right);
	static void merge_sort(int* a, int n);

	static void apply_mask(const float* in, float* out, int row, int col, int width, int height, const float* kernel, int k);
	static void convolve_2d(float* r_in,float* g_in,float* b_in,float* r_out,float* g_out,float* b_out,int width,int height,float* kernel,int k);
};