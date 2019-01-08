# 模板方法模式

模板方法控制了算法，它让子类能够提供一些步骤的实现；模板方法在一个方法中定一个一个算法的骨架，而将一些步骤延迟到子类中。模板方法使得子类可以在不改变算法结构的情况下，重新定义算法中的某些步骤。

# 好莱坞原则

别打电话给我，我会打电话给你！当高层组件依赖低层组件，低层组件又依赖高层组件的时候，允许底层组件将自己挂钩到系统上，但是高层组件会决定什么时候和怎么样使用这些组件。

### Testcase

```java
public class Testcase {
    public static void main(String[] args) {
        Coffee cof = new Coffee();
        Tea tea = new Tea();

        System.out.println("Making coffee...");
        cof.prepareRecipe();
        System.out.println("\nMaking tea...");
        tea.prepareRecipe();
    }
}
```

### Output
```sh
Making coffee...
Boiling water
Coffee brewing
Pouring into cup
Coffee adding caffeine and sugar

Making tea...
Boiling water
Tea brewing
Pouring into cup
```