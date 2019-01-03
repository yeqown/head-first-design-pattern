# 策略模式

定义了算法族，分别封装起来让他们之间可以互相替换，此模式让算法的变化独立于使用算法的客户。
如例子中：FlyBehavior 和 QuackBehavior 就是两个算法租；且各自实现了两种不同的行为；

在测试最终，分别有两个类，鸭子类和模型鸭子。同样的行为通过不同的算法产生了不一样的效果。

### TestCase

```golang
type duck struct {
	flyBehavior   flyBehavior
	quackBehavior quackBehavior
}

func (d *duck) SetFlyBehavior(behavior flyBehavior) {
	d.flyBehavior = behavior
}

func (d *duck) SetQuackBehavior(behavior quackBehavior) {
	d.quackBehavior = behavior
}

func (d *duck) Flying() {
	d.flyBehavior.Fly()
}

func (d *duck) Quacking() {
	d.quackBehavior.Quack()
}

func (d *duck) Display() {
	println("i'm duck")
}

func Test_duck(t *testing.T) {
	d := new(duck)

	d.SetFlyBehavior(new(FlyWithWings))
	d.SetQuackBehavior(new(Quack))

	d.Display()
	d.Flying()
	d.Quacking()
}

type modelDuck struct {
	duck
}

func (md *modelDuck) Display() {
	println("i'm model duck")
}

func Test_ModelDuck(t *testing.T) {
	d := new(modelDuck)

	d.SetFlyBehavior(new(FlyNoWay))
	d.SetQuackBehavior(new(Squack))

	d.Display()
	d.Flying()
	d.Quacking()
}

```

### Output

```sh
=== RUN   Test_duck
i'm duck
i can fly with wings
I can Quack
--- PASS: Test_duck (0.00s)
=== RUN   Test_ModelDuck
i'm model duck
i can not fly anyway
I can Squack
--- PASS: Test_ModelDuck (0.00s)
```