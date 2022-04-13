#include <iostream>
#include <string>
#include <cassert>
#include "boost/bind.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/smart_ptr/make_shared.hpp"
void may_throw1(char) {
}
void may_throw2(const char *) {
    std::throw std::exception();
}
void foo() {
    char *buffer = new char[1024 * 1024 * 10];
    may_throw1(buffer[0]);
    may_throw2(buffer.get());
    delete buffer;
}
void foo_fixed() {
    boost::scoped_array<char>buffer(new char[1024 * 1024 * 10]);
    may_throw1(buffer[0]);
    may_throw2(buffer.get());
}

int main() {
    try {
        foo_fixed();
        assert(false);
    }
    catch (...) {

    }
    
    return 0;
}
