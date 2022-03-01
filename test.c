#include <stdio.h>
struct bit1 {
    unsigned a:20;
    unsigned b:6;
    unsigned c:2;
}test_bit1;
struct bit2 {
    unsigned d:20;
    unsigned e:6;
    unsigned f:20;
}test_bit2;
union UN {
    unsigned int u;
    struct {
        unsigned char a:1;
        unsigned char b:2;
        unsigned char c:4;
        unsigned char d:8;
    } ST;
};

int main() {
    printf("%zd\n", sizeof(test_bit1));
    printf("%zd\n", sizeof(test_bit2));
    test_bit1.a = 0;
    test_bit1.b = 0;
    test_bit1.c = 3;
    printf("%d\n", test_bit1.c);

    union UN un;
    un.u = 0;
    un.ST.a = 1;
    un.ST.b = 2;
    un.ST.c = 4;
    un.ST.d = 8;
    printf("%0x\n", un.u);
    
    return 0;
}