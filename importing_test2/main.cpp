#define print(x) std::cout << x << "\n"

#include <iostream>

extern int globalAttempt;
void printHello();


int main(int argc, char const *argv[])
{
    print(globalAttempt);
    printHello();

    return 0;
}



