package decorate

// Beverage 饮料接口
type Beverage interface {
	Cost() float32
	Description() string
}

// Espresso ...
type Espresso struct{}

// Cost of Espre ...
func (m *Espresso) Cost() float32 { return 1.99 }

// Description of Espre
func (m *Espresso) Description() string { return "Espresso" }

// HouseBlend ...
type HouseBlend struct{}

// Cost of House ...
func (m *HouseBlend) Cost() float32 { return 0.99 }

// Description of House
func (m *HouseBlend) Description() string { return "HouseBlend" }

// DarkRoast ...
type DarkRoast struct{}

// Cost of DarkR ...
func (m *DarkRoast) Cost() float32 { return 1.23 }

// Description of DarkR
func (m *DarkRoast) Description() string { return "DarkRoast" }

// Decaf ...
type Decaf struct{}

// Cost of Decaf ...
func (m *Decaf) Cost() float32 { return 1.4 }

// Description of Decaf
func (m *Decaf) Description() string { return "Decaf" }
