#include <iostream>
#include <string>
#include <cassert>
#include "boost/function.hpp"
typedef boost::function<void(int)>fobject_t;
void process_integers(const fobject_t &fun) {
    fun(10);
}
void my_ints_function(int i) {
    assert(10 == i);
}
int main() {
    process_integers(&my_ints_function);

    return 0;
}
