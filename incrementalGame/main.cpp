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

    std::cout << "\033[1A\r"; //go up a line & go to start of line

    std::cout << "Points: " << GameData::points << ", Pps: " << GameData::points_per_second;
    
    std::cout << "\033[u"; //restore cursor position 
   
    std::cout << std::flush; //make sure it refreshes

    //print(GameData::points);

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


    //gameplay
    while (true)
    {
        std::string userInput;
        std::cin >> userInput;

        //std::cout << userInput << std::endl;

        if (userInput == "exit") {
            break;
        }
        
    }

    //wrap up
    bgW.stopBackgroundThread();

    return 0;
}