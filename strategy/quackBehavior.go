package strategy

// quackBehavior ...
type quackBehavior interface {
	Quack()
}

// Quack ...
type Quack struct{}

// Quack of Quack ...
func (q *Quack) Quack() {
	println("I can Quack")
}

// Squack ...
type Squack struct{}

// Quack of Squack ...
func (s *Squack) Quack() {
	println("I can Squack")
}
