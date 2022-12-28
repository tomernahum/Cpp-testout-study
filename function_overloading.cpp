#define print(x) std::cout << x << "\n"

#include <iostream>


/* 
function overloading is simple:
define a function twice, with different inputs, 
and the compiler will select the correct function
*/

std::string add(int a, int b){
    int x = a + b;
    return "Hello, you answer is " + std::to_string(x);

}
std::string add(int a, double b) {
    double x = a + b; //+ is already overloaded sortof by default
    return "HHeerree''ss yyoouurr aannsswweerr::  " + std::to_string(x); 
}

int main(int argc, char const *argv[])
{
    print(add(5, 5));
    print(add(5, 5.0));


    
    return 0;
}
