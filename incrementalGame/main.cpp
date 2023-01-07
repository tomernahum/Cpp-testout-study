#define print(x) std::cout << x << "\n"

#include <iostream>
#include <string>

#include "bgworker.hpp"

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

/*--Display--*/

void displayBg()
{
    std::cout << "\033[s"; //save cursor position

    std::cout << "\033[0;0f"; //go to first char of first line

    std::cout << "Points: " << GameData::points << ", Pps: " << GameData::points_per_second;
    std::cout << "\n> "; //TODO: maybe move outside of the updating part

    std::cout << "\033[u"; //restore cursor position 
   
    std::cout << std::flush; //make sure it refreshes

    //print(GameData::points);

}

//TODO: maybe display class

void resetDisplay()
{
    std::cout << "\033[2J"; //clear display
    std::cout << "\033[0;0f"; //go to first char of first line

    std::cout << "Points: " << GameData::points << ", Pps: " << GameData::points_per_second;
    std::cout << "\n> ";
}

/*----*/

void pointsIncrementerBg()
{
    GameData::points += GameData::points_per_second;
    displayBg();
}

int main()
{
    //setup
    BackgroundWorker bgW(&pointsIncrementerBg, 1000);
    bgW.startBackgroundThread();
    resetDisplay();

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

        resetDisplay();
        
    }

    //wrap up
    bgW.stopBackgroundThread();

    return 0;
}