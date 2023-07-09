#pragma once
#include <vector>

using namespace std;

void find_minmax(const vector<double> numbers, double& min, double& max);
vector<double> input_numbers(size_t count);
vector<size_t> make_histogram(const vector<double>& numbers, const size_t bin_count);