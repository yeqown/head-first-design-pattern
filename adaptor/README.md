# 适配器模式

讲一个类的接口，转换成一个客户期望的另一个接口，适配器让原本接口不兼容的类可以合作无间。

## 工作过程
客户通过目标接口调用适配器的方法对适配器发出请求；适配器使用被适配者接口把请求转换成被适配器的一个或者多个调用接口；客户端接收调用的结果，但无法未察觉适配器的转换作用。

### 对象适配器

通过组合来适配被适配者，并实现目标接口。

### 类适配器

通过继承被适配类和目标类。


### Testcase

```cpp
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
```

### Output

```sh
duck quacking ~
duck flying ~ (About 10 meters)
Turkey gobbling
Turkey flying (About 3 meters)
Turkey flying (About 3 meters)
Turkey flying (About 3 meters)
```