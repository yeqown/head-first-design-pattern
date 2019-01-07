from subsystem import *

class HomeTheaterFacade(object):
    dvdPlayer = None
    audioPlayer = None
    cdPlayer = None
    # more subsystem ignored

    def __init__(self, dvdPlayer: DvdPlayer, audioPlayer: AudioPlayer, cdPlayer:CDPlayer):
        self.dvdPlayer = dvdPlayer
        self.audioPlayer = audioPlayer
        self.cdPlayer = cdPlayer

    def playVideo(self):
        self.dvdPlayer.start()
        self.audioPlayer.start()
        self.cdPlayer.start()
        print("\nseveral hours later~ \n")
    
    def endPlayVideo(self):
        self.dvdPlayer.stop()
        self.audioPlayer.stop()
        self.cdPlayer.stop()

if __name__ == "__main__":
    dvd = DvdPlayer()
    audio = AudioPlayer()
    cd = CDPlayer()

    theater = HomeTheaterFacade(dvd, audio, cd)

    theater.playVideo()
    theater.endPlayVideo()