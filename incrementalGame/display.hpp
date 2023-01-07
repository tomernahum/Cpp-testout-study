#pragma once


class Displayer
{
public:
    Displayer(void (*displayFunction)());
    Displayer(void (*displayFunction)(), int update_freq_milliseconds);
    void setDisplayFunction(void (*function_pointer)());
    
    void updateDisplay();
    void resetDisplay();

    void startDisplay();
    void stopDisplay();

    //WIP
    void displayText(std::string text);
    std::string askForInput();

private:
    void (*displayFunction)();
    BackgroundWorker bgWorker;
};