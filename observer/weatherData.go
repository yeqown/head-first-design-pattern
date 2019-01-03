package observer

// WeatherData ... 实现Subject接口的天气数据源
type WeatherData struct {
	observers  []Observer
	temprature float32
	humidity   float32
	pressure   float32
}

// RegisterObserver of WeatherData to implement Subject interface
func (wd *WeatherData) RegisterObserver(o Observer) {
	wd.observers = append(wd.observers, o)
}

// RemoveObserver of WeatherData to implement Subject interface
func (wd *WeatherData) RemoveObserver(o Observer) {
	l := len(wd.observers)
	mark := -1
	for i := 0; i < l; i++ {
		if o == wd.observers[i] {
			mark = i
			break
		}
	}
	if mark == -1 {
		return
	}

	wd.observers = append(wd.observers[:mark], wd.observers[mark:]...)
}

// NotifyObservers of WeatherData to implement Subject interface
func (wd *WeatherData) NotifyObservers() {
	l := len(wd.observers)
	for i := 0; i < l; i++ {
		wd.observers[i].Update(wd.temprature, wd.humidity, wd.pressure)
	}
}

// 当观测数据改变时候触发
func (wd *WeatherData) measurementsChanged() {
	wd.NotifyObservers()
}

// 手动更新观测数据
func (wd *WeatherData) setMeasurements(temp, humidty, pressure float32) {
	wd.temprature = temp
	wd.humidity = humidty
	wd.pressure = pressure

	wd.measurementsChanged()
}
