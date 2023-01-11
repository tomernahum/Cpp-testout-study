#include <string>
#include <iostream>
#include <functional>

#include "bgworker.hpp"
#include "display.hpp"

/*
    Idea: (probably won't do)
    autocomplete functionality in display
    1. you just need like a list of words and check if the start of the words and the input match
    2. (so need realtime input monitoring too)
    -I think this might be os/terminal specific. Or I could use something like ncurses I think they keep talking about that in forums
    - Alternatively it could just run on enter and people would press enter instead of tab, then if it's complete just run it normally. That takes out some of the impressiveness though

    3. you need to write the completion to the right of where you're typing and get rid of 1 char at a time 
    or just refresh every time you type a char

    I will consider this if theres ever long commands could just make all the commands a char or a number so
*/

/*
    BUG: display displays over text if console window is small enough that text goes off screen
*/


Displayer::Displayer(std::function<void()> displayFunction)
    : displayFunction(displayFunction), bgWorker(BackgroundWorker( [this]{this->updateDisplay();},  1000 ))
{
    this->resetDisplay();

    /*
    lambda call to member function might be bad practice i really dk
    I am kind of trying to mix OOP and functionalish programming it feels like maybe?
    */
}

Displayer::Displayer(std::function<void()> displayFunction, int update_freq_milliseconds)
    : displayFunction(displayFunction), bgWorker(BackgroundWorker( [this]{this->updateDisplay();},  update_freq_milliseconds ))
{
    this->resetDisplay();
}



void Displayer::setDisplayFunction(std::function<void()> displayFunction)
{
    this->displayFunction = displayFunction;
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
    this->bgWorker.startBackgroundThread();
}

void Displayer::stopDisplay()
{
    this->bgWorker.stopBackgroundThread();
}

//Below Functions are WIP
void Displayer::displayText(const std::string text)          
{
    std::cout << text;
}

std::string Displayer::askForInput()
{
    std::string userInput;
    std::cin >> userInput;
    return userInput;
}