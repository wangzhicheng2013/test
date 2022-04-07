#include <iostream>
#include "boost/scoped_ptr.hpp"
bool g_exit_on_first_function = true;
class foo_class {
public:
    char data[1000000];
    explicit foo_class(const char *param) {
        std::cout << "foo class!" << std::endl;
    }
};
bool some_function1(const foo_class &) {
    return g_exit_on_first_function;
}
void some_function2(const foo_class *) {
    throw std::exception();
}
bool foo1() {
    foo_class *p = new foo_class("something happened!");
    auto is_happened = some_function1(*p);
    if (is_happened) {
        delete p;
        return false;
    }
    some_function2(p);
    delete p;
    std::cout << "foo1 over!" << std::endl;
    return true;
}
bool foo2() {
    foo_class *p = new foo_class("something happened!");
    auto is_happened = some_function1(*p);
    if (is_happened) {
        delete p;
        return false;
    }
    try {
        some_function2(p);
    }
    catch (...) {
        delete p;
    }
    std::cout << "foo1 over!" << std::endl;
    return true;
}
bool foo3() {
    boost::scoped_ptr<foo_class>p(new foo_class("something happened!"));
    auto is_happened = some_function1(*p);
    if (is_happened) {
        delete p;
        return false;
    }
    some_function2(p);
    delete p;
    std::cout << "foo1 over!" << std::endl;
    return true;
}
int main() {
    g_exit_on_first_function = false;
    //foo1();
    //foo2();
    foo3();

    return 0;
}
