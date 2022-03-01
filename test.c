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
int main() {
    printf("%zd\n", sizeof(test_bit1));
    printf("%zd\n", sizeof(test_bit2));
    test_bit1.a = 0;
    test_bit1.b = 0;
    test_bit1.c = 3;
    printf("%d\n", test_bit1.c);

    return 0;
}