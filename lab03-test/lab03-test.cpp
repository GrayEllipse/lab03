#include "histogram.h"
#include "show_svg_histogram.h"

#include <cassert>

void test_find_minmax() {
    double min = 0;
    double max = 0;

    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);

    find_minmax({ 1, 2, 3 }, min, max);
    assert(min == 1);
    assert(max == 3);

    find_minmax({ -5, -2, -4 }, min, max);
    assert(min == -5);
    assert(max == -2);

    find_minmax({ 1, 1, 1 }, min, max);
    assert(min == 1);
    assert(max == 1);

}

void test_make_histogram() {
    vector<size_t> result({ 2, 1, 2});
    auto s = make_histogram({ 1, 2, 4, 5, 7 }, 3);
    assert(make_histogram({1, 2, 4, 5, 7 }, 3) == result);

    result.assign({ 2, 2 });
    assert(make_histogram({ -1.8, 0, 2, 4}, 2) == result);

}

void test_find_max_count() {
    assert(find_max_count({}, 0) == 0);
    assert(find_max_count({ 1, 4, 8, 12, 15, 100, 13}, 7) == 100);
}

void test_show_svg_histogram() {
    string expected = "<?xml version='1.0' encoding='UTF-8'?>\n"
        "<svg width='810.000000' height='300.000000' viewBox='0 0 810.000000 300.000000' xmlns='http://www.w3.org/2000/svg'>\n"
        "<rect x='30.000000' y='0.000000' width='40.000000' height='30.000000' stroke='green' fill='green'/>\n"
        "<text x='80.000000' y='20.000000'>4</text>\n"
        "<rect x='20.000000' y='30.000000' width='50.000000' height='30.000000' stroke='green' fill='green'/>\n"
        "<text x='80.000000' y='50.000000'>5</text>\n"
        "<rect x='10.000000' y='60.000000' width='60.000000' height='30.000000' stroke='green' fill='green'/>\n"
        "<text x='80.000000' y='80.000000'>6</text>\n"
        "<rect x='0.000000' y='90.000000' width='70.000000' height='30.000000' stroke='green' fill='green'/>\n"
        "<text x='80.000000' y='110.000000'>7</text>\n"
        "</svg>\n";
    string res = show_histogram_svg({ 4, 5, 6, 7 }, 4);
    assert(res.compare(expected)==0);
}

void test() {
    test_find_minmax();
    test_make_histogram();
    test_find_max_count();
    test_show_svg_histogram();
}


int main() {
    test();
}
