#include <iostream>

#define LOG(x) std::cout << x << std::endl
/*
    an array is really a pointer to the beginning of the array (then the elements are stored next to each other in memory)
    int example[5];


*/

int main()
{
    int example[5] = {5,6,7};
    
    //example is a pointer
    LOG(example);
    int* exampleCopy = example;



    std::string example2[5] = {"hello", "there"};
    std::string* example2Copy = example2;
    LOG(example2);



    LOG("");

    int example3[5] = {5,6,7}; //remember example3 is really a pointer to the start of the array (length 5)
    
    example3[2] = 10;
    //^V Equivilent  (aside from the numbers)
    *(example+2) = 11;
    
    LOG(example[2]);
    
    /*
    example+2 autoconverted the number of bytes to add to the pointer
    since the pointer is of type int
    (ints are 4 bytes so it added 2*4=8 not 2)
    */
    LOG(example);
    LOG(example+2);

    /**/
    LOG("----\n");

    float testArray[10];

    float * test1 = testArray; // pointer to float  ((start of float array))
    float (*test2)[10] = &testArray; // pointer to float array of length 10

    // pretty sure people use the first one in functions etc
    // but it would technically be more typesafe I think to use the second one
    






    return 0;
}
