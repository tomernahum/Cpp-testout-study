#include <iostream>
#include <thread>

#define print(x) std::cout << x << std::endl


// !!! You need to do -pthread when compiling dont ask me why i dont even need to be learning threads in the first place i am on time crunch //also try -lpthread idk

bool is_finished = false;
void DoWorkk()
{
    while (!is_finished){
        std::cout << "Hello\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main()
{
    std::thread workerr(DoWorkk); //aka    thread workerrr = thread(DoWorkk);
    //^^ this immediatley starts the thread running the function

    std::string x;
    std::cin >> x; //seems to wait for you to enter something besides nothing
    is_finished = true;
    
    workerr.join(); // aka wait for workerr to complete before continuing main thread
    
    std::cout << "Bye";

    return 0;
}