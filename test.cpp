#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cassert>
void sample1() {
    const boost::array<int, 12> v = {
         1, 2, 3, 4, 5, 6, 7, 100, 99, 98, 97, 96
    };
    const std::size_t count0 = std::count_if(v.begin(), v.end(), [] (int x) { return 5 < x; } );
    const std::size_t count1 = std::count_if(v.begin(), v.end(), boost::bind(std::less<int>(), 5, _1) );
    assert(count0 == count1);
}
void sample2() {
    const boost::array<std::string, 3> v = {
          "We ", "are", " the champions!"
    };
    const std::size_t count0 = std::count_if(v.begin(), v.end(), [] (const std::string &str) { return str.empty(); } );
    const std::size_t count1 = std::count_if(v.begin(), v.end(), boost::bind(std::string::empty, _1) );
    assert(count0 == count1);
}
void sample3() {
    const boost::array<std::string, 3> v = {
          "We ", "are", " the champions!"
    };
    const std::size_t count0 = std::count_if(v.begin(), v.end(), [] (const std::string &str) { return str.size() < 5; } );
    const std::size_t count1 = std::count_if(v.begin(), v.end(), boost::bind(std::less<std::size_t>(), boost::bind(&std::string::size, _1), 5) );
    assert(count0 == count1);
}
void sample4() {
    const auto twice = boost::bind(std::plus<int>(), _1, _1);
    assert(twice(2), 4);
    const auto minus_from_second = boost::bind(std::minus<int>(), _2, _1);
    assert(minus_from_second(2, 4), 2);
}
int main() {
    sample1();
    sample2();
    sample3();
    sample4();

    return 0;
}