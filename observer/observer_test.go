package observer

import (
	"math/rand"
	"testing"
	"time"
)

func Test_Observer(t *testing.T) {
	var (
		weatherData         = new(WeatherData)
		temp        float32 = 80.0
		humidty     float32 = 80.0
		pressure    float32 = 80.0

		ccd = new(CurrentConditionDisplay)
		ad  = new(AvgDisplay)
	)

	ccd.Construct(weatherData)
	ad.Construct(weatherData)

	for i := 0; i < 10; i++ {
		temp += rand.Float32()
		humidty += rand.Float32()
		pressure += rand.Float32()
		weatherData.setMeasurements(temp, humidty, pressure)
		time.Sleep(1 * time.Second)
	}
}
