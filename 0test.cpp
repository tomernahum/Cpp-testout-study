#define print(x) std::cout << x << "\n"

#include <iostream>

#include <sstream>
int main(int argc, char const *argv[])
{
    std::istringstream stream;
    stream.str("Hell o there");

    char var;
    while (stream.get(var))
    {
        print(var);
    }
    
    return 0;
}
