﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

void find_minmax(const vector<double>& numbers, double& min, double& max) {
    min = numbers[0];
    max = numbers[0];
    for (double x : numbers) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }
}

vector<size_t> make_histogram(const vector<double>& numbers, const size_t bin_count) {
    vector<size_t> bins(bin_count);
    double min, max;
    find_minmax(numbers, min, max);
    double bin_size = (max - min) / bin_count;
    size_t max_count = 0;
    for (size_t i = 0; i < numbers.size(); i++) {
        bool found = false;
        size_t j;
        for (j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found) {
            bins[bin_count - 1]++;
        }
    }
    return bins;
}

size_t find_max_count(const vector<size_t>& bins, const size_t bin_count) {
    size_t max_count = 0;
    for (size_t count : bins) {
        if (count > max_count) {
            max_count = count;
        }
    }
    return max_count;
}

void show_histogram_text(const vector<size_t>& bins, const size_t bin_count) {
    double scaling_factor = 1.0;
    size_t height;
    size_t max_count = find_max_count(bins, bin_count);
    if (max_count > 76)
        scaling_factor = 76 / static_cast<double>(max_count);
    size_t max_height = static_cast<size_t>(scaling_factor * max_count);
    for (int i = 0; i < bin_count; i++) {
        height = static_cast<size_t>(scaling_factor * bins[i]);
        string indent(max_height - height, ' ');
        cout << indent;
        for (int j = 0; j < height; j++)
            cout << '*';
        cout << '|';
        if (bins[i] < 100)
            cout << ' ';
        if (bins[i] < 10)
            cout << ' ';
        cout << bins[i];
        cout << '\n';
    }
}

int main()
{
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;
    vector<size_t> bins = make_histogram(numbers, bin_count);
    show_histogram_text(bins, bin_count);
}