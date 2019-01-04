#ifndef _PIZZA_STORE_H_
#define _PIZZA_STORE_H_

#include <iostream>
#include "pizza.h"

enum PizzType
{
    CHEESE,
    CLAM,
    POPPCORN,
};

/*
* 工厂方法模式生产不同类型的Pizza
*/
class PizzaStore
{
  public:
    virtual Pizza *orderPizza(PizzType pizzaType) = 0;
};

class NewYorkPizzaStore : public PizzaStore
{
  public:
    Pizza *orderPizza(PizzType pt)
    {
        Pizza *pizza;
        IngredientFactory *ingredientFactory = new NewYorkIngredientFactory();
        switch (pt)
        {
        case CHEESE:
            pizza = new NewYorkCheesePizza(ingredientFactory);
            break;
        case CLAM:
            pizza = new NewYorkClamPizza(ingredientFactory);
            break;
        case POPPCORN:
            pizza = new NewYorkPoppcornPizza(ingredientFactory);
            break;
        }
        return pizza;
    }
};

class ChicagoPizzaStore : public PizzaStore
{
  public:
    Pizza *orderPizza(PizzType pt)
    {
        Pizza *pizza;
        IngredientFactory *ingredientFactory = new ChicagoIngredientFactory();
        switch (pt)
        {
        case CHEESE:
            pizza = new ChicagoCheesePizza(ingredientFactory);
            break;
        case CLAM:
            pizza = new ChicagoClamPizza(ingredientFactory);
            break;
        case POPPCORN:
            pizza = new ChicagoPoppcornPizza(ingredientFactory);
            break;
        }
        return pizza;
    }
};
#endif