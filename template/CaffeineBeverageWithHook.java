public abstract class CaffeineBeverageWithHook {
    // 这里是算法骨架
    final void prepareRecipe() {
        this.boilWater();
        this.brew();
        this.pourInCup();
        // 调用钩子函数
        if (this.customerWantCondiments()) {
            this.addCondiments();
        }
    }

    // 这题提供差异方法的抽象函数，用于子类实现，提供不同的饮料
    abstract void brew();
    abstract void addCondiments();

    void boilWater() {
        System.out.println("Boiling water");
    }

    void pourInCup() {
        System.out.println("Pouring into cup");
    }

    // 钩子函数；如果是Golang, 可以直接判断addCondiments == nil 来决定是否调用，但是目的是一样的。
    boolean customerWantCondiments() {
        return true;
    }
}