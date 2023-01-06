#pragma once //moderner equivilent to ifndef, makes compiler run this once

#include <thread>

class BackgroundWorker
{
public:
    BackgroundWorker(void (*function_pointer)(), int miliseconds_frequency);

    void startBackgroundThread();

    // need to call stop background thread sometime in program or else runtime error
    void stopBackgroundThread();

private:
    bool isRunning;
    std::thread bgthread;

    void (*customFunctionPointer)();
    int millisecondsFrequency;

    const void bgWorkerFunction();
};
