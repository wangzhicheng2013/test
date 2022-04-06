#include <iostream>
#include <algorithm>
#include <iterator>
#include "boost/array.hpp"
#include "boost/algorithm/cxx11/iota.hpp"
#include "boost/algorithm/hex.hpp"
boost::array<unsigned char, 60> chars_65_125() {
    boost::array<unsigned char, 60>res;
    boost::algorithm::iota(res.begin(), res.end(), 65);
    return res;
}
int main() {
    boost::array<unsigned char, 60> res = chars_65_125();
    std::for_each(res.begin(), res.end(), [] (auto e) { std::cout << e << std::endl; } );
    std::string data = "Hello World";
    boost::algorithm::hex(begin(data), end(data), std::ostream_iterator<char>(std::cout));
    std::cout << std::endl;
    
    return 0;
}
