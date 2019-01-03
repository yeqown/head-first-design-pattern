package observer

// Observer ... 观察者接口
type Observer interface {
	Update(temp, humidty, pressure float32)
}

// Subject ... 主题接口
type Subject interface {
	RegisterObserver(o Observer)
	RemoveObserver(o Observer)
	NotifyObservers()
}

// Displayer ... 告示板接口
type Displayer interface {
	Display()
}
