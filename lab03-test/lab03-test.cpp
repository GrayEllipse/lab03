#include <cassert>
#include "histogram.h"

void test_positive() {
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

    find_minmax({ 1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);

}

int main() {
    test_positive();
}