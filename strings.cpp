#include <iostream>

#define LOG(x) std::cout << x << std::endl
/*
Strings (literal strings not std strings)

- strings are/must be const char arrays 
(can not be edited)
*/
int main() {
    "Hello"; 
    //What a string literal really means is a const char array (hover over it in editor)
    // length is 1 more than num characters because of null terminator thing at end ( written as \0)
    std::cout << "Hel\0lo" << std::endl; // \0 is terminator. dont do this probably
    
    
    const char literal_string[] = "Hello"; //const char array
    std::cout << literal_string << std::endl;

    const char* literal_string2 = "Byeee";    //equivilent, since arrays are pointers
    std::cout << literal_string2 << std::endl;
    //^^ implicit terminator char at the end. 
    //pointer points to the start and functions that read it go till they see the \0 character


    //normal array test
    LOG("");

    int test[] = {9,8,7};
    LOG(test); //pointer

    char testC[] = {'O','M','G','\0'};
    LOG(testC); //when its a char array it knows to read it like a string not a pointer (i guess)
    


    LOG("");
    /*
    - Not allowed to have non-const string char array pointer 
    (undefined behavior, inconsistent across compilers, some won't let you compile)
    
    - if you want a mutable char array you can use []

    char ttest[] = "Hello";
    ttest[4] = "!"; //in the compiler im using g++ it puts an error here
    */

    char mTest[] = {'O','M','G','\0'};
    LOG(mTest);
    mTest[2] = 'M';
    LOG(mTest);



    LOG("\n"<< "Hello"[4]); //reading works you just cant write
    


    return 0;
}