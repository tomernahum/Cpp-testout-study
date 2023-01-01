#define print(x) std::cout << x << "\n"

#include <iostream>

class ExampleClass{
public:
    void printOut(){
        std::cout << posX << ", " << posY << "\n";
        std::cout << velocityX << ", " << velocityY << "\n\n";
    }

    //Constructors
    ExampleClass(){
        posX = 0;
        posY = 0;
    }

    ExampleClass(int posX, int posY){
        this->posX = posX;
        this->posY = posY;
    }


    //using member initializer list
    //need to initialize members in order that they are defined in in the class
    ExampleClass(int posX, int posY, int velocityX)
        : posX(posX), posY(posY), velocityX(velocityX), velocityY(99)
    {
        print("initialized with ykw");
    }
    

private:
    int posX;
    int posY;
    int velocityX;
    int velocityY;
};

int main(int argc, char const *argv[])
{
    ExampleClass AA;
    AA.printOut();
    
    ExampleClass BB(5,10);
    BB.printOut();

    ExampleClass CC(5,10,1);
    CC.printOut();

    return 0;
}
