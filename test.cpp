#include <iostream>
#include <string>
#include <cassert>
#include <deque>
#include <algorithm>
#include "boost/function.hpp"
typedef boost::function<void(int)>fobject_t;
void process_integers(const fobject_t &fun) {
    static const int data[] = { 1, 2, 3, 4, 5, 200 };
    std::for_each(std::begin(data), std::end(data), fun);
}
void sample() {
    process_integers([](int) { });
    std::deque<int>ints;
    process_integers([&ints](int i) {
        ints.push_back(i);
    });
    std::size_t match_count = 0;
    process_integers([&ints, &match_count](int i) mutable {
        if (ints.front() == i) {
            ++match_count;
        }
        ints.pop_front();
    });
    assert(6 == match_count);
}
int main() {
    sample();
    std::deque<int>v = { 10, 20, 30, 40, 50 };
    std::for_each(std::begin(v), std::end(v), [](int &v) { v += 10;});
    const boost::function<void(int&)>f0([] (int &v) { v += 10;});
    std::for_each(std::begin(v), std::end(v), f0);

    return 0;
}
