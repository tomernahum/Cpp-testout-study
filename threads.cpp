#include <iostream>
#include <thread>

#define print(x) std::cout << x << std::endl


// !!! You need to do -pthread when compiling dont ask me why i dont even need to be learning threads in the first place i am on time crunch
// also try -lpthread idk

void DoWorkk()
{
    std::cout << "Hello";
}

int main()
{
    std::thread workerr(DoWorkk); //aka    thread workerrr = thread(DoWorkk);
    //^^ this immediatley starts the thread running the function

    //std::string x;
    //std::cin >> x;
    
    
    workerr.join(); // aka wait for workerr to complete before continuing main thread
    
    
    
    return 0;
}