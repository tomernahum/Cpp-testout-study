#include <iostream>
using namespace std;

void Testtt(){
    cout << "Tessttt" << endl;
}

/*
    Another common practice is to include the head of test ("void Testtt()"")
    in a header file (test.h), 
    then #include that where you define it and everywhere you use it
    (look it up, need #pragma once etc, c++ seems really clearly and simply designed :D    zzor you know maybe its just new to me)


    include ""     //is relative path (can use ../)
    include <>     // is compiler hardcoded paths type thing
    
    // iostream is a header file but they decided not to include .h, c files do use .h usually
*/