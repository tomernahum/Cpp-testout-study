#define print(x) std::cout << x << "\n"

#include <iostream>
#include <fstream>


int main(int argc, char const *argv[])
{
    std::string myVar;


    std::ifstream myFile("file.txt");
    
    while (std::getline(myFile, myVar))
    {
        std::cout << "\nLine: " << myVar;
    }



    std::ifstream myFile2("file.txt");

    while ( ) {

    }




    
    return 0;
}
