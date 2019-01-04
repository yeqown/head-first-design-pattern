# 工厂模式

工厂方法模式有“创建者”，“产品”两个元素。通过让子类决定该创建的对象是什么，来达到将对象的创建的过程封装的目的。工厂方法模式定义了一个创建对象的接口，但由子类来决定要是实例化的类是哪一个。工厂方法让类的实例化推迟到子类。

### 工厂方法
通过继承来扩展一个类，并覆写工厂方法。通过子类来创建对象。

```cpp
// 工厂方法，生产单个产品
class PizzaStore {
    public:
        virtual Pizza orderPizza() = 0;
};
```

### 抽象工厂
通过组合来把一个产品家族集合起来。

```cpp
// 抽象工厂，生产一系列的产品（可以由工厂方法组合而来）
class PizzaIngredientFactory {
    public:
        virtual Dough createDough() = 0;
        virtual Sauce createSauce() = 0;
        virtual Cheese createCheese() = 0;
        virtual Vegges createVegges() = 0;
        virtual Poppcorn createPoppcorn() = 0;
};
```

### Testcase

* [pizzastore.h](pizzastore.h) 里面是工厂方法模式
* [ingredient.h](ingredient.h) 里面是抽象工厂模式（也有工厂方法模式）

```cpp
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
```

### Output

```sh
order1 : preparing Newyork style cheese Pizza
preparing
using ThinDough
using ReggianoCheese
using SugarFreePoppcorn
baking 15 Minutes
cutting to 5 pieces
boxing

order2 : preparing Newyork style cheese Pizza
preparing
using ThirdCrustDough
using MozzarellaCheese
using SugarFreePoppcorn
baking 10 Mins 30 secs
cutting to 2 pieces
boxing
```