#include <iostream>
#include "duck.h"
#include "turkey.h"

class TurkeyAdaptor : public Duck
{
  private:
    Turkey *turk;

  public:
    TurkeyAdaptor(Turkey *t)
    {
        this->turk = t;
    }

    void quack()
    {
        this->turk->gobble();
    }

    void fly()
    {
        int i;
        for (i = 0; i < 3; i++)
        {
            this->turk->fly();
        }
    }
};

void actWithDuck(Duck *d)
{
    d->quack();
    d->fly();
    return;
}

int main()
{
    Turkey *turkey = new WildTurkey();
    TurkeyAdaptor *turkeyDuck = new TurkeyAdaptor(turkey);

    Duck * duck = new WildDuck();

    // act like a duck
    actWithDuck(duck);
    actWithDuck(turkeyDuck);

    return 0;
}
