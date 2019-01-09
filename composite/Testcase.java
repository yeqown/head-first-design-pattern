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