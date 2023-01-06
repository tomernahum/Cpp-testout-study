/*
Pseudocode
    every second/less:
        update points based on points per second
        rerender display with updated points




    every game loop:
        display points (should be updating)
        display problem
        get input

        if input is answer to problem:
            increment points appropriately
            reset challenge
            restart gameloop
        if input is shop:
            shop mode:
                display options
                user input
                buy the thing
                    deduct coins and uptate active upgrades list
*/

#define print(x) std::cout << x << std::endl

#include <iostream>
#include <thread>

/* 
Could make the class take a function pointer on init and a time interval to run it, 
then do the while loop and delay and run the function
*/
class BackgroundWorker
{
public:
    //need to call stop background thread sometime in program or else runtime error
    void startBackgroundThread()
    {
        running = true;
        bgthread = std::thread(&BackgroundWorker::bgWorkerFunction, this); //dont 100% understand why it has to be done this way
    }
    void stopBackgroundThread()
    {
        running = false;
        bgthread.join();
    }

private:
    bool running;
    std::thread bgthread;
    void bgWorkerFunction(){

        while (running)
        {
            print("hello");

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    void bgWorkerTestFunction(){
        while (running)
        {
            print("hello");
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
};


// draft.  likely make this global/singleton so stuff can modify it, i heard global=bad though
class GameData
{
public:
    int points;
    float pointsPerSecond(){
        return 1;
    };
    std::string upgrades[10][2]; //todo figure out proper type etc


};


int main()
{
    int points = 0; //todo: make it unsigned long and then make it work infinitely if you feel like it

    BackgroundWorker backgroundWorker;
    backgroundWorker.startBackgroundThread();
    
    while (true) {
        std::string userInput;
        std::cin >> userInput;

        if (userInput == "exit"){
            break;
        }
    }
    
    
    
    
    backgroundWorker.stopBackgroundThread();

    return 0;
}
