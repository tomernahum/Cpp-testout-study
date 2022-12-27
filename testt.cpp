#include <iostream>

//using namespace std;

#define print(x) std::cout << x << std::endl

#include <chrono>
#include <thread>
void sleep(float seconds){
    const int milliseconds = 1000*seconds;
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

class Test 
{
    public:
        bool running;
        int counter;

        Test(){
            running = true;
            counter = 0;
        }
        void run_loop(){
            //todo: learn threading
            while(running){
                sleep(1);
                counter++;
            }
        }

        void display_counter(){
            print(counter);
        }
};

class Test2 {
    public:
        bool running = true;
        int counter = 0;
        std::string testt = "d";

        void main(){
            while(running){
                sleep(1);
                counter++;
                print(counter);
                print(testt);

                std::cin >> testt;
            }
        }
};

int main()
{
    //i tested it and nested functions are not a thing, though you can use lambdas 
    
    Test2 test = Test2();
    test.main();

    return 0;
}
