#define print(x) std::cout << x << "\n"

#include <iostream>



#include <cstring>
int main(int argc, char const *argv[])
{
    char source[] = "Copy This";
    char dest[10]; //needs to be at least one longer to make room for null terminator
    
    
    //C-String functions
    std::strcpy(dest, source); //strcpy_s checks overflows
    std::strncpy(dest, source, 2);
    std::strcat(source, dest); //be careful of b overflows

    
    print(source);
    print(dest);
    

    

    return 0;
}
