/*
Pseudocode
    every second/less:
        update points based on points per second
        rerender display with updated points




    every game loop:
        display points (should be updating)
        display problem
        get input

        if input is answer to problem:
            increment points appropriately
            reset challenge
            restart gameloop
        if input is shop:
            shop mode:
                display options
                user input
                buy the thing
                    deduct coins and uptate active upgrades list
*/

#define print(x) std::cout << x << std::endl

#include <iostream>
#include <thread>

namespace backgroundThread
{
    //"private"
    static bool m_running = true;
    void bgWorkerFunction()
    {
        while (m_running)
        {
            print("hello");
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
    std::thread bgthread;

    //"public"
    void startBackgroundThread()
    {
        m_running = true;
        bgthread = std::thread(&bgWorkerFunction);
    }
    void stopBackgroundThread()
    {
        m_running = false;
        bgthread.join();
    }
}



class BackgroundWorker
{
public:
    //need to call stop background thread sometime in program or else runtime error
    void startBackgroundThread()
    {
        running = true;
        bgthread = std::thread(&BackgroundWorker::bgWorkerFunction, this); //dont 100% understand why it has to be done this way
    }
    void stopBackgroundThread()
    {
        running = false;
        bgthread.join();
    }

private:
    bool running;
    std::thread bgthread;
    void bgWorkerFunction(){
        while (running)
        {
            print("hello");
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};


int main()
{
    if (false)
    {
        backgroundThread::startBackgroundThread();

        std::string x;
        std::cin >> x;

        backgroundThread::stopBackgroundThread();
    }

    BackgroundWorker backgroundWorker;
    backgroundWorker.startBackgroundThread();
    std::string x;
    std::cin >> x;
    backgroundWorker.stopBackgroundThread();

    return 0;
}
