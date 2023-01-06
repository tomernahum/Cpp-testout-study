#define print(x) std::cout << x << "\n"

#include <iostream>

#include "bgworker.hpp"


int points = 0;
int points_per_second = 1;
void pointsIncrementerBg()
{
    points += points_per_second;
    std::cout << "\rP: " << points << std::flush;
}

int main()
{
    BackgroundWorker bg(&pointsIncrementerBg, 1000);
    bg.startBackgroundThread();

    while (true)
    {
        std::string userInput;
        std::cin >> userInput;

        if (userInput == "exit") {
            break;
        }
    }

    bg.stopBackgroundThread();

    return 0;
}