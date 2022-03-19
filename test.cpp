class descriptor_owner_fixed : private boost::noncopyable {
public:
    descriptor_owner_fixed(const char *param) {
        (void)param;
    }
};
void i_am_good() {
    descriptor_owner_fixed d1("OOP");
    descriptor_owner_fixed d2("OOC");
}


int main() {
    i_am_good();
    
    return 0;
}
