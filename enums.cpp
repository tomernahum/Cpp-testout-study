#define print(x) std::cout << x << "\n"

#include <iostream>

/* Enums stand in for ints */

enum ExampleClass
{
    A, B, C
};

enum Example2
{
    APPLE=5, BURP=10, CRAYON
};


/*
Enums are 32 bit integers by default
but can assign them to be any integer type thing
unsigned int, char, bool, ...
this can save on memory
like so:
*/
enum Example3 : char
{
    X,Y,Z
};


/*
You can also make class enums
which have to be accessed with Example4::X for example
this allows you to use the symbol multiple times

*/
enum class Example4 
{ 
    X,Y,Z //if this wasnt a class XYZ would conflict with Example3 type enum/ints
}
;

int main(int argc, char const *argv[])
{
    ExampleClass vall = A;  //can only assign A B or C

    char x = 101;
    print(x);

    if (vall == 0){
        print("is correct");
    }

    Example4 valuee = Example4::X;
    if (valuee == Example4::X) {
        print("111");
    }
    //if(valuee == 0) //does not compile
    if(Example4::Y > Example4::X){
        print("333");
    }


    return 0;
}
