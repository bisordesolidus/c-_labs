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


bool full_perebor(vector<unsigned long long int>& input_array, unsigned long long size, long long int needed) {
	unsigned long long i = 0;
		while (i < input_array.size() and input_array[i] != needed) {
			if (input_array[i] == needed) {
				return true;
			}
			else {
				if (i == input_array.size()-1) {
					return false;
				}
				i++;
			}
		}
}



bool binar_search(vector<unsigned long long int>& input_array, unsigned long long size, long long int needed) {
	unsigned long long int l = 0;
	unsigned long long int r = input_array.size();
	unsigned long long int mid;

	while (r - l > 1) {
		mid = (l + r) / 2;

		if (input_array[mid] > needed) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	if (input_array[l] == needed) {
		return true;
	}
	else {
		return false;
	}
}



unsigned long long int random(unsigned long long int low, unsigned long long int high)
{
	uniform_int_distribution <> dist(low, high);
	return dist(gen);
}

void fill_array(vector<unsigned long long int> &input_array) {
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
	for (int i = 0; i < 1000; i++) {
		full_perebor(input_array, size, 228);
	}
	auto end = chrono::steady_clock::now();
	auto span = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
	return ";" + to_string(span);
}

int main() {
	ofstream bs_res("bin_search_results.txt");
	ofstream s_res("search_results.txt");
	for (unsigned size = 100; size <= 10000000; size = size * 20/19) {
		s_res << to_string(size);
		for (int j = 0; j < 5; j++) {
			s_res << runTest(size);
		}
		cout << "N = " << size << "\done";
		s_res << endl;
	}
	return 0;
}




