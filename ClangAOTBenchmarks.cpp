
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

}