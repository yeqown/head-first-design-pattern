package observer

import (
	"fmt"
)

// CurrentConditionDisplay ... 实现了Observer 和 Displayer 两个接口
type CurrentConditionDisplay struct {
	weatherData Subject
	temprature  float32
	humidity    float32
	// pressure   float32
}

// Construct ... 用于注册到主题的观察者
func (ccd *CurrentConditionDisplay) Construct(wd Subject) {
	ccd.weatherData = wd
	ccd.weatherData.RegisterObserver(ccd)
}

// Update func of CurrentConditionDisplay
func (ccd *CurrentConditionDisplay) Update(temp, humidty, pressure float32) {
	ccd.temprature = temp
	ccd.humidity = humidty
	// ccd.pressure = pressure
	ccd.Display()
}

// Display func of CurrentConditionDisplay
func (ccd *CurrentConditionDisplay) Display() {
	fmt.Printf("Current Condition: %.2f F degrees and %.2f humidity\n", ccd.temprature, ccd.humidity)
}

// AvgDisplay ... 实现了Observer 和 Displayer 两个接口
type AvgDisplay struct {
	weatherData Subject

	tempratures []float32
	humiditys   []float32
	pressures   []float32

	avgTemp     float32
	avgHumidity float32
	avgPressure float32
}

// Construct ... 用于注册到主题的观察者
func (ad *AvgDisplay) Construct(wd Subject) {
	ad.weatherData = wd
	ad.weatherData.RegisterObserver(ad)
}

// Update func of AvgDisplay
func (ad *AvgDisplay) Update(temp, humidty, pressure float32) {
	ad.tempratures = append(ad.tempratures, temp)
	ad.humiditys = append(ad.humiditys, humidty)
	ad.pressures = append(ad.pressures, pressure)

	ad.avgTemp += (temp - ad.avgTemp) / float32(len(ad.tempratures))
	ad.avgPressure += (pressure - ad.avgPressure) / float32(len(ad.pressures))
	ad.avgHumidity += (humidty - ad.avgHumidity) / float32(len(ad.humiditys))

	ad.Display()
}

// Display func of AvgDisplay
func (ad *AvgDisplay) Display() {
	fmt.Printf("Avg Display: %.2fF degrees, %.2f humidity, %.2f pressure\n",
		ad.avgTemp, ad.avgHumidity, ad.avgPressure)
}
