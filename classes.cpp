
#include <iostream>


class Xx
{
public:

    Xx() {
        //i = 0; 
        
    }
    Xx(int whatsI) {
        i = whatsI;
    }


    int getI(){
        return i;
    }

private:
    int i;
    void X() {

    }
};


int main(int argc, char const *argv[])
{
    Xx foo(5); // Xx foo = Xx(5)
    int hello = foo.getI();
    std::cout << hello << "\n";

    Xx bar;
    std::cout << bar.getI() << "\n";
    
    return 0;
}
