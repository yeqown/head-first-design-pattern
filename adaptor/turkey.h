#ifndef _TURKEY_H_
#define _TURKEY_H_

class Turkey
{
  public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class WildTurkey : public Turkey
{
  public:
    void gobble()
    {
        std::cout << "Turkey gobbling" << std::endl;
    }

    void fly()
    {
        std::cout << "Turkey flying (About 3 meters)" << std::endl;
    }
};

#endif