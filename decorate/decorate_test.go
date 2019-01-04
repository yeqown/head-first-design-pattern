package decorate

import (
	"fmt"
	"testing"
)

func Test_Decorate(t *testing.T) {
	coffee := new(Espresso)
	mocha := new(Mocha)
	mocha.Wrap(coffee)
	soy := new(Soy)
	soy.Wrap(mocha)

	PrintBeverage(soy)
}

func PrintBeverage(b Beverage) {
	fmt.Printf("Coffee %s and Cost: %.2f", b.Description(), b.Cost())
}
