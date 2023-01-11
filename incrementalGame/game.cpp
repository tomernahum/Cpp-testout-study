
//!Not currently in use

#include "bgworker.hpp"
#include "display.hpp"
#include <iostream>
#include <functional>

//yk theres only gonna be one game, maybe it should just be a namespace
class Game
{
    struct GameData
    {
        double points = 0;
        double points_per_second = 1;
    };

public:
    //feels like I am doing something wrong judging by how I'm using these constructors 
    //also copied code for the constructors init lists idk if theres a way around that
    
    //default constructor
    Game()
        :gameData(), 
        pointsIncrementerBgw(  BackgroundWorker( [this]{this->pointsIncrementerBgFunc();}, 1000 )  ),
        display(  Displayer( [this]{this->displayBgFunc();}, 500 )  )
    {

    }

    //detailed constructor
    //want to implement save/load system. maybe save/loader can be a friend of game class and access GameData directly, since friend was on the curriculum I think
    Game(GameData gameData)
        :gameData(gameData), 
        pointsIncrementerBgw(  BackgroundWorker( [this]{this->pointsIncrementerBgFunc();}, 1000 )  ),
        display(  Displayer( [this]{this->displayBgFunc();}, 500 )  )
    {}



    void setup()
    {
        this->pointsIncrementerBgw.startBackgroundThread();
        this->display.startDisplay();
        this->play();
    }

    void wrapup() //should be private?
    {
        this->display.stopDisplay();
        this->pointsIncrementerBgw.stopBackgroundThread();
    }


    void play() //should be private?
    {
        while (true)
        {
            std::string userInput = display.askForInput();

            if (userInput == "exit" || userInput == "quit") {
                break;
            }

            else if (userInput == "shop") {
                //will abstract into shop funtion probably
                display.displayText("Welcome to the shop, which do you buy? \n> ");
                userInput = display.askForInput();
                
                display.displayText("Yeah I cant hear you yet, have an extra pps \n> ");
                gameData.points_per_second++;
                
                userInput = display.askForInput(); //needs this or it resets display instantly after printing so you dont see it
            }


            display.resetDisplay(); //todo: should this be abstracted into display more etc
            
        }
        this->wrapup();
    }

private:
    GameData gameData;
    
    
    BackgroundWorker pointsIncrementerBgw;
    Displayer display;



    void displayBgFunc()
    {
        std::cout << "Points: " << gameData.points;
        std::cout << "\nPps: " << gameData.points_per_second;
        std::cout << "\n> "; //TODO: maybe move outside of the updating part
    }

    void pointsIncrementerBgFunc()
    {
        gameData.points += gameData.points_per_second;
    }


    //Actual Methods:



};



int main(int argc, char const *argv[])
{
    Game game;
    game.setup();
    
    

    //game.wrapup();
    
    return 0;
}
