# 迭代器模式

提供一种方法顺序访问一个聚合对象重的各个元素，而又不暴露其内部的表示。

> 个人观点：迭代器模式提供的思维方式跟适配器模式的方式类似，都是改变接口来为调用者提供相同的功能。不过出发点却不一样，迭代器是为了减少调用者责任；适配器是为了适应不同。

### 单一责任原则

类的每个责任都有改变的的潜在区域，超过一个责任，以为着超过一个改变的区域。当一个模块或一个类被设计车过只支持一组相关的功能时，我们说它具有高内聚；反之，当被设计成支持一组不相关的功能时，被称为低内聚。

### Testcase

```java
public class Testcase {
    public static void main(String[] args) {
        DinerMenu dinerMenu = new DinerMenu();
        PancakeHouseMenu pancakeHouseMenu = new PancakeHouseMenu();

        dinerMenu.addItem("name 0", "description of item 0", true, 0.8162);
        dinerMenu.addItem("name 1", "description of item 1", true, 1.8162);
        dinerMenu.addItem("name 2", "description of item 2", true, 2.8162);
        dinerMenu.addItem("name 3", "description of item 3", true, 3.8162);

        pancakeHouseMenu.addItem("name 4", "description of item 4", false, 4.8162);
        pancakeHouseMenu.addItem("name 5", "description of item 5", false, 5.8162);
        pancakeHouseMenu.addItem("name 6", "description of item 6", false, 6.8162);
        pancakeHouseMenu.addItem("name 7", "description of item 7", false, 7.8162);

        Waitress alice = new Waitress(pancakeHouseMenu, dinerMenu);

        alice.printMenu();
    }
}
```

### Output

```sh
PancakeHouseMenu:
MenuItem(name 4, description of item 4, Vegetarain: false Price 4.82)
MenuItem(name 5, description of item 5, Vegetarain: false Price 5.82)
MenuItem(name 6, description of item 6, Vegetarain: false Price 6.82)
MenuItem(name 7, description of item 7, Vegetarain: false Price 7.82)
DinerMenu:
MenuItem(name 0, description of item 0, Vegetarain: true Price 0.82)
MenuItem(name 1, description of item 1, Vegetarain: true Price 1.82)
MenuItem(name 2, description of item 2, Vegetarain: true Price 2.82)
MenuItem(name 3, description of item 3, Vegetarain: true Price 3.82)
```