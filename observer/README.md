# 观察者模式

在对象之间定义一对多的依赖，这样一来，当一个对象改变状态，依赖他的对象都会收到通知，并自动更新。
应用此模式的时候，可以选择 “pull” 和 “push” 两种方式。

### TestCase

```golang
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
```

### Output

```sh
=== RUN   Test_Observer
Current Condition: 80.60 F degrees and 80.94 humidity
Avg Display: 80.60F degrees, 80.94 humidity, 80.66 pressure
Current Condition: 81.04 F degrees and 81.37 humidity
Avg Display: 80.82F degrees, 81.15 humidity, 81.01 pressure
Current Condition: 81.11 F degrees and 81.52 humidity
Avg Display: 80.92F degrees, 81.28 humidity, 81.15 pressure
Current Condition: 81.41 F degrees and 82.04 humidity
Avg Display: 81.04F degrees, 81.47 humidity, 81.43 pressure
Current Condition: 81.62 F degrees and 82.42 humidity
Avg Display: 81.16F degrees, 81.66 humidity, 81.66 pressure
Current Condition: 82.09 F degrees and 82.70 humidity
Avg Display: 81.31F degrees, 81.83 humidity, 81.86 pressure
Current Condition: 82.77 F degrees and 82.92 humidity
Avg Display: 81.52F degrees, 81.99 humidity, 82.04 pressure
Current Condition: 83.13 F degrees and 83.49 humidity
Avg Display: 81.72F degrees, 82.17 humidity, 82.27 pressure
Current Condition: 83.43 F degrees and 83.79 humidity
Avg Display: 81.91F degrees, 82.35 humidity, 82.54 pressure
Current Condition: 83.63 F degrees and 84.65 humidity
Avg Display: 82.08F degrees, 82.58 humidity, 82.83 pressure
--- PASS: Test_Observer (10.03s)
```