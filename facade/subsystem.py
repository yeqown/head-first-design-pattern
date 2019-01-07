def onoff(b: bool):
    return "ON" if b else "OFF"

class Player(object):
    name = "None"
    enabled = False

    def start(self):
        self.enabled = True
        print("%s player \t%s" % (self.name, onoff(self.enabled)))
    
    def stop(self):
        self.enabled = False

        print("%s player \t%s" % (self.name, onoff(self.enabled)))

class DvdPlayer(Player):
    name = "DVD"

class AudioPlayer(Player):
    name = "Audio"

class CDPlayer(Player):
    name = "CD"