#ifndef _PIZZA_H_
#define _PIZZA_H_

#include <iostream>
#include "ingredient.h"

class Pizza
{
public:
  virtual void prepare() = 0;
  virtual void bake() = 0;
  virtual void cut() = 0;
  virtual void box() = 0;

protected:
  Dough *dough;
  Cheese *cheese;
  Poppcorn *poppcorn;
};

class NewYorkCheesePizza : public Pizza
{
private:
  IngredientFactory *factory;

public:
  NewYorkCheesePizza(IngredientFactory *factory)
  {
    this->factory = factory;
  }
  void prepare()
  {
    std::cout << "preparing " << std::endl;
    this->dough = this->factory->createDough();
    this->cheese = this->factory->createCheese();
    this->poppcorn = this->factory->createPoppcorn();
  }
  void bake()
  {
    std::cout << "baking 15 Minutes " << std::endl;
  }
  void cut()
  {
    std::cout << "cutting to 5 pieces" << std::endl;
  }
  void box()
  {
    std::cout << "boxing " << std::endl;
  }
};

class NewYorkPoppcornPizza : public Pizza
{
private:
  IngredientFactory *factory;

public:
  NewYorkPoppcornPizza(IngredientFactory *factory)
  {
    this->factory = factory;
  }
  void prepare()
  {
    std::cout << "preparing " << std::endl;
    this->dough = this->factory->createDough();
    this->cheese = this->factory->createCheese();
    this->poppcorn = this->factory->createPoppcorn();
  }
  void bake()
  {
    std::cout << "baking 13 Minutes " << std::endl;
  }
  void cut()
  {
    std::cout << "cutting to 5 pieces" << std::endl;
  }
  void box()
  {
    std::cout << "boxing " << std::endl;
  }
};

class NewYorkClamPizza : public Pizza
{
private:
  IngredientFactory *factory;

public:
  NewYorkClamPizza(IngredientFactory *factory)
  {
    this->factory = factory;
  }
  void prepare()
  {
    std::cout << "preparing " << std::endl;
    this->dough = this->factory->createDough();
    this->cheese = this->factory->createCheese();
    this->poppcorn = this->factory->createPoppcorn();
  }
  void bake()
  {
    std::cout << "baking 10-13 Minutes " << std::endl;
  }
  void cut()
  {
    std::cout << "cutting to 5 pieces" << std::endl;
  }
  void box()
  {
    std::cout << "boxing " << std::endl;
  }
};

class ChicagoCheesePizza : public Pizza
{
private:
  IngredientFactory *factory;

public:
  ChicagoCheesePizza(IngredientFactory *factory)
  {
    this->factory = factory;
  }
  void prepare()
  {
    std::cout << "preparing " << std::endl;
    this->dough = this->factory->createDough();
    this->cheese = this->factory->createCheese();
    this->poppcorn = this->factory->createPoppcorn();
  }
  void bake()
  {
    std::cout << "baking 10 Mins 30 secs" << std::endl;
  }
  void cut()
  {
    std::cout << "cutting to 2 pieces " << std::endl;
  }
  void box()
  {
    std::cout << "boxing " << std::endl;
  }
};

class ChicagoPoppcornPizza : public Pizza
{
private:
  IngredientFactory *factory;

public:
  ChicagoPoppcornPizza(IngredientFactory *factory)
  {
    this->factory = factory;
  }
  void prepare()
  {
    std::cout << "preparing " << std::endl;
    this->dough = this->factory->createDough();
    this->cheese = this->factory->createCheese();
    this->poppcorn = this->factory->createPoppcorn();
  }
  void bake()
  {
    std::cout << "baking 10 Mins 30 secs" << std::endl;
  }
  void cut()
  {
    std::cout << "cutting to 2 pieces " << std::endl;
  }
  void box()
  {
    std::cout << "boxing " << std::endl;
  }
};

class ChicagoClamPizza : public Pizza
{
private:
  IngredientFactory *factory;

public:
  ChicagoClamPizza(IngredientFactory *factory)
  {
    this->factory = factory;
  }
  void prepare()
  {
    std::cout << "preparing " << std::endl;
    this->dough = this->factory->createDough();
    this->cheese = this->factory->createCheese();
    this->poppcorn = this->factory->createPoppcorn();
  }
  void bake()
  {
    std::cout << "baking 9-13 Minutes " << std::endl;
  }
  void cut()
  {
    std::cout << "cutting to 2 pieces" << std::endl;
  }
  void box()
  {
    std::cout << "boxing " << std::endl;
  }
};

#endif