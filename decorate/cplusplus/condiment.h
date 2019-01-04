#ifndef _CONDIMENT_H_
#define _CONDIMENT_H_

#include <string>
#include "coffee.h"

class Mocha : public Beverage
{
  private:
    Beverage *b;

  public:
    Mocha(Beverage *b, float cost = 0.20, std::string desc = "Mocha")
    {
        this->b = b;
        this->f_cost = cost;
        this->desc = desc;
    }
    float cost()
    {
        return this->b->cost() + this->f_cost;
    }
    std::string description()
    {
        return this->b->description() + ", " + this->desc;
    }
};


class Soy : public Beverage
{
  private:
    Beverage *b;

  public:
    Soy(Beverage *b, float cost = 0.11, std::string desc = "Soy")
    {
        this->b = b;
        this->f_cost = cost;
        this->desc = desc;
    }
    float cost()
    {
        return this->b->cost() + this->f_cost;
    }
    std::string description()
    {
        return this->b->description() + ", " + this->desc;
    }
};


class Whip : public Beverage
{
  private:
    Beverage *b;

  public:
    Whip(Beverage *b, float cost = 0.20, std::string desc = "Whip")
    {
        this->b = b;
        this->f_cost = cost;
        this->desc = desc;
    }
    float cost()
    {
        return this->b->cost() + this->f_cost;
    }
    std::string description()
    {
        return this->b->description() + ", " + this->desc;
    }
};
#endif