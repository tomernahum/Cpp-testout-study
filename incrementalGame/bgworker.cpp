#include "bgworker.hpp"

BackgroundWorker::BackgroundWorker(void (*function_pointer)(), int milliseconds_frequency)
    : customFunctionPointer(function_pointer), millisecondsFrequency(milliseconds_frequency)
{
    printf("Registered\n");
    customFunctionPointer();
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
        this->customFunctionPointer();  //function pointers dereferenced automatically

        std::this_thread::sleep_for(std::chrono::milliseconds(this->millisecondsFrequency));
    }
}