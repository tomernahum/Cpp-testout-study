#include <string>
#include <iostream>
#include <functional>

#include "display.hpp"
#include "bgworker.hpp"

Displayer::Displayer(void (*displayFunction)())
    : displayFunction(displayFunction)
{
    this->resetDisplay();
}

void Displayer::setDisplayFunction(void (*function_pointer)())
{
    this->displayFunction = function_pointer;
}

void Displayer::updateDisplay()
{
    std::cout << "\033[s"; //save cursor position
    std::cout << "\033[0;0f"; //go to first char of first line

    
    this->displayFunction();

    
    std::cout << "\033[u"; //restore cursor position    
    std::cout << std::flush; //make sure it refreshes
}

void Displayer::resetDisplay()
{
    std::cout << "\033[2J"; //clear display
    std::cout << "\033[0;0f"; //go to first char of first line

    this->displayFunction();
}


void Displayer::startDisplay()
{
    //TODO

    //void(*bgFunc)() = [this]{this->updateDisplay();}; // Why...
    //BackgroundWorker displayBgw(&bgFunc, 1000); 

    //std::function<void()> func = [this]{this->updateDisplay();};
}

//Below Functions are WIP
void Displayer::displayText(std::string text)
{
    std::cout << text;
}

std::string Displayer::getInput()
{
    std::string userInput;
    std::cin >> userInput;
    return userInput;
}