#include <iostream>
#include "coffee.h"
#include "condiment.h"

int main()
{
    // now order a cup of coffee: Decaf with Mocha, 2 Soy and Whip
    Beverage *b = new Decaf();
    // std::cout << "Coffee: " << b->description() << " Cost: " << b->cost() << std::endl;

    b = new Mocha(b);
    b = new Soy(b);
    b = new Soy(b);
    b = new Whip(b);

    std::cout << "Coffee: " << b->description() << " Cost: " << b->cost() << std::endl;
    return 0;
}