package strategy

import "testing"

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
