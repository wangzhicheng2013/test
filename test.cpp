#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include "boost/scoped_array.hpp"
#include "boost/thread.hpp"
#include "boost/bind.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/make_shared.hpp"
#include "boost/shared_array.hpp"
void do_process(const char *data, std::size_t size) {
    assert(size);
    assert(data);
}
void do_process_in_background(const char *data, std::size_t size) {
    char *data_cpy = new char[size];
    std::memcpy(data_cpy, data, size);
    boost::thread(boost::bind(&do_process, data_cpy, size)).detach();
    boost::thread(boost::bind(&do_process, data_cpy, size)).detach();
}
template <std::size_t Size>
void do_process_shared(const boost::shared_ptr<char[Size]>&data) {
    data[0] = 1;
    assert(data[0]);
    do_process(data.get(), Size);
}
template <std::size_t Size>
void do_process_in_background_v1(const char *data) {
    boost::shared_ptr<char[Size]>data_cpy = boost::make_shared<char[Size]>();
    std::memcpy(data_cpy, data.get(), size);
    boost::thread(boost::bind(&do_process_shared<Size>, data_cpy)).detach();
    boost::thread(boost::bind(&do_process_shared<Size>, data_cpy)).detach();
}
void do_process_shared_ptr(const boost::shared_ptr<char[]>& data, std::size_t size) {
    do_process(data.get(), size);
}
void do_process_in_background_v2(const char *data, std::size_t size) {
    boost::shared_ptr<char[]>data_cpy = boost::make_shared<char[]>(size);
    std::memcpy(data_cpy, data.get(), size);
    boost::thread(boost::bind(&do_process_shared_ptr<Size>, data_cpy)).detach();
    boost::thread(boost::bind(&do_process_shared_ptr<Size>, data_cpy)).detach();
}
void do_process_shared_ptr2(const boost::shared_ptr<char>&data, std::size_t size) {
    do_process(data.get(), size);
}
void do_process_in_background_v3(const char *data, std::size_t size) {
    boost::shared_ptr<char>data_cpy(new char[size], boost::checked_array_deleter<char>());
    std::memcpy(data_cpy, data.get(), size);
    boost::thread(boost::bind(&do_process_shared_ptr2, data_cpy, size)).detach();
    boost::thread(boost::bind(&do_process_shared_ptr2, data_cpy, size)).detach();
}
void do_process_shared_array(const boost::shared_array<char>&data, std::size_t size) {
    do_process(data.get(), size);
}
void do_process_in_background_v4(const char *data, std::size_t size) {
    boost::shared_array<char>data_cpy(new char[size]);
    std::memcpy(data_cpy, data.get(), size);
    boost::thread(boost::bind(&do_process_shared_array, data_cpy)).detach();
    boost::thread(boost::bind(&do_process_shared_array, data_cpy)).detach();
}
int main() {
    char ch[] = "Hello dear reader!";
    do_process_in_background_v1<sizeoif(ch)>(ch);
    do_process_in_background_v2(ch, sizeof(ch));
    do_process_in_background_v3(ch, sizeof(ch));
    do_process_in_background_v4(ch, sizeof(ch));

    boost::this_thread::sleep_for(boost::chrono::seconds(2));
    return 0;
}
