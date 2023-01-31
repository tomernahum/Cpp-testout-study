#define print(x) std::cout << x << "\n"

#include <iostream>


/*
Vectors are like lists in python (though type is typically specified)
they wrap arrays and let them have non-fixed size, as well as providing some methods.
they are allocated on the heap automatically by the std::vector class, no need to worry yourself!

*/

//Vectors
#include <vector>
int main(int argc, char const *argv[])
{
    //std::vector<type> myVector;
    std::vector<double> myVector;
    std::vector<double> myVector2(5); //experiencing bugs personally
    std::vector<double> myVector3 = {0,1,2,3,4,5};

    myVector.push_back(420.69);
    std::cout << myVector[0] << std::endl; //or myVector.at()
    myVector.pop_back(); //deletes last, no return

    myVector.size();
    for(double var : myVector2) {}
    //vectors are passed by value(copied)

    //to insert/delete vars, slides tell to loop through it and use what we know above. Can also do:
    myVector.insert(myVector.begin() + 3, 420.69);
    myVector.erase(myVector.begin() + 3);
    
    
    
    print("What");
    
}
