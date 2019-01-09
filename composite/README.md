# 组合模式

允许将对象组合成树形结构来表现“整体部分”层次结构。组合能让客户以一致的方式处理个别对象及对象组合。
这个例子是，通过一个抽象类MenuComponent，分别实现了Menu和MenuItem来达到目的。

### Testcase

组合模式和迭代器模式都是同一个例子（菜单扩展问题）；迭代器解决的问题在于如何让服务员跟菜单实现解耦（服务员不用知道每家餐厅的实现详情，能尽可能多的扩展餐厅）；组合模式解决的问题是如何扩展菜单，以达到菜单中包含菜单（这样需要修改各家餐厅的菜单实现方式）。

```java
import java.util.ArrayList;
import java.util.Iterator;

// ABC MenuComponent
abstract class MenuComponent {
    public MenuComponent() {
    }

    public void add(MenuComponent comp) {
        throw new UnsupportedOperationException();
    }

    public void remove(MenuComponent comp) {
        throw new UnsupportedOperationException();
    }

    public MenuComponent getChild(int i) {
        throw new UnsupportedOperationException();
    }

    public String getName() {
        throw new UnsupportedOperationException();
    }

    public String getDescription() {
        throw new UnsupportedOperationException();
    }

    public double getPrice() {
        throw new UnsupportedOperationException();
    }

    public boolean isVegetarain() {
        throw new UnsupportedOperationException();
    }

    public void print() {
        throw new UnsupportedOperationException();
    }
}

/**
 * MenuItem
 */
class MenuItem extends MenuComponent {
    String name;
    String description;
    double price;
    boolean vegetarain;

    public MenuItem(String name, String description, boolean vegetarain, double price) {
        this.name = name;
        this.description = description;
        this.vegetarain = vegetarain;
        this.price = price;
    }

    public String toString() {
        return String.format("MenuItem(%s, %s, Vegetarain: %b Price %.2f)", name, description, vegetarain, price);
    }

    public String getName() {
        return this.name;
    }

    public String getDescription() {
        return this.description;
    }

    public double getPrice() {
        return this.price;
    }

    public boolean isVegetarain() {
        return this.vegetarain;
    }

    public void print() {
        System.out.println(this.toString());
    }
}

class Menu extends MenuComponent {
    ArrayList<MenuComponent> components = new ArrayList<MenuComponent>();
    String name;
    String description;

    public Menu(String name, String desc) {
        this.name = name;
        this.description = desc;
    }

    public void add(MenuComponent comp) {
        this.components.add(comp);
    }

    public void remove(MenuComponent comp) {
        this.components.remove(comp);
    }

    public MenuComponent getChild(int i) {
        return this.components.get(i);
    }

    public String getName() {
        return this.name;
    }

    public String getDescription() {
        return this.description;
    }

    public void print() {
        System.out.println("\nname: " + this.name + "\t");
        System.out.println("description: " + this.description + "\t");
        System.out.println("---------------");

        Iterator<MenuComponent> it = this.components.iterator();
        while (it.hasNext()) {
            MenuComponent comp = it.next();
            comp.print();
        }
    }
}

/**
 * Waitress
 */
class Waitress {
    MenuComponent allMenu;

    public Waitress(MenuComponent allMenu) {
        this.allMenu = allMenu;
    }

    public void printMenu() {
        this.allMenu.print();
    }
}

/**
 * Testcase
 */
public class Testcase {
    public static void main(String[] args) {
        MenuComponent allMenu = new Menu("All Menus", "All Menus combined");
        MenuComponent dinerMenu = new Menu("PANCACKE HOUE MENU", "Breakfast");
        MenuComponent pancakeHouseMenu = new Menu("DINER MENU", "Lunch");
        MenuComponent dessertMenu = new Menu("DESSERT MENU", "dessert of course");

        allMenu.add(dinerMenu);
        allMenu.add(pancakeHouseMenu);

        dinerMenu.add(new MenuItem("name 0", "description of item 0", true, 0.8162));
        dinerMenu.add(new MenuItem("name 1", "description of item 1", true, 1.8162));
        dinerMenu.add(new MenuItem("name 2", "description of item 2", true, 2.8162));
        dinerMenu.add(new MenuItem("name 3", "description of item 3", true, 3.8162));

        pancakeHouseMenu.add(new MenuItem("name 4", "description of item 4", false, 4.8162));
        pancakeHouseMenu.add(new MenuItem("name 5", "description of item 5", false, 5.8162));
        pancakeHouseMenu.add(new MenuItem("name 6", "description of item 6", false, 6.8162));
        pancakeHouseMenu.add(new MenuItem("name 7", "description of item 7", false, 7.8162));

        dessertMenu.add(
                new MenuItem("Pasta", "Spaghetti with Marinara Sauce, and a slice og sourdough bread", true, 3.89));
        // dessertMenu as sub menu of dinerMenu
        dinerMenu.add(dessertMenu);

        Waitress alice = new Waitress(allMenu);

        alice.printMenu();
    }
}
```

### Output

```sh
name: All Menus
description: All Menus combined
---------------

name: PANCACKE HOUE MENU
description: Breakfast
---------------
MenuItem(name 0, description of item 0, Vegetarain: true Price 0.82)
MenuItem(name 1, description of item 1, Vegetarain: true Price 1.82)
MenuItem(name 2, description of item 2, Vegetarain: true Price 2.82)
MenuItem(name 3, description of item 3, Vegetarain: true Price 3.82)

name: DESSERT MENU
description: dessert of course
---------------
MenuItem(Pasta, Spaghetti with Marinara Sauce, and a slice og sourdough bread, Vegetarain: true Price 3.89)

name: DINER MENU
description: Lunch
---------------
MenuItem(name 4, description of item 4, Vegetarain: false Price 4.82)
MenuItem(name 5, description of item 5, Vegetarain: false Price 5.82)
MenuItem(name 6, description of item 6, Vegetarain: false Price 6.82)
MenuItem(name 7, description of item 7, Vegetarain: false Price 7.82)
```