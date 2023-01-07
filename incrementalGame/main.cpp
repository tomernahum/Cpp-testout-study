#define print(x) std::cout << x << "\n"

#include <iostream>
#include <string>

#include "bgworker.hpp"
#include "display.hpp"

namespace GameData
{
    int points = 0;
    int points_per_second = 1;
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

    Displayer display(&displayFunc);
    display.startDisplay();
 

    //gameplay
    while (true)
    {
        std::string userInput;
        std::cin >> userInput;

        if (userInput == "shop") {
            std::cout << "Welcome to the shop, which do you buy? \n> ";
            std::cin >> userInput;
            std::cout << "Yeah I cant hear you yet, have an extra pps \n> ";
            GameData::points_per_second++;
            std::cin >> userInput; //needs this or it resets display instantly after printing so you dont see it
        }

        if (userInput == "exit") {
            break;
        }

        //resetDisplay();
        
    }

    //wrap up
    pointsIncrementerBgw.stopBackgroundThread();

    return 0;
}