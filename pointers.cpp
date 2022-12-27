#include <iostream>

#define LOG(x) std::cout << x << std::endl


/* 
pointers are all the same type (hexadecimal ints i think)
if we declare a type for a pointer its just what we expect it to be pointing to


- to point to a variable do &var
- to read whats at a pointer do *pointer

- pointers type is int*, Person* etc,   can also use void* if we're not going to write to it
    | [type pointed to]* varName = &varPointedTo
- * is not technically part of the type but im thinking of it that way rn
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

/*
Theres also references which I have not fully learned at time of writing 
but they compile to pointers essentially and are used commonly 

you can pass by reference to a function by doing (type& varName)
otherwise it copies the var (this way it passes the pointer and uses it automaticsally)
*/