# 外观模式

提供了一个统一的接口，用来访问访问子系统重的一群接口。外观定义了一个高层接口，让子系统更容易使用。

## 最少知识原则

就对象而言，在该对象的方法内，我们就只应该调用属于以下范围的方法：

* 该对象本身
* 被当作方法的参数而传递进来的对象
* 此方法所创建或实例化的任何对象
* 对象的任何组件

### Testcase

```python
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
```

### Output

```sh
DVD player      ON
Audio player    ON
CD player       ON

several hours later~

DVD player      OFF
Audio player    OFF
CD player       OFF
```