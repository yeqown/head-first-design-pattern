import java.util.ArrayList;

/**
 * MenuItem
 */
class MenuItem {
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
}

/**
 * Iterator
 */
interface Iterator {
    boolean hasNext();

    Object next();
}

/**
 * PancakeHouseMenuIterator
 */
class PancakeHouseMenuIterator implements Iterator {
    ArrayList<MenuItem> items;
    int position = 0;

    public PancakeHouseMenuIterator(ArrayList<MenuItem> items) {
        this.items = items;
    }

    // implements Iterator
    public boolean hasNext() {
        if (this.position >= this.items.size() || this.items.get(this.position) == null) {
            return false;
        }
        return true;
    }

    public Object next() {
        MenuItem item = this.items.get(this.position);
        this.position += 1;
        return item;
    }
}

/**
 * PancakeHouseMenu
 */
class PancakeHouseMenu {
    ArrayList<MenuItem> items;

    public PancakeHouseMenu() {
        this.items = new ArrayList<MenuItem>();
    }

    public PancakeHouseMenu(MenuItem[] items) {
        this.items = new ArrayList<MenuItem>();
        int i;
        for (i = 0; i < items.length; i++) {
            MenuItem item = items[i];
            this.addItem(item.name, item.description, item.vegetarain, item.price);
        }
    }

    public void addItem(String name, String description, boolean vegetarain, double price) {
        MenuItem item = new MenuItem(name, description, vegetarain, price);
        this.items.add(item);
    }

    public Iterator createIterator() {
        return new PancakeHouseMenuIterator(this.items);
    }
}

/**
 * DinerMenuIterator
 */
class DinerMenuIterator implements Iterator {
    MenuItem[] items;
    int position = 0;

    public DinerMenuIterator(MenuItem[] items) {
        this.items = items;
    }

    // implements Iterator
    public Object next() {
        MenuItem item = this.items[position];
        position = position + 1;
        return item;
    }

    public boolean hasNext() {
        if (this.position >= items.length || items[position] == null) {
            return false;
        }
        return true;
    }
}

/**
 * DinerMenu
 */
class DinerMenu {
    public final int MAX_ITEMS = 6;
    int numberOfItems = 0;
    MenuItem[] items;

    public DinerMenu() {
        this.items = new MenuItem[this.MAX_ITEMS];
    }

    public DinerMenu(MenuItem[] items) {
        this.items = new MenuItem[this.MAX_ITEMS];
        int i;
        for (i = 0; i < items.length; i++) {
            MenuItem item = items[i];
            this.addItem(item.name, item.description, item.vegetarain, item.price);
        }
    }

    public void addItem(String name, String description, boolean vegetarain, double price) {
        if (numberOfItems >= MAX_ITEMS) {
            System.out.println("overflow max_items");
            return;
        }
        MenuItem item = new MenuItem(name, description, vegetarain, price);
        this.items[numberOfItems] = item;
        numberOfItems++;
    }

    public Iterator createIterator() {
        return new DinerMenuIterator(this.items);
    }
}

/**
 * Waitress
 */
class Waitress {
    PancakeHouseMenu pancakeHouseMenu;
    DinerMenu dinerMenu;

    public Waitress(PancakeHouseMenu m1, DinerMenu m2) {
        this.pancakeHouseMenu = m1;
        this.dinerMenu = m2;
    }

    public void printMenu() {
        Iterator iter1 = this.pancakeHouseMenu.createIterator();
        Iterator iter2 = this.dinerMenu.createIterator();

        System.out.println("PancakeHouseMenu: ");
        this.printMenu(iter1);
        System.out.println("DinerMenu: ");
        this.printMenu(iter2);
    }

    public void printMenu(Iterator iter) {
        while (iter.hasNext()) {
            MenuItem item = (MenuItem) iter.next();
            System.out.println(item.toString());
        }
    }

    // other funcs ... ignored
}

/**
 * Testcase
 */
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