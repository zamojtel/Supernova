
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>

#include "BenchmarkAlgorithms.h"
#include "BenchmarkAlgorithms.cpp"

// how we'll get functions from ddl with
// GetProcAddress(dll, "bubble_sort_aot")
extern "C" {
	__declspec(dllexport) void bubble_sort_aot(int* arr, int n) {
		BenchmarkAlgorithms::bubble_sort2(arr,n);
	}

	__declspec(dllexport) void merge_sort_aot(int* arr, int n) {
		BenchmarkAlgorithms::merge_sort(arr,n);
	}

	__declspec(dllexport) void convolve_2d_aot(float* red_input_canal, float* green_input_canal, float* blue_input_canal, float* red_output_canal, float* green_output_canal, float* blue_output_canal, int width, int height, float* kernel, int k) {
		BenchmarkAlgorithms::convolve_2d(red_input_canal,green_input_canal,blue_input_canal,red_output_canal,green_output_canal,blue_output_canal,width,height, kernel, k);
	}

	__declspec(dllexport) void biquad_cascade_aot(float* in, float* out, int num_samples, float* coeffs, int* enabled, float* state, int num_stages) {
		BenchmarkAlgorithms::biquad_cascade(in,out,num_samples,coeffs,enabled,state,num_stages);
	}

	__declspec(dllexport) void chroma_key_aot(float* fg_r, float* fg_g, float* fg_b, float* bg_r, float* bg_g, float* bg_b, float* out_r, float* out_g, float* out_b, int num_pixels, float thresh, float spill_limit, float gain) {
		BenchmarkAlgorithms::chroma_key(fg_r, fg_g, fg_b, bg_r, bg_g, bg_b, out_r, out_g, out_b, num_pixels, thresh, spill_limit, gain);
	}

}