# 命令模式

将“请求”封装成对象，以便使用不同的请求、队列或者日志来参数化其他对象，命令模式也支持可撤销的操作；命令对象将动作和接收者封装进对象中，只暴露一个`execute`方法，当`execute`被调用的时候，那些动作就被执行。命令模式将发出请求的对象和执行请求的对象解耦。

## 宏命令

也就是把一组命令组合到一起，通过一个命令可以同时使多个命令工作。

### Testcase

```python
from remoteControl import RemoteControl
from command import LightOffCommand, LightOnCommand, AirConditionOnCommand, AirConditionOffCommand, NullCommand

def test():
    onCommands = [NullCommand() for _ in range(5)]
    offCommands = [NullCommand for _ in range(5)]

    # reg Light commands
    onCommands[0] = LightOnCommand()
    offCommands[0] = LightOffCommand()

    # reg AirCondition commands
    onCommands[1] = AirConditionOnCommand()
    offCommands[1] = AirConditionOffCommand()

    rc = RemoteControl(onCommands=onCommands, offCommands=offCommands)

    rc.commandUndo() # nothing is wanted to happen

    rc.commandOn(0) # means open light
    rc.commandOff(0) # means close light
    rc.commandUndo() # light shoule be on

    rc.commandOn(1) # means open air condition
    # rc.commandOff(1) # means close air condition

if __name__ == "__main__":
    test()
```

### Output

```sh
this is a null command, undo
light switch to: True
light switch to: False
light switch to: True
AirCondition switch to: True
```