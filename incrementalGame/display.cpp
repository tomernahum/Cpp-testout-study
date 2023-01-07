#include <string>
#include <iostream>
#include <functional>

#include "bgworker.hpp"
#include "display.hpp"


Displayer::Displayer(void (*displayFunction)())
    : displayFunction(displayFunction), bgWorker(BackgroundWorker( [this]{this->updateDisplay();},  1000 ))
{
    this->resetDisplay();
    //bgWorker(   BackgroundWorker(   [this]{this->updateDisplay();},    update_freq_milliseconds   )   )
}

Displayer::Displayer(void (*displayFunction)(), int update_freq_milliseconds)
    : displayFunction(displayFunction), bgWorker(BackgroundWorker( [this]{this->updateDisplay();},  update_freq_milliseconds ))
{
    this->resetDisplay();
    //bgWorker(   BackgroundWorker(   [this]{this->updateDisplay();},    update_freq_milliseconds   )   )
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
    
    std::function<void()> func = [this]{this->updateDisplay();};
    this->bgWorker.startBackgroundThread();
    
    /*
    ^ Might be bad practice idk. 
    I am kind of trying to mix OOP and functionalish programming it feels like maybe?
    */

}

void Displayer::stopDisplay()
{
    this->bgWorker.stopBackgroundThread();
}

//Below Functions are WIP
void Displayer::displayText(std::string text)
{
    std::cout << text;
}

std::string Displayer::askForInput()
{
    std::string userInput;
    std::cin >> userInput;
    return userInput;
}