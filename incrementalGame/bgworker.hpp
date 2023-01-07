#pragma once //moderner equivilent to ifndef, makes compiler run this once

#include <thread>
#include <functional>

class BackgroundWorker
{
public:
    BackgroundWorker(std::function<void()> function_pointer, int miliseconds_frequency);

    void startBackgroundThread();

    // need to call stop background thread sometime in program or else runtime error
    void stopBackgroundThread();

private:
    bool isRunning;
    std::thread bgthread;

    std::function<void()> customFunction;
    int millisecondsFrequency;

    const void bgWorkerFunction();
};
