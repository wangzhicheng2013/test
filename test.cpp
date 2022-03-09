#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cassert>
#include <boost/move/move.hpp>
#include <boost/swap.hpp>

namespace other {
    class characteristics { };
}
struct person_info {
    std::string name;
    std::string second_name;
    other::characteristics cc;
private:
    BOOST_COPYABLE_AND_MOVABLE(person_info);
public:
    person_info() { }
    person_info(const person_info &p) : name(p.name), 
                                        second_name(p.second_name),
                                        cc(p.cc) { }
    person_info(BOOST_RV_REF(person_info) p) {
        swap(p);
    }
    person_info& operator = (BOOST_COPY_ASSIGN_REF(person_info) person) {
        std::cout << "BOOST_COPY_ASSIGN_REF" << std::endl;
        person_info tmp(person);
        swap(tmp);
        return *this;
    }
    person_info& operator = (BOOST_RV_REF(person_info) person) {
        std::cout << "BOOST_RV_REF" << std::endl;
        person_info tmp(boost::move(person));
        swap(tmp);
        return *this;
    }
    void swap(person_info &rhs) {
        name.swap(rhs.name);
        second_name.swap(rhs.second_name);
        boost::swap(cc, rhs.cc);
    }
};

int main() {
    person_info vasya;
    vasya.name = "Vasya";
    vasya.second_name = "Snow";

    person_info new_vasya(boost::move(vasya));
    assert("Vasya" == new_vasya.name);
    assert("Snow" == new_vasya.second_name);
    assert(vasya.name.empty());
    assert(vasya.second_name.empty());

    vasya = boost::move(new_vasya);
    assert("Vasya" == vasya.name);
    assert("Snow" == vasya.second_name);
    assert(new_vasya.name.empty());
    assert(new_vasya.second_name.empty());

    new_vasya = vasya;
    assert("Vasya" == vasya.name);
    assert("Snow" == vasya.second_name);
    assert("Vasya" == new_vasya.name);
    assert("Snow" == new_vasya.second_name);

    return 0;
}
