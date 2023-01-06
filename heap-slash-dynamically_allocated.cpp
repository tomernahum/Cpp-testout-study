#define print(x) std::cout << x << "\n"

#include <iostream>


int main(int argc, char const *argv[])
{

    /*
    to allocate something dynamically, aka on the heap
    use new and delete keywords

    new returns a pointer to the thing
    */

    int x; //stack allocated
    int* y = new int; //heap allocated
    delete y;

    std::string ex1("Hello");
    std::string ex1Alt = std::string("Hello");
    std::string * ex2HeapPointer = new std::string("Hello");

    delete ex2HeapPointer;

    return 0;



    /*
    Stack allocated vars have automatic duration
    heap allocated vars have static duration maybe idk
    
    heap vars are accessable until we 'delete' them
    */
}
