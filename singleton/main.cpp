#include <iostream>
#include <pthread.h>

class ChocolateBoiler
{
  private:
    bool empty;
    bool boiled;
    // static ChocolateBoiler *uniqueInstance;
    ChocolateBoiler()
    {
        empty = true;
        boiled = false;
    }
    ChocolateBoiler(ChocolateBoiler const &);
    void operator=(ChocolateBoiler const &);

  public:
    static ChocolateBoiler &getInstance()
    {
        static ChocolateBoiler uniqueInstance;
        return uniqueInstance;
    }
    // ChocolateBoiler(ChocolateBoiler const &) = delete;
    // void operator=(ChocolateBoiler const &) = delete;

    void fill()
    {
        if (empty)
        {
            empty = false;
            boiled = false;
            // fill ingredient into
            std::cout << "fill ChocolateBoil" << std::endl;
            // pretend time delayed
            boiled = true;
            return;
        }
        std::cout << "cannot fill ChocolateBoil" << std::endl;
    }

    void drain()
    {
        if (!empty && boiled)
        {
            std::cout << "ChocolateBoil drained" << std::endl;
            empty = true;
            boiled = false;
            // output product
            return;
        }
        std::cout << "ChocolateBoil cannot drain" << std::endl;
    }

    bool isEmpty()
    {
        return empty;
    }

    bool isBoiled()
    {
        return boiled;
    }
};

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