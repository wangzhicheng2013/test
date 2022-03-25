#include <string.h>
#include <iostream>
#include <algorithm>
#include <cassert>
#include "boost/noncopyable.hpp"
#include "boost/config.hpp"
#include "boost/move/move.hpp"
#include "boost/container/vector.hpp"
class descriptor_owner : private boost::noncopyable {
    void *descriptor_;
public:
    descriptor_owner() : descriptor_(nullptr) {}
    explicit descriptor_owner(const char *param) : descriptor_(strdup(param)) {}
    void swap(descriptor_owner& desc) {
        std::swap(descriptor_, desc.descriptor_);
    }
    void show() const {
        if (descriptor_) {
            const char *ss = (const char *)descriptor_;
            std::cout << ss << std::endl;
        }
    }
    ~descriptor_owner() {
        if (descriptor_) {
            free(descriptor_);
            descriptor_ = nullptr;
        }
    }
};
void construct_descriptor1(descriptor_owner& ret) {
    descriptor_owner("Construct using this string").swap(ret);
}
class descriptor_owner1 {
    void *descriptor_;
public:
    descriptor_owner1() : descriptor_(nullptr) {}
    explicit descriptor_owner1(const char *param) : descriptor_(strdup(param)) {}
    descriptor_owner1(descriptor_owner1 &&param) : descriptor_(param.descriptor_) {
        param.descriptor_ = nullptr;
    }
    descriptor_owner1 & operator = (descriptor_owner1 &&param) {
        descriptor_owner1 tmp(std::move(param));
        std::swap(descriptor_, tmp.descriptor_);
        return *this;
    }
    void clear() {
        if (descriptor_) {
            free(descriptor_);
            descriptor_ = nullptr;
        }
    }
    bool empty() const {
        return !descriptor_;
    }
    void show() const {
        if (descriptor_) {
            const char *ss = (const char *)descriptor_;
            std::cout << ss << std::endl;
        }
    }
    ~descriptor_owner1() {
        clear();
    }
};
class descriptor_owner_movable {
    void *descriptor_;
    BOOST_MOVABLE_BUT_NOT_COPYABLE(descriptor_owner_movable);
public:
    descriptor_owner_movable() : descriptor_(nullptr) {}
    explicit descriptor_owner_movable(const char *param) : descriptor_(strdup(param)) {}
    descriptor_owner_movable(BOOST_RV_REF(descriptor_owner_movable)param) BOOST_NOEXCEPT : descriptor_(param.descriptor_) {}
        param.descriptor_ = nullptr;
    }
    descriptor_owner_movable & operator = (descriptor_owner_movable)param) BOOST_NOEXCEPT {
        descriptor_owner_movable tmp(std::move(param));
        std::swap(descriptor_, tmp.descriptor_);
        return *this;
    }
    void clear() {
        if (descriptor_) {
            free(descriptor_);
            descriptor_ = nullptr;
        }
    }
    bool empty() const {
        return !descriptor_;
    }
    ~descriptor_owner_movable() BOOST_NOEXCEPT {
        clear();
    }
};
descriptor_owner_movable construct_descriptor3() {
    return descriptor_owner_movable("Construct using this string");
}
int main() {
    descriptor_owner ret;
    construct_descriptor1(ret);
    ret.show();

    descriptor_owner1 desc;
    desc = descriptor_owner1("Construct using this string");
    assert(!desc.empty());

    descriptor_owner_movable movable;
    movable = construct_descriptor3();

    boost::container::vector<descriptor_owner_movable>vec;
    vec.resize(10);
    vec.push_back(construct_descriptor3());
    return 0;
}
