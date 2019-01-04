package decorate

// Mocha decorator of Beverage
type Mocha struct{ b Beverage }

// Wrap of Mocha
func (m *Mocha) Wrap(b Beverage) { m.b = b }

// Description of Mocha
func (m *Mocha) Description() string { return m.b.Description() + ", Mocha" }

// Cost of Mocha
func (m *Mocha) Cost() float32 { return m.b.Cost() + 0.20 }

// Soy decorator of Beverage
type Soy struct{ b Beverage }

// Wrap of Soy
func (m *Soy) Wrap(b Beverage) { m.b = b }

// Description of Soy
func (m *Soy) Description() string { return m.b.Description() + ", Soy" }

// Cost of Soy
func (m *Soy) Cost() float32 { return m.b.Cost() + 0.17 }

// Whip decorator of Beverage
type Whip struct{ b Beverage }

// Wrap of Whip
func (m *Whip) Wrap(b Beverage) { m.b = b }

// Description of Whip
func (m *Whip) Description() string { return m.b.Description() + ", Whip" }

// Cost of Whip
func (m *Whip) Cost() float32 { return m.b.Cost() + 0.33 }
