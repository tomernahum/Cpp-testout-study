#define print(x) std::cout << x << "\n"

#include <iostream>


class Test
{
public:
    Test() {
        x = 7;
        y = 2;
    }

    ~Test(){

    }

    void printX(){
        print(x);
    }

    int x;
    int y;
};



int main(int argc, char const *argv[])
{
    Test* t = new Test;

    t->printX();

    delete t;

    t->printX();
    
    return 0;
}
