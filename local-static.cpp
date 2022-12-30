//#define print(x) std::cout << x << "\n"

#include <iostream>

inline void print(std::string x){
    std::cout << x << "\n";
}


void incrementAndPrint(){
    static int s_value = 0; //initializer is only executed once
    s_value++;
    print(s_value);
}

void incrementAndPrint2(){
    static int s_value = 0; //initializer is only executed once
    s_value++;
    print(s_value);
}


/*
static keyword for global and local variables do different things
static global variable makes the variable not exportable / scoped to the file
static local variable makes it persistent / remembers its value if called again (eg this file)

theres also static variables inside classes which is a third thing I think.

*/


int main(int argc, char const *argv[])
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    print("");

    incrementAndPrint2();
    incrementAndPrint2();
    incrementAndPrint2();

    
    int x;
    std::cin >> x;


    static int y = x*2;




    return 0;
}
