'''python 实现单例模式的方法有，
1.模块中定的变量
2.__new__ 控制
3.使用装饰器
4.使用元类
'''
class Singleton(object):
    '''
    __new__ 控制对象的创建
    '''
    _instance = None

    def __new__(cls, *args, **kwargs):
        if cls._instance == None:
           cls._instance = super().__new__(cls)
        return cls._instance


class SingletonType(type):
    """
    元类继承type
    """
    _instance = {}

    def __call__(cls, *args, **kwargs):
        if cls not in cls._instance:
            cls._instance[cls] = super().__call__(*args, **kwargs)
        return cls._instance


class Bar(metaclass=SingletonType):
    pass


if __name__ == "__main__":

    ins = Singleton()
    ins2 = Singleton()

    print(id(ins), id(ins2))

    b = Bar()
    b1 = Bar()
    print(id(b), id(b1))