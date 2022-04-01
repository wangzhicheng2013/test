#include <stdio.h>
#include <stdlib.h>
typedef struct _Coffee
{
    void (*have_coffee)();
} Coffee;
typedef struct _Tea
{
    void (*have_tea)();
} Tea;

void have_black_coffee()
{
    printf("have black coffee!\n");
}
void have_white_coffee()
{
    printf("have white coffee!\n");
}

void have_red_tea()
{
    printf("have red tea!\n");
}
void have_green_tea()
{
    printf("have green tea!\n");
}

typedef struct _CoffeeTeaShop
{
    Coffee *(*sell_coffee)();
    Tea *(*sell_tea)();
} CoffeeTeaShop;

Coffee *sell_black_coffee()
{
    Coffee *pCoffee = (Coffee *)malloc(sizeof(Coffee));
    if (NULL == pCoffee)
    {
        return NULL;
    }
    pCoffee->have_coffee = have_black_coffee;
    return pCoffee;
}

Coffee *sell_white_coffee()
{
    Coffee *pCoffee = (Coffee *)malloc(sizeof(Coffee));
    if (NULL == pCoffee)
    {
        return NULL;
    }
    pCoffee->have_coffee = have_white_coffee;
    return pCoffee;
}

Tea *sell_red_tea()
{
    Tea *pTea = (Tea *)malloc(sizeof(Tea));
    if (NULL == pTea)
    {
        return NULL;
    }
    pTea->have_tea = have_red_tea;
    return pTea;
}

Tea *sell_green_tea()
{
    Tea *pTea = (Tea *)malloc(sizeof(Tea));
    if (NULL == pTea)
    {
        return NULL;
    }
    pTea->have_tea = have_green_tea;
    return pTea;
}
#define SELL_BLACK_COFFEE_REA_TEA 0x01
#define SELL_WHITE_COFFEE_GREEN_TEA 0x01

CoffeeTeaShop * create_coffeetea_shop(int type)
{
    if (type != SELL_BLACK_COFFEE_REA_TEA && type != SELL_WHITE_COFFEE_GREEN_TEA)
    {
        return NULL;
    }
    CoffeeTeaShop *pShop = (CoffeeTeaShop *)malloc(sizeof(CoffeeTeaShop));
    if (NULL == pShop)
    {
        return NULL;
    }
    if (SELL_BLACK_COFFEE_REA_TEA == type)
    {
        pShop->sell_coffee = sell_black_coffee;
        pShop->sell_tea = sell_red_tea;
    }
    else
    {
        pShop->sell_coffee = sell_white_coffee;
        pShop->sell_tea = sell_green_tea;
    }
    return pShop;
}
int main() 
{
    CoffeeTeaShop *pShop = create_coffeetea_shop(SELL_BLACK_COFFEE_REA_TEA);
    if (pShop)
    {
        pShop->sell_coffee();
        pShop->sell_tea();
        free(pShop);
    }

    return 0;
}
