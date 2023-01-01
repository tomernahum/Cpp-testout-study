#define print(x) std::cout << x << "\n"

#include <iostream>


class HelloClass
{
public:
    HelloClass(){
        x = 0;
        y = 0;
    }
    HelloClass(int x, int y)
        : x(x), y(y)
    {
    }

    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    HelloClass helloObj(0,0);
    HelloClass* helloObjPointer = &helloObj;




    HelloClass* A = new HelloClass(22,22);
    print(A->x);

    print("");

    HelloClass ex = *A; //creates a copy of it
    ex.x = 3;
    print(ex.x);
    print((*A).x);

    print("");

    HelloClass* AB = new HelloClass(22,22);

    HelloClass& ex2 = *AB; //doesnt copy it its a reference//alias
    ex2.x = 5;
    print(ex2.x);
    print((*AB).x);


    delete A; 
    delete AB;
    //new returns a pointer (to the obj created on the heap). 
    //delete takes in a pointer and deletes that object
    

    print("");
    int* n = nullptr;
    int* k;
    print(n);
    print(k);
    print(sizeof(n));
    print(sizeof(k));
    print(sizeof(*n));

    std::string* p = new std::string("test");
    print(*p);
    
    return 0;
}
