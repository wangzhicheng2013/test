#include <boost/tuple/tuple.hpp>
#include <iostream>
#include <string>
boost::tuple<int, std::string>almost_a_pair(10, "Hello");
boost::tuple<int, float, double, int>quad(10, 1.0f, 10.0d, 1);
void fun0() {
    auto i = boost::get<0>(almost_a_pair);
    auto &str = boost::get<1>(almost_a_pair);
    double d = boost::get<2>(quad);
    std::cout << "i = " << i << std::endl;
    std::cout << "str = " << str << std::endl;
    std::cout << "d = " << d << std::endl;
}
int main() {
    fun0();
    
    return 0;
}