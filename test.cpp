#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include "boost/scoped_array.hpp"
#include "boost/move/make_unique.hpp"
void may_throw1(char) {
}
void may_throw2(const char *) {
    throw std::exception();
}
void foo() {
    char *buffer = new char[1024 * 1024 * 10];
    may_throw1(buffer[0]);
    may_throw2(buffer);
    delete buffer;
}
void foo_fixed() {
    boost::scoped_array<char>buffer(new char[1024 * 1024 * 10]);
    may_throw1(buffer[0]);
    may_throw2(buffer.get());
}
void foo_fixed2() {
    const boost::movelib::unique_ptr<char []>buffer = boost::movelib::make_unique<char []>(1024 * 1024 * 10);
    may_throw1(buffer[0]);
    may_throw2(buffer.get());
}
int main() {
    try {
        //foo_fixed();
        foo_fixed2();
        assert(false);
    }
    catch (...) {

    }

    return 0;
}
