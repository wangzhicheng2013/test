#include <stdio.h>
#include <stdlib.h>
int add(int num1, int num2) {
    return num1 + num2;
}
int sub(int num1, int num2) {
    return num1 - num2;
}
int mul(int num1, int num2) {
    return num1 * num2;
}
int decorator(int (*func)(int, int), int num1, num2) {
    return func(num1, num2);
}
int main() 
{
    int a = 1, b = 2;
    printf("%d\n", decorator(add, a, b));
    printf("%d\n", decorator(sub, a, b));
    printf("%d\n", decorator(mul, a, b));

    return 0;
}
