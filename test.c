#include <stdio.h>
int main() {
    int a = 1;
    int b = 2;
    int c = a+++++b;
    printf("a = %d, c = %d\n", a, c);
    
    return 0;
}