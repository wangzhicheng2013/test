#include <stdio.h>
#include <stdlib.h>
typedef struct _FoodClass
{
    void (*eat)();
} FoodClass;
void eat()
{
    printf("I want to eat!\n");
}
typedef struct _ShopClass
{
    void (*shop)();
} ShopClass;
void shop()
{
    printf("I want to shop!\n");
}
typedef struct _PlayClass
{
    void (*play)();
} PlayClass;
void play()
{
    printf("I want to play!\n");
}
typedef struct _TourClass
{
    FoodClass *pFood;
    ShopClass *pShop;
    PlayClass *pPlay;
    void (*facade)(struct _TourClass *pTour);
} TourClass;
void facade(TourClass *pTour)
{
    if (NULL == pTour)
    {
        return;
    }
    if (pTour->pFood)
    {
        pTour->pFood->eat();
    }
    if (pTour->pShop)
    {
        pTour->pShop->shop();
    }
    if (pTour->pPlay)
    {
        pTour->pPlay->play();
    }
}
int main() 
{
    FoodClass Food;
    ShopClass Shop;
    PlayClass Play;
    Food.eat = eat;
    Shop.shop = shop;
    Play.play = play;
    TourClass Tour;
    Tour.pFood = &Food;
    Tour.pShop = &Shop;
    Tour.pPlay = &Play;
    Tour.facade = facade;
    Tour.facade(&Tour);
    
    return 0;
}
