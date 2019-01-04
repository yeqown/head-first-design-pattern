#ifndef _INGREDIENT_H_
#define _INGREDIENT_H_

#include <iostream>

// Dough Ingredient ...
class Dough
{
  public:
    virtual std::string water() = 0;
};

class ThinDough : public Dough
{
  public:
    std::string water() { return "ThinDough"; }
};

class ThirdCrustDough : public Dough
{
  public:
    std::string water() { return "ThirdCrustDough"; }
};

// Cheese Ingredient ...
class Cheese
{
  public:
    virtual std::string fire() = 0;
};

class MozzarellaCheese : public Cheese
{
  public:
    std::string fire() { return "MozzarellaCheese"; }
};

class ReggianoCheese : public Cheese
{
  public:
    std::string fire() { return "ReggianoCheese"; }
};

// Poppcorn ingedient ...
class Poppcorn
{
  public:
    virtual std::string sweet() = 0;
};

class SugaryPoppcorn : public Poppcorn
{
  public:
    std::string sweet() { return "SugaryPoppcorn"; }
};

class SugarFreePoppcorn : public Poppcorn
{
  public:
    std::string sweet() { return "SugarFreePoppcorn"; }
};
/*
* IngredientFactory 就是一个抽象工厂
*/
class IngredientFactory
{
  public:
    virtual Dough *createDough() = 0;
    virtual Cheese *createCheese() = 0;
    virtual Poppcorn *createPoppcorn() = 0;
    /*
    * 为了减少代码，省去了部分原料生产方法
    */
    // virtual Sauce createSauce() = 0;
    // virtual Vegges createVegges() = 0;
};

class NewYorkIngredientFactory : public IngredientFactory
{
    Dough *createDough()
    {
        std::cout << "using ThinDough" << std::endl;
        return new ThinDough();
    }
    Cheese *createCheese()
    {
        std::cout << "using ReggianoCheese" << std::endl;
        return new ReggianoCheese();
    }
    Poppcorn *createPoppcorn()
    {
        std::cout << "using SugarFreePoppcorn" << std::endl;
        return new SugarFreePoppcorn();
    }
};

class ChicagoIngredientFactory : public IngredientFactory
{
    Dough *createDough()
    {
        std::cout << "using ThirdCrustDough" << std::endl;
        return new ThirdCrustDough();
    }
    Cheese *createCheese()
    {
        std::cout << "using MozzarellaCheese" << std::endl;
        return new MozzarellaCheese();
    }
    Poppcorn *createPoppcorn()
    {
        std::cout << "using SugarFreePoppcorn" << std::endl;
        return new SugarFreePoppcorn();
    }
};

#endif