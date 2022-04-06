#include <iostream>
#include "boost/array.hpp"
boost::array<unsigned char, 60> chars_65_125() {
    boost::array<unsigned char, 60>res;
    boost::algorithm:iota(res.begin(), res.end(), 65);
    return res;
}
int main() {
    for_each(res.begin(), res.end(), [] (auto e) { std::cout << e << std::endl; } );

    return 0;
}
