#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void svg_begin(double width, double height, string& res);
void svg_end(string& res);
void svg_text(double left, double baseline, string text, string& res);
void svg_rect(double x, double y, double width, double height, string& res, string stroke="black", string fill="black");
size_t find_max_count(const vector<size_t>& bins, const size_t bin_count);
string show_histogram_svg(const vector<size_t>& bins, const size_t& bin_count);