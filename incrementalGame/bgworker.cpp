#include "bgworker.hpp"

BackgroundWorker::BackgroundWorker(std::function<void()> function_pointer, int milliseconds_frequency)
    : customFunction(function_pointer), millisecondsFrequency(milliseconds_frequency)
{
    printf("Registered\n");
    customFunction();
}

void BackgroundWorker::startBackgroundThread()
{
    this->isRunning = true;
    this->bgthread = std::thread(&BackgroundWorker::bgWorkerFunction, this);
}

void BackgroundWorker::stopBackgroundThread()
{
    this->isRunning = false;
    this->bgthread.join();
}


//private member, not sure if I should define here or in header file
const void BackgroundWorker::bgWorkerFunction()
{
    while (this->isRunning)
    {
        this->customFunction();  //function pointers dereferenced automatically

        std::this_thread::sleep_for(std::chrono::milliseconds(this->millisecondsFrequency));
    }
}