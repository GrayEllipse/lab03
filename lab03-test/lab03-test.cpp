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

void test() {
    test_find_minmax();
    test_make_histogram();
    test_find_max_count();
}


int main() {
    test();
}