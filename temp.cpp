#define print(x) std::cout << x << "\n"

#include <iostream>


int main(int argc, char const *argv[])
{
    
    //allocating off stack
    float test1[100];


    print("---------\n");


    //allocating off heap / dynamically allocatinig
    float* test2 = new float[100]; //new returns a pointer

    print(sizeof(test2));
    print(sizeof(test2[0]));
    

    
    
    delete test2;



    
    return 0;
}
