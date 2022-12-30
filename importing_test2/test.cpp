#define print(x) std::cout << x << "\n"

#include <iostream>

extern int globalAttempt;
void printHello();

int globalAttempt = 0;

void printHello(){
    print("hello");
}
