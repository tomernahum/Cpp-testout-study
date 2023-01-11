
#include <functional>
#include <iostream>

void foo(std::function<void()> func)
{
    func();
}

void printHW()
{
    printf("Hello World\n");
}


#include <chrono>
#include <thread>
void sleep(float seconds=1){
    std::cout << std::flush;

    std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000*seconds)));

}

int main(int argc, char const *argv[])
{
    //foo(&printHW);

    printf("line 1\n");
    sleep();

    printf("Hello There");
    sleep();
    printf("\033[1A");
    sleep();
    
    printf("Bye");
    sleep();

    printf("\n");

}
