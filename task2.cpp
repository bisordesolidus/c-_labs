#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <string>
#include <vector>


using namespace std;

default_random_engine gen;


bool sum_perebor(vector<unsigned long long int>& input_array, unsigned long long size, long long int needed)
{
	for (int i = 0; i < input_array.size()-1; ++i)
	{
		for (int j = i + 1; j < input_array.size()-1; ++j)
		{
			if (input_array[i] + input_array[j] == needed)
			{
				return true;
			}
		}
	}
	return false;
}

bool sum_linear(vector<unsigned long long int>& input_array, unsigned long long size, long long int needed)
{
	unsigned long long int l = 0;
	unsigned long long int r = input_array.size()-1;
	while (r != -1)
	{
		while (l < r and input_array[l] + input_array[r] < needed)
		{
			++l;
		}
		if (input_array[l] + input_array[r] == needed) {
			return true;
		}
		--r;
	}
	return false;
}


unsigned long long int random(unsigned long long int low, unsigned long long int high)
{
	uniform_int_distribution <> dist(low, high);
	return dist(gen);
}

void fill_array(vector<unsigned long long int>& input_array) {
	for (unsigned long long int i = 0; i < input_array.size(); i++) {
		input_array[i] = rand();
	}
	//unsigned long long needed = random(0, input_array.size()-1);
}


string runTest(size_t size) {
	vector<unsigned long long int> input_array(size);
	fill_array(input_array);
	//sort(input_array.begin(), input_array.end());
	auto begin = chrono::steady_clock::now();
	for (int i = 0; i < 4; i++) {
		sum_perebor(input_array, size, 228);
	}
	auto end = chrono::steady_clock::now();
	auto span = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
	return ";" + to_string(span);
}

int main() {
	ofstream sum_s_res("linear_sum_results.txt");
	ofstream sum_ss_res("sum_results.txt");
	for (unsigned size = 100; size <= 1000000; size = size * 5/4) {
		sum_s_res << to_string(size);
		for (int j = 0; j < 5; j++) {
			sum_s_res << runTest(size);
		}
		cout << "N = " << size << "\done";
		sum_s_res << endl;
	}
	return 0;
}
