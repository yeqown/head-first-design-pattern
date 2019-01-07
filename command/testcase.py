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