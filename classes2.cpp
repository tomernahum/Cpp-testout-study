#define print(x) std::cout << x << "\n"

#include <iostream>


class Time {
public:
    void const printOut(){
        print(hours);
        print(minutes);
        print(seconds);
        print("");
    }

    int hours;
    int minutes;
    int seconds;
};



int main(int argc, char const *argv[])
{
    //Ways to instatiate classes:
    //1
    Time a;
    a.hours = 10;
    a.minutes = 35;
    a.printOut();

    //2
    Time b = {11, 45 }; 
    // {11, 45} can be converted to a valid Time 
    // type object wherever its used even if you dont assign it to a variable
    // it is type <brace-enclosed initializer list> it seems
    b.printOut();

    //3
    //using a constructor

    
    
    return 0;
}
