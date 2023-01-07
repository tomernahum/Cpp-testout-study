#define print(x) std::cout << x << "\n"

#include <iostream>
#include <string>

#include "bgworker.hpp"
#include "display.hpp"

namespace GameData
{
    int points = 0; //todo: would be more fun as floats I think
    int points_per_second = 1;
    //also todo: system for rounding large numbers that wouldn't fit into bits (ie 11.5 quadrillion points)
}

//not currently used, just playing arround
class GameDataa
{
public:
    GameDataa()
        : points(0), points_per_second(0)
    {
    }
    int points;
    int points_per_second;

    void runpointspersecondbgthread(){

    }
};


void displayFunc()
{
    std::cout << "Points: " << GameData::points;
    std::cout << "\nPps: " << GameData::points_per_second;
    std::cout << "\n> "; //TODO: maybe move outside of the updating part
}



void pointsIncrementerBgFunc()
{
    GameData::points += GameData::points_per_second;
}

int main()
{
    //setup
    BackgroundWorker pointsIncrementerBgw(&pointsIncrementerBgFunc, 1000);
    pointsIncrementerBgw.startBackgroundThread();

    Displayer display(&displayFunc, 500);
    display.startDisplay(); //not work
 

    //gameplay
    while (true)
    {
        std::string userInput;
        userInput = display.askForInput();

        if (userInput == "exit" || userInput == "quit") {
            break;
        }

        else if (userInput == "shop") {
            display.displayText("Welcome to the shop, which do you buy? \n> ");
            userInput = display.askForInput();
            
            display.displayText("Yeah I cant hear you yet, have an extra pps \n> ");
            GameData::points_per_second++;
            
            userInput = display.askForInput(); //needs this or it resets display instantly after printing so you dont see it
        }


        display.resetDisplay(); //todo: should this be abstracted into display more etc
        
    }

    //wrap up
    display.stopDisplay();
    pointsIncrementerBgw.stopBackgroundThread();

    return 0;
}