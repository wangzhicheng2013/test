#include <stdio.h>
typedef char * PSTR;
int main() {
    char string[4] = "abc";
    const char *p1 = string;
    const PSTR p2 = string;
    p1++;
    //p2++;         // 编译出错
    *p2 = 'd';
    printf("%s\n", string);
    
    return 0;
}