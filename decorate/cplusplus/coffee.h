#ifndef _COFFEE_H_
#define _COFFEE_H_

#include <string>

/*
* Bevarage is a virtual class just work as a interface
* NOTICE: Beverage work as a interface should not contain any data, 
* so just see it as an Abtract Class rather than a interface
*/
class Beverage
{
  public:
    virtual float cost() = 0;
    virtual std::string description() = 0;

  protected:
    float f_cost;
    std::string desc;
};

class Espresso : public Beverage
{
  public:
    Espresso(float cost = 1.99, std::string desc = "Espresso")
    {
        this->f_cost = cost;
        this->desc = desc;
    }
    float cost()
    {
        return this->f_cost;
    }
    std::string description()
    {
        return this->desc;
    }
};

class DarkRoast : public Beverage
{
  public:
    DarkRoast(float cost = 1.99, std::string desc = "DarkRoast")
    {
        this->f_cost = cost;
        this->desc = desc;
    }
    float cost()
    {
        return this->f_cost;
    }
    std::string description()
    {
        return this->desc;
    }
};

class HouseBlend : public Beverage
{
  public:
    HouseBlend(float cost = 1.99, std::string desc = "HouseBlend")
    {
        this->f_cost = cost;
        this->desc = desc;
    }
    float cost()
    {
        return this->f_cost;
    }
    std::string description()
    {
        return this->desc;
    }
};

class Decaf : public Beverage
{
  public:
    Decaf(float cost = 1.09, std::string desc = "Decaf")
    {
        this->f_cost = cost;
        this->desc = desc;
    }
    float cost()
    {
        return this->f_cost;
    }
    std::string description()
    {
        return this->desc;
    }
};
#endif