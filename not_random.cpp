#include <random>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>

using namespace std;


void fill_array(vector<int>& input_array) {
    for (int i = 0; i < input_array.size(); i++) {
        input_array[i] = rand();
    }
    //unsigned long long needed = random(0, input_array.size()-1);
}

int random(int Min, int Max)
{
    unsigned seed = 1448;
    default_random_engine rng(seed);
    uniform_int_distribution<unsigned> dstr(Min, Max);

    return dstr(rng);
}

int lin_search(vector<int>& input_array, int value)
{
    for (int i = 0; i < input_array.size(); ++i)
    {
        if (input_array[i] == value)
            return i;
    }
    return -1;
}

void strategy_A(vector<int>& input_array, unsigned N, unsigned search_element)
{
    for (unsigned i = 0; i < N; i++)
    {
        if ((input_array[i] == search_element) and (i != 0))
        {
            int cash = input_array[i];
            input_array[i] = input_array[0];
            input_array[0] = cash;
            break;
        }
    }
}

void strategy_B(vector<int>& input_array, unsigned N, unsigned search_element)
{
    for (unsigned i = 0; i < N; i++)
    {
        if ((input_array[i] == search_element) and (i != 0))
        {
            unsigned tmp = input_array[i];
            input_array[i] = input_array[i - 1];
            input_array[i - 1] = tmp;
            break;
        }
    }
}

void strategy_C(vector<int>& input_array, vector<int> arr_counts, unsigned N, unsigned search_element)
{
    for (unsigned i = 0; i < N; i++)
    {
        if (input_array[i] == search_element)
        {
            arr_counts[i]++;
            if (i != 0)
            {
                if (arr_counts[i - 1] < arr_counts[i])
                {
                    unsigned tmp = input_array[i];
                    input_array[i] = input_array[i - 1];
                    input_array[i - 1] = tmp;
                }
            }
            break;
        }
    }
}

string runTest_A(vector<int> input_array, size_t size, int times) {
    int chance = random(0,10);
    int search_element;
    if (chance < 9) {
        search_element = random(0, 100);
    }
    else {
        search_element = rand();
    }

    auto begin = chrono::steady_clock::now();
    for (int i = 0; i < times; i++) {
        strategy_A(input_array, size, search_element);
    }
    auto end = chrono::steady_clock::now();
    auto span = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    return ";" + to_string(span);
}

string runTest_B(vector<int> input_array, size_t size, int times) {

    auto begin = chrono::steady_clock::now();
    int chance = random(0, 10);
    int search_element;
    if (chance < 9) {
        search_element = random(0, 100);
    }
    else {
        search_element = rand();
    }
    for (int i = 0; i < times; i++) {
        strategy_B(input_array, size, search_element);
    }
    auto end = chrono::steady_clock::now();
    auto span = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    return ";" + to_string(span);
}

string runTest_C(vector<int> input_array, size_t size, vector<int> arr_counts, int times) {

    auto begin = chrono::steady_clock::now();
    int chance = random(0, 10);
    int search_element;
    if (chance < 9) {
        search_element = random(0, 100);
    }
    else {
        search_element = rand();
    }
    for (int i = 0; i < times; i++) {
        strategy_C(input_array, arr_counts, size, search_element);
    }
    auto end = chrono::steady_clock::now();
    auto span = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    return ";" + to_string(span);
}
int main() {
    int size = 10000;
    vector<int> arr_counts(size);
    for (int i = 0; i < size; i++) {
        arr_counts[i] = 0;
    }
    vector<int> input_arrayA(size);
    fill_array(input_arrayA);

    vector<int> input_arrayB(size);
    fill_array(input_arrayB);

    vector<int> input_arrayC(size);
    fill_array(input_arrayC);

    ofstream res_a("freq_used_results_A_2.txt");
    ofstream res_b("freq_used_results_B_2.txt");
    ofstream res_c("freq_used_results_C_2.txt");
    for (unsigned times = 100; times <= 10000000; times = times * 15 / 14) {
        vector<int> arr_counts(size);
        for (int i = 0; i < size; i++) {
            arr_counts[i] = 0;
        }
        res_a << to_string(times);
        res_b << to_string(times);
        res_c << to_string(times);
        res_a << runTest_A(input_arrayA, size, times);
        res_b << runTest_B(input_arrayB, size, times);
        res_c << runTest_C(input_arrayC, size, arr_counts, times);
        cout << "N = " << size << "\done";
        res_a << endl;
        res_b << endl;
        res_c << endl;
    }
    return 0;
}
