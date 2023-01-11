#pragma once

#include <functional>

//should stuff that modifies the actual terminal be marked as const? because it doesn't modify a member function but you could think of the terminal as a member if we were using something other than terminal    probably not even what thats about
class Displayer
{
public:
    Displayer(std::function<void()> displayFunction);
    Displayer(std::function<void()> displayFunction, int update_freq_milliseconds);
    void setDisplayFunction(std::function<void()> displayFunction);
    
    void updateDisplay();
    void resetDisplay();

    void startDisplay();
    void stopDisplay();

    //WIP
    void displayText(const std::string text);
    std::string askForInput();

private:
    std::function<void()> displayFunction;
    BackgroundWorker bgWorker;
};