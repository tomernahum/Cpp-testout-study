#define print(x) std::cout << x << "\n"

#include <iostream>

//Interface:
class ExampleClass{
public:
    void printOut();

    ExampleClass();
    ExampleClass(int posX, int posY);

private: 
/*
private members need to be included in the header so 
the compiler knows how much space to allocate for each instance
may be some ways around this google it + google pimpl idiom but yeah
*/
    int posX;
    int posY;
    int velocityX;
    int velocityY;
};


//Implementation
void ExampleClass::printOut() {
    std::cout << posX << ", " << posY << "\n";
    std::cout << velocityX << ", " << velocityY << "\n\n";
}

ExampleClass::ExampleClass(){
    posX = 0;
    posY = 0;
}
ExampleClass::ExampleClass(int posX, int posY){
        this->posX = posX;
        this->posY = posY;
}

/*
Interface might be put in header file and implementation in its own file

*/

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
