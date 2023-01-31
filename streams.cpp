#define print(x) std::cout << x << "\n"

#include <iostream>

/*
cin is an instance of type istream
cout is of instance type ostream

a stream goes into a buffer and then gets inputted to your program (/)
eg keyboard generates input stream, console is buffer, press enter to enter it.
Not Sure about This

files on your hard disk are common sources / destinations that are accessed with streams

*/



#include <fstream> //Dont forget this for file streams
#include <sstream> //DONT FORGET THIS for string streams
int main(int argc, char const *argv[])
{
    //See files.cpp andor files.cpp in test folder for file streams

    //string streams:
    
    double floatVar;
    int strVar;


    //INPUT STRING STREAMS (READ FROM STRING)
    std::istringstream iSStream; //can also init w/string directly
    iSStream.str("3.9 4 55"); 
    //now its the same as a input file stream but reads from string instead (doesnt seem to want to read words as strings though even when inputting to strings (??))
    //usefull for converting strings to numbers (iSStream >> intVar)
    

    while(iSStream >> floatVar) //??: Doesn't seem to work with strings as the input writing to stringVar, it fails if its not an int in that case (?)
    {
        print(floatVar);
    }

    

    print("---------");

    //OUTPUT STRING STREAMS (WRITE TO STRING)
    std::ostringstream oSStream;
    oSStream << "Hello";
    oSStream << "There";
    print(oSStream.str()); //str returns the string;


}
