public class Tea extends CaffeineBeverageWithHook {
    void brew() {
        System.out.println("Tea brewing");
    }

    void addCondiments() {
        System.out.println("Tea adding Condiments? Are u kidding me !!!");
    }
    
    // 重载钩子函数
    boolean customerWantCondiments() {
        return false;
    }
};