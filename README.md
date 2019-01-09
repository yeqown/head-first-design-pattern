# Head First Design Pattern

所有的例子都源于《[Head First Design Pattern](#)》。用Golang，JAVA，C++或者Python来书写了一遍，便于理解OO设计模式并且应用于编程开发中。

# 目录

* [策略模式](strategy/README.md)
* [观察者模式](observer/README.md)
* [装饰器模式](decorate/README.md)
* [工厂模式](factory/README.md)
* [单例模式](singleton/README.md)
* [命令模式](command/README.md)
* [适配器模式](adaptor/README.md)
* [外观模式](facade/README.md)
* [模板模式](template/README.md)
* [迭代器模式](iterator/README.md)
* [组合器模式](composite/README.md)

# OO的原则

* 封装变化
* 多用组合，少用继承
* 针对借口编程，不针对实现编程
* 为交互对象之间的松耦合设计而努力
* 开放关闭原则，对扩展开发，对修改关闭
* 依赖倒置原则，要依赖抽象，不要依赖具体类
* 最少知识，不要让太多的类耦合在一起。[原则](/facade/README.md#最少知识原则)
* 底层注册到高层，高层自行决定调用。[原则](/template/README.md#好莱坞原则)
* 单一责任原则。[原则](/iterator/README.md#单一责任原则)
* 类应该只有一个改变的理由

### 关于多语言书写

原书是全部用Java书写，本人的初衷是想在Golang中书写一遍，结果发现强行在Golang应用OO模式，反而不利于理解，便换用C++尝试；在使用过程中，C++书写的时候效率又偏低～（个人问题：心急）；又换到了Python来书写，python书写倒是没有没什么问题，但是毕竟是弱类型语言，在声明的时候无法指定类型～，习惯了先声明后使用的强迫症吧；到最后还是选择使用Java来书写～。一切的一切都是因为本人是一个善变（贬义）的程序猿。 —— 20190108