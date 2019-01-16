# 代理模式

为另一个对象提供一个替身或者占位符以控制对这个对象的访问。

> 代理在结构上相似于装饰器，但目的并不一致

### 常见代理

* 防火墙代理 （控制主题访问，保护主题不被恶意攻击）
* 智能代理 （当主题被引用时，进行额外的计算）
* 缓存代理 （为开销大的对象提供暂时存储）
* 同步代理 （在多线程的情况下为主题提供安全的访问）
* 复杂隐藏代理 （用来隐藏一个类的复杂度，并进行访问控制，也可以称为外观代理）
* 写入时复制代理 （用来控制对象的复制，方法是延迟对象的复制，直到客户真的需要？）

### Testcase

```java
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

/**
 * PersonBean
 */
interface PersonBean {

    public void setIntrest(String intrest);

    public String getIntrest();

    public void setGender(String gender);

    public String getGender();

    public void setName(String name);

    public String getName();

    public int getHotOrNotRating();

    public void setHotOrNotRating(int rating);
}

/**
 * PersonBeanImpl
 */
class PersonBeanImpl implements PersonBean {
    String name;
    String gender;
    String intrest;
    int rating;
    int rateCnt;

    PersonBeanImpl(String name, String gender, String intrest, int rating, int rateCnt) {
        this.name = name;
        this.gender = gender;
        this.intrest = intrest;
        this.rating = rating;
        this.rateCnt = rateCnt;
    }

    public void setIntrest(String intrest) {
        this.intrest = intrest;
    }

    public String getIntrest() {
        return intrest;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getGender() {
        return gender;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int getHotOrNotRating() {
        if (rateCnt == 0) {
            return 0;
        }
        return (rating / rateCnt);
    }

    public void setHotOrNotRating(int rating) {
        this.rating += rating;
        this.rateCnt++;
    }
}

/**
 * OwnerInvocationHandler
 */
class OwnerInvocationHandler implements InvocationHandler {
    PersonBean person;

    OwnerInvocationHandler(PersonBean p) {
        this.person = p;
    }

    public Object invoke(Object proxy, Method method, Object[] args) throws IllegalAccessException {
        try {
            if (method.getName().startsWith("get")) {
                return method.invoke(this.person, args);
            } else if (method.getName() == "setHotOrNotRating") {
                throw new IllegalAccessException();
            } else if (method.getName().startsWith("set")) {
                return method.invoke(this.person, args);
            }
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }

        return null;
    }
}

/**
 * NonOwnerInvocationHandler
 */
class NonOwnerInvocationHandler implements InvocationHandler {
    PersonBean person;

    NonOwnerInvocationHandler(PersonBean p) {
        this.person = p;
    }

    public Object invoke(Object proxy, Method method, Object[] args) throws IllegalAccessException {
        try {
            if (method.getName().startsWith("get")) {
                return method.invoke(this.person, args);
            } else if (method.getName() == "setHotOrNotRating") {
                return method.invoke(this.person, args);
            } else if (method.getName().startsWith("set")) {
                throw new IllegalAccessException();
            }
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }
        return null;
    }

}

/**
 * Testcase
 */
public class Testcase {
    // public static PersonBean getOwnerProxy(PersonBean p) {
    // return (PersonBean) Proxy.newProxyInstance(p.getClass().getClassLoader(),
    // p.getClass().getInterfaces(),
    // new OwnerInvocationHandler(p));
    // }

    // public static PersonBean getNonOwnerProxy(PersonBean p) {
    // return (PersonBean) Proxy.newProxyInstance(p.getClass().getClassLoader(),
    // p.getClass().getInterfaces(),
    // new NonOwnerInvocationHandler(p));
    // }

    public static PersonBean getProxy(InvocationHandler h, PersonBean p) {
        return (PersonBean) Proxy.newProxyInstance(p.getClass().getClassLoader(), p.getClass().getInterfaces(), h);
    }

    public static void main(String[] args) {
        PersonBean joe = new PersonBeanImpl("joe", "male", "playing egame; read ebook; I'm fall in love with e;", 2, 100);

        // test ownerProxy
        PersonBean ownerProxy = getProxy(new OwnerInvocationHandler(joe), joe);
        System.out.println("owner proxy getName: " + ownerProxy.getName());
        ownerProxy.setGender("male or not");
        System.out.println("owner proxy setGender success: " + ownerProxy.getGender());
        try {
            ownerProxy.setHotOrNotRating(100);
        } catch (Exception e) {
            System.out.println("cannot set rating to ownerProxy");
        }

        // test nonOwnerProxy
        PersonBean nonOwnerProxy = getProxy(new NonOwnerInvocationHandler(joe), joe);
        System.out.println("non owner proxy getName: " + nonOwnerProxy.getName());
        nonOwnerProxy.setHotOrNotRating(5);
        System.out.println("set rating to nonOwnerProxy: " + nonOwnerProxy.getHotOrNotRating());
        try {
            nonOwnerProxy.setGender("male");
        } catch (Exception e) {
            System.out.println("non owner proxy cannot reset Gender: " + nonOwnerProxy.getGender());
        }
    }
}
```

### Output

```sh
owner proxy getName: joe
owner proxy setGender success: male or not
cannot set rating to ownerProxy
non owner proxy getName: joe
set rating to nonOwnerProxy: 0
non owner proxy cannot reset Gender: male or not
```