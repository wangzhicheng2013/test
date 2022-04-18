#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include "boost/function.hpp"
typedef boost::function<void(int)>fobject_t;
class int_processor {
    const int min_;
    const int max_;
    bool &triggered_;
public:
    int_processor(int min, int max, bool &triggered)
        : min_(min)
        , max_(max)
        , triggered_(triggered)
    {}
    void operator() (int i) const {
        triggered_ = (i > max_ ) || (i < min_);
    }
};
void process_integers(const fobject_t &f) {
    static const int data[] = { 1, 2, 3, 4, 200 };
    std::for_each(std::begin(data), std::end(data), f);
}
int main() {
    bool is_triggered = false;
    int_processor fo(100, 200, is_triggered);
    process_integers(fo);
    std::cout << is_triggered << std::endl;

    return 0;
}
