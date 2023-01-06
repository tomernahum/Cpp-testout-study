#define print(x) std::cout << x << "\n"

#include <iostream>
#include <fstream>


int main(int argc, char const *argv[])
{

    std::ifstream file;
    file.open("file2.txt");

    if(file.fail()){
        print("FAILED");
        return -1;
    }

    double sum = 0;

    double doubleVar;
    while (file >> doubleVar)
    {
        print(doubleVar);
        sum+= doubleVar;
    }

    print("");
    std::cout << sum << std::endl;






    
    return 0;
}
