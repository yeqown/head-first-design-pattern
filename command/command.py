from abc import ABCMeta, abstractmethod

class Command(object):
    '''
    __metaclass__ = ABCMeta 指定这是一个抽象类

    或者：
    
    class Command(metaclass=ABCMeta): 

        @abstractmethod  
        def execute(self, ...): 
    '''

    __metaclass__ = ABCMeta

    @abstractmethod
    def execute(self):
        pass

    @abstractmethod
    def undo(self):
        pass

class NullCommand(Command):
    '''null command means do nothing'''
    def execute(self):
        print("this is a null command, execute")

    def undo(self):
        print("this is a null command, undo")

class Light(object):
    '''
    Light instance to manage light on or off
    '''

    _lightOn = False
    _instance = None # for singleton
    
    def __new__(cls, *args, **kwargs):
        if cls._instance == None:
            cls._instance = super().__new__(cls)
        return cls._instance

    def lightOn(self):
        self._lightOn = True
        print("light switch to: %s" % self._lightOn)

    def lightOff(self):
        self._lightOn = False
        print("light switch to: %s" % self._lightOn)


# Light Commads ...

class LightOnCommand(Command):

    light = Light()

    def execute(self):
        self.light.lightOn()

    def undo(self):
        self.light.lightOff()

class LightOffCommand(Command):

    light = Light()

    def execute(self):
        self.light.lightOff()

    def undo(self):
        self.light.lightOn()

class AirCondition(object):
    '''
    AirCondition instance to manage AirCondition on or off
    '''

    _AirConditionOn = False
    _instance = None # for singleton
    
    def __new__(cls, *args, **kwargs):
        if cls._instance == None:
            cls._instance = super().__new__(cls)
        return cls._instance

    def AirConditionOn(self):
        self._AirConditionOn = True
        print("AirCondition switch to: %s" % self._AirConditionOn)

    def AirConditionOff(self):
        self._AirConditionOn = False
        print("AirCondition switch to: %s" % self._AirConditionOn)

# AirCondition Commads ...
class AirConditionOnCommand(Command):

    AirCondition = AirCondition()

    def execute(self):
        self.AirCondition.AirConditionOn()

    def undo(self):
        self.AirCondition.AirConditionOff()

class AirConditionOffCommand(Command):

    AirCondition = AirCondition()

    def execute(self):
        self.AirCondition.AirConditionOff()
    
    def undo(self):
        self.AirCondition.AirConditionOn()
