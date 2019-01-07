from command import Command, NullCommand

class RemoteControl(object):

    '''
    RemoteControl 是一个遥控器类，控制其他电器的关闭和开启
    '''

    onCommands = [] # Command instance
    offCommands = [] # Command instance
    undoCommand = NullCommand() # last command called, support undo function

    def __init__(self, *args, **kwargs):
        # print(kwargs)
        if 'onCommands' not in kwargs.keys():
            raise Exception("must contains onCommands")
        self.onCommands = kwargs['onCommands']
        if 'offCommands' not in kwargs:
            raise Exception("must contains offCommands")
        self.offCommands = kwargs['offCommands']

    def commandOn(self, slotIdx: int):
        '''
        hah~ python not support define vars with type, so i add this type lint
        '''
        try:
            item = self.onCommands[slotIdx]
        except IndexError as e:
            print("%d command not support, caused by: %s" % (slotIdx, e))
            return
        if not isinstance(item, Command):
            print("command error: not instance of Command!")
            return
        item.execute() # call command execute
        self.undoCommand = self.onCommands[slotIdx]        
    
    def commandOff(self, slotIdx: int):
        try:
            item = self.offCommands[slotIdx]
        except IndexError as e:
            print("%d command not support, caused by: %s" % (slotIdx, e))
            return
        if not isinstance(item, Command):
            print("command error: not instance of Command!")
            return
        item.execute() # call command execute
        self.undoCommand = self.offCommands[slotIdx]

    def commandUndo(self):
        self.undoCommand.undo()