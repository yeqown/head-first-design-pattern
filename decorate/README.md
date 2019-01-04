# 装饰模式

动态的讲责任附加到对象上，如果想要扩展功能，装饰器提供了比继承更有弹性的替代方案。
> 使用Golang来应用装饰器模式，在语法上并不那么直观和优雅。相比之下，支持OO语法的Java,C++,Python会更容易编码。

## Golang版本

### TestCase

```golang
func Test_Decorate(t *testing.T) {
	coffee := new(Espresso)
	mocha := new(Mocha)
	mocha.Wrap(coffee)
	soy := new(Soy)
	soy.Wrap(mocha)

	PrintBeverage(soy)
}

func PrintBeverage(b Beverage) {
	fmt.Printf("Coffee %s and Cost: %.2f", b.Description(), b.Cost())
}
```

### Output

```sh
=== RUN   Test_Decorate
Coffee Espresso, Mocha, Soy and Cost: 2.36--- PASS: Test_Decorate (0.00s)
PASS
```

## C++ 版本

```c++
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
```

### Output

```sh
Coffee: Decaf, Mocha, Soy, Soy, Whip Cost: 1.71
```