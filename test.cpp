#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <iostream>
#include <string>
#include <set>
#include <cassert>
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
void fun1() {
    std::set<boost::tuple<int, double, int>>s;
    s.insert(boost::make_tuple(1, 1.0d, 2));
    s.insert(boost::make_tuple(2, 10.0d, 2));
    s.insert(boost::make_tuple(3, 100.0d, 2));
    const auto t = boost::make_tuple(0, -1.0, 2);
    assert(2 == boost::get<2>(t));
}
int main() {
    fun0();
    fun1();

    return 0;
}