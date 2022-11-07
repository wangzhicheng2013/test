#include <iostream>
#include "boost/static_assert.hpp"
#include "boost/type_traits/is_same.hpp"
#include "boost/core/enable_if.hpp"
#include "boost/type_traits/is_same.hpp"
#include "boost/type_traits/has_plus_assign.hpp"
template <class T>
T process_data_plus_assign(const T&v1, const T&v2, const T&v3) {
    BOOST_STATIC_ASSERT(boost::is_same<int, T>::value);
    (void)v2;
    (void)v3;
    std::cout << "call T process_data_plus_assign(const T&v1, const T&v2, const T&v3) " << std::endl;
    return v1;
}
template <class T>
typename boost::disable_if_c<boost::has_plus_assign<T>::value, T>::type
    process_data(const T&v1, const T&v2, const T&v3) {
        BOOST_STATIC_ASSERT(boost::is_same<const char *, T>::value);
        (void)v2;
        (void)v3;
        std::cout << "call typename boost::diable_if_c<boost::has_plus_assign<T>::value, T>::type" << std::endl;
        return v1;
}
template <class T>
typename boost::enable_if_c<boost::has_plus_assign<T>::value, T>::type
    process_data(const T&v1, const T&v2, const T&v3) {
        return process_data_plus_assign(v1, v2, v3);
}
int main() {
    int i = 1;
    process_data(i, i, i);
    process_data<const char *>("Testing", "example", "function");

    return 0;
}

