#ifndef _DUCK_H_
#define _DUCK_H_

#include <iostream>

class Duck
{
  public:
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class WildDuck : public Duck
{
  public:
    void quack()
    {
        std::cout << "duck quacking ~" << std::endl;
    }

    void fly()
    {
        std::cout << "duck flying ~ (About 10 meters)" << std::endl;
    }
};
#endif