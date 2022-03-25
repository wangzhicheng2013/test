#include <string.h>
#include <iostream>
#include <algorithm>
#include <cassert>
#include "boost/noncopyable.hpp"
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
int main() {
    descriptor_owner ret;
    construct_descriptor1(ret);
    std::cout << ret.show() << std::endl;

    return 0;
}
