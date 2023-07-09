#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "show_svg_histogram.h"

using namespace std;

void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>" << '\n';
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
    vector<string> colors = { "#FFD1DC", "#77DD77", "#FCE883", "#9ACEEB", "#D8BFD8",
                              "#F0E68C", "#7FC7FF", "#AFEEEE", "#CCCCFF", "#3EB489" };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 9);
    string color = colors[distr(gen)];
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << color << "' fill='" << color << "'/>" << '\n';
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

void show_histogram_svg(const vector<size_t>& bins, const size_t& bin_count) {
    const auto IMAGE_WIDTH = 810;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 10;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const size_t MAX_NUMBER_OF_CHAR = 80;
    const size_t MAX_ASTERISK = MAX_NUMBER_OF_CHAR - 4;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double top = 0;
    double scaling_factor = 1.0;
    size_t max_count = find_max_count(bins, bin_count);
    if (max_count > MAX_ASTERISK)
        scaling_factor = MAX_ASTERISK / static_cast<double>(max_count);
    size_t scaled_bin;
    size_t max_height = static_cast<size_t>(scaling_factor * max_count);
    const auto TEXT_LEFT = max_height * BLOCK_WIDTH + TEXT_WIDTH;
    double indent;
    for (size_t bin : bins) {
        scaled_bin = static_cast<size_t>(scaling_factor * bin);
        indent = BLOCK_WIDTH * (max_height - scaled_bin);
        const double bin_width = BLOCK_WIDTH * scaled_bin;
        svg_rect(indent, top, bin_width, BIN_HEIGHT);
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        top += BIN_HEIGHT;
    }
    svg_end();
}