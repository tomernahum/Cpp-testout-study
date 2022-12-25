#include <iostream>

#define LOG(x) std::cout << x << std::endl


/* 
pointers are all the same type (hexadecimal ints i think)
if we declare a type for a pointer its just what we expect it to be pointing to


- to point to a variable do &var
- to read whats at a pointer do *pointer

- pointers type is int*, Person* etc, can also use void* if we're not going to write to it

*/
int main()
{
    
    int varr = 8;
    int* pointerr = &varr;

    LOG(varr);
    LOG(pointerr);
    LOG(*pointerr);
    *pointerr = 5;
    LOG(varr);
    LOG(pointerr);
    LOG(&*pointerr);


    LOG("");
    int varr2 = 1;
    int* pointerr2 = &varr2;

    LOG(varr2);
    LOG(pointerr2);
    LOG(sizeof(int));




    
    


    return 0;
}
