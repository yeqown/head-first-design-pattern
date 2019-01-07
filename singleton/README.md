# 单例模式

单件模式确保一个类只有一个实例，并提供一个全局访问点。

### 存在的问题

线程安全。如果两个线程同时想要获取单例实例，那么可能存在两个单例实例。

### 解决办法

1. 同步获取
2. 使用“急切”创建实例，而不是延迟创建

```cpp
// 急切创建示范例子
```

### TestCase

```cpp

struct threadArgs
{
  public:
    int threadid;
    std::string message;
};

void *threadFunc(void *threadid)
{
    struct threadArgs *args = (struct threadArgs *)threadid;
    ChocolateBoiler *ptr = &ChocolateBoiler::getInstance();
    std::cout << "Thread Id: " << args->threadid << std::endl;
    std::cout << "get instance addr: " << ptr << std::endl;
    // do some operate
    ptr->fill();
    ptr->drain();
    return NULL;
}

int main()
{
    // ChocolateBoiler *ptr1 = &ChocolateBoiler::getInstance();
    // ChocolateBoiler *ptr2 = &ChocolateBoiler::getInstance();

    // std::cout << ptr1 << std::endl;
    // std::cout << ptr2 << std::endl;

    // ptr1->fill();
    // ptr1->drain();

    // ptr2->fill();
    // ptr2->drain();

    // multi thread test case
    int i;
    pthread_t threads[2];
    struct threadArgs thread_args[2];

    for (i = 0; i < 2; i++)
    {
        thread_args[i].threadid = i;
        int ir = pthread_create(&threads[i], NULL, threadFunc, (void *)(&thread_args[i]));
        if (ir)
        {
            std::cout << "Error:unable to create thread," << ir << std::endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}
```

### Output

```sh
Thread Id: Thread Id: 10
get instance addr: 0x107aa1140
fill ChocolateBoil
ChocolateBoil drained

get instance addr: 0x107aa1140
fill ChocolateBoil
ChocolateBoil drained
```