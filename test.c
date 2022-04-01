#include <stdio.h>
#include <stdlib.h>
typedef struct _shoes
{
    int type;
    void (*produce_shoes)(struct _shoes *);
}myShoes;
void produce_leather_shoes(myShoes *pshoes) 
{
    if (NULL != pshoes)
    {
        printf("produce the leather shoes!\n");
    }
}
void produce_travel_shoes(myShoes *pshoes) 
{
    if (NULL != pshoes)
    {
        printf("produce the travel shoes!\n");
    }
}
#define LEATHER_TYPE 0x1
#define TRAVEL_TYPE  0x2
myShoes *produce_new_shoes(int type)
{
    if (type != LEATHER_TYPE || type != TRAVEL_TYPE)
    {
        return NULL;
    }
    myShoes *pshoes = (myShoes *)malloc(sizeof(myShoes));
    if (NULL == pshoes) 
    {
        return NULL;

    }
    pshoes->type = type;
    if (LEATHER_TYPE == type) 
    {
        pshoes->produce_shoes = produce_leather_shoes;
    }
    else
    {
        pshoes->produce_shoes = produce_travel_shoes;
    }
    return pshoes;
}
int main() 
{
    myShoes *pshoes = produce_new_shoes(LEATHER_TYPE);
    if (pshoes)
    {
        pshoes->produce_shoes(pshoes);
        free(pshoes);
    }

    return 0;
}
