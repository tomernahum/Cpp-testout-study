


/*
"this" is a pointer to the current object (when used in an object method)

*/

#include <iostream>

class Ex
{
public:
    int i = 5;
    void exampleMethod()
    {
        std::cout << this->i << std::endl;
    }
};

int main(int argc, const char** argv) {
    
    Ex e;
    e.exampleMethod();
    
    
    return 0;
}