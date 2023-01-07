#define print(x) std::cout << x << "\n"

#include <iostream>

namespace GameData
{
    int points = 0;
    int points_per_second = 1;
}


#include <chrono>
#include <thread>
void sleep(float seconds=0.5){
    std::cout << std::flush;

    std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000*seconds)));

}


int main(int argc, char const *argv[])
{
    std::cout << "Points: -, Pps: -\nHello There!";
    sleep();
    //
    while (true) {

    std::cout << "\033[s"; //save cursor position
    sleep();

    std::cout << "\033[1A\r"; //go up a line & go to start of line
    sleep();

    std::cout << "Points: " << GameData::points << ", Pps: " << GameData::points_per_second;
    sleep();
    
    std::cout << "\033[u"; //restore cursor position 
    sleep();
    
    GameData::points+= 19;
    //sleep();
    }//
    
    std::cout << "\n";
    return 0;
}
