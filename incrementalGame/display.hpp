#pragma once


class Displayer
{
public:
    Displayer(void (*displayFunction)());
    void setDisplayFunction(void (*function_pointer)());
    
    void updateDisplay();
    void resetDisplay();

    //WIP
    void displayText(std::string text);
    std::string getInput();

private:
    void (*displayFunction)();
};