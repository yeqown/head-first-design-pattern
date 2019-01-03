package strategy

// flyBehavior ...
type flyBehavior interface {
	Fly()
}

// FlyWithWings ...
type FlyWithWings struct{}

// Fly of FlyWithWings ...
func (f *FlyWithWings) Fly() {
	println("i can fly with wings")
}

// FlyNoWay ...
type FlyNoWay struct{}

// Fly of FlyNoWay ...
func (f *FlyNoWay) Fly() {
	println("i can not fly anyway")
}
