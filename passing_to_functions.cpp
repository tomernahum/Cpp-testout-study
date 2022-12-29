
#include <iostream>
#define print(x) std::cout << x << "\n"

class TestObj{
    public:
        int val = 1;
};


void AprintTestObjAndAdd1(TestObj t){
    t.val = t.val + 1;
    std::cout << t.val << "\n";
    /*
    passing directly // passing by value
    copies the object so changes to it dont
    apply to the object outside of the function
    */
}

void BprintTestObjAndAdd1(TestObj* t){
    //(*t).val = (*t).val + 1; 
    //std::cout << (*t).val << "\n";
    //  V^alternate ways to write
    t->val = t->val + 1;
    std::cout << t->val << "\n";
    /*
    if we want to modify the object passed in 
    we can pass in a pointer to the function
    and read from the pointer with (*pointer)
    */
}

void CprintTestObjAndAdd1(TestObj& t){
    t.val = t.val + 1;
    std::cout << t.val << "\n";
    /*
    function B & C are functionally identical 
    (compile to same assembly code)
    we pass a reference instead of a pointer
    a reference 
    */
}

//illustration of pass by reference
void ex(TestObj* t) {
    //TestObj t = *t; //this is what function C does automatically pretend it worked (overwritten old t with new t)
    //t.val = t.val + 1;
    //std::cout << t.val << "\n";
}

int main(int argc, char const *argv[])
{
    TestObj testObj; //val inits to 1

    AprintTestObjAndAdd1(testObj);
    print(testObj.val);
    print("");

    testObj = TestObj();
    BprintTestObjAndAdd1(&testObj); //& gets the pointer to testObj
    print(testObj.val);
    print("");

    testObj = TestObj();
    CprintTestObjAndAdd1(testObj);
    print(testObj.val);
    print("");


    //References:
    int a = 5;
    int* pointerToA = &a; //type is pointer to a (which stores 5)
    int& referenceToA = a;
    /*
    ^ referenceToA is basically an alias of a.
    anytime we use referenceToA the compiler switches it out to a.
    
    if we make a function take in an (int& p) it will automatically
    pass p in by reference, meaning it will pass in the pointer
    and then will make p be a reference to whats at the pointer 
    (see above)
    */

   TestObj& x = testObj; // reference to testObj called x
   CprintTestObjAndAdd1(x);


    

    return 0;
}
