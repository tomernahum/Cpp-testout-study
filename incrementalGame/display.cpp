#include <string>
#include <iostream>

#include "display.hpp"

Displayer::Displayer(void (*displayFunction)())
    : displayFunction(displayFunction)
{}

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