#include <iostream>

#include "pizza.h"
#include "pizzastore.h"

int main()
{
    // order a pizza
    PizzaStore *NYStore = new NewYorkPizzaStore();
    ChicagoPizzaStore *CStore = new ChicagoPizzaStore();

    Pizza *pizzaOrder1 = NYStore->orderPizza(CHEESE);
    Pizza *pizzaOrder2 = CStore->orderPizza(POPPCORN);

    std::cout << "order1 : preparing Newyork style cheese Pizza" << std::endl;
    // deal with pizzaOrder1
    pizzaOrder1->prepare();
    pizzaOrder1->bake();
    pizzaOrder1->cut();
    pizzaOrder1->box();

    std::cout << std::endl;
    std::cout << "order2 : preparing Newyork style cheese Pizza" << std::endl;
    // deal with pizzaOrder2
    pizzaOrder2->prepare();
    pizzaOrder2->bake();
    pizzaOrder2->cut();
    pizzaOrder2->box();

    return 0;
}