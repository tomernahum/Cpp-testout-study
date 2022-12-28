
#include <iostream>
#include <thread>

#define print(x) std::cout << x << std::endl

class BackgroundWorker
{
public:
    BackgroundWorker(void (*function_pointer)(), int miliseconds_frequency)
    {
        m_Function = function_pointer;
        m_milisecondsFrequency = miliseconds_frequency;
    }

    void startBackgroundThread()
    {
        running = true;
        bgthread = std::thread(&BackgroundWorker::bgWorkerFunction, this); // dont 100% understand why it has to be done this way
    }

    // need to call stop background thread sometime in program or else runtime error
    void stopBackgroundThread()
    {
        running = false;
        bgthread.join();
    }

private:
    bool running;
    std::thread bgthread;

    void (*m_Function)();
    int m_milisecondsFrequency;

    void bgWorkerFunction()
    {

        while (running)
        {
            m_Function();

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};

int points = 0;
int points_per_second = 1;
void pointsIncrementerBg()
{
    points += points_per_second;
    std::cout << "\rP: " << points << std::flush;
}

int main()
{
    BackgroundWorker bg(&pointsIncrementerBg, 1000);
    bg.startBackgroundThread();

    while (true)
    {
        std::string userInput;
        std::cin >> userInput;

        if (userInput == "exit") {
            break;
        }
    }

    bg.stopBackgroundThread();
}
