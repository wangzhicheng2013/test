#include <iostream>
#include <string>
#include <cassert>
#include "boost/thread.hpp"
#include "boost/bind.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/smart_ptr/make_shared.hpp"
bool g_exit_on_first_function = true;
class foo_class {
public:
    char data[1000000];
    explicit foo_class(const char *param) {
        std::cout << "foo class!" << std::endl;
    }
};
foo_class *get_data() {
    static int i = 0;
    ++i;
    if (i % 2) {
        return new foo_class("Just something!");
    }
    else {
        return 0;
    }
}
void process1(const foo_class *p) {
    assert(p);
}
void process2(const foo_class *p) {
    assert(p);
}
void process3(const foo_class *p) {
    assert(p);
}
void process_sp1(const boost::shared_ptr<foo_class>&p) {
    assert(!!p);
}
void process_sp2(const boost::shared_ptr<foo_class>&p) {
    assert(!!p);
}
void process_sp3(const boost::shared_ptr<foo_class>&p) {
    assert(!!p);
}
void process_str1(boost::shared_ptr<std::string> p) {
    assert(p);
}

void process_str2(const boost::shared_ptr<std::string>& p) {
    assert(p);
}

void process_cstr1(boost::shared_ptr<const std::string> p) {
    assert(p);
}

void process_cstr2(const boost::shared_ptr<const std::string>& p) {
    assert(p);
}

void foo1() {
    while (foo_class *p = get_data()) {
        boost::thread(boost::bind(&process1, p)).detach();
        boost::thread(boost::bind(&process2, p)).detach();
        boost::thread(boost::bind(&process3, p)).detach();
    }
}
void foo2() {
    typedef boost::shared_ptr<foo_class>ptr_t;
    ptr_t p;
    while (p = ptr_t(get_data())) {
        boost::thread(boost::bind(&process_sp1, p)).detach();
        boost::thread(boost::bind(&process_sp2, p)).detach();
        boost::thread(boost::bind(&process_sp3, p)).detach();
    }
}
void foo3() {
    boost::shared_ptr<std::string>ps = boost::make_shared<std::string>("C++");
    boost::thread(boost::bind(&process_str1, ps)).detach();
    boost::thread(boost::bind(&process_str2, ps)).detach();
}
void foo3_const() {
    boost::shared_ptr<const std::string>ps = boost::make_shared<const std::string>("Modern C++");
    boost::thread(boost::bind(&process_cstr1, ps)).detach();
    boost::thread(boost::bind(&process_cstr2, ps)).detach();
}
int main() {
    foo2();
    foo3();
    foo3_const();

    return 0;
}
