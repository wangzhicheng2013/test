#include <stdio.h>
#define MAXSIZE 10
typedef int stack_type;
typedef int bool;
struct mystack 
{
    stack_type data[MAXSIZE];
    int top;
};
struct mystack s;
void init() 
{
    s.top = -1;
}
bool isEmpty()
{
    return -1 == s.top;
}
bool isFull()
{
    return MAXSIZE - 1 == s.top;
}
void push(stack_type node) 
{
    if (!isFull())
    {
        s.data[++s.top] = node;
    }
    else 
    {
        printf("mystack is full!\n");
    }
}
void pop() 
{
    if (!isEmpty())
    {
        --s.top;
    }
    else 
    {
        printf("mystack is empty!\n");
    }
}
stack_type top()
{
    if (!isEmpty())
    {
        return s.data[s.top];
    }
    else 
    {
        printf("mystack is empty!\n");
    }
}
void destory()
{
    s.top = -1;
}

int main() {
    push(100);
    push(1000);
    pop();
    printf("%d\n", top());
    
    return 0;
}
