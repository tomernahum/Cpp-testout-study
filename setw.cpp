#define print(x) std::cout << x << "\n"

#include <iostream>


#include <iomanip>
int main(int argc, char const *argv[])
{
    std::cout << std::setw(15) << "ex" << std::endl;
    std::cout << std::setfill('*') << std::setw(15) << "ex";
    
    return 0;
}
