#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"
using namespace boost::gregorian;
int main() {
    date d(2022, 3, 6);
    std::cout << d.year() << std::endl;
    std::cout << d.month() << std::endl;
    std::cout << d.day() << std::endl;
    std::cout << d.week_number() << std::endl;

    return 0;
}
