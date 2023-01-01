#include <iostream>

using namespace std;

/*
Use const keyword to the left of method names
if they dont modify anything in the object
otherwise if theres a const obj instance, 
it wont be able to call that method unless its const
*/

//making a class is like making a type (ie int, string)
class Playerr
{
public:
    string name; //badish practice to make variables public (should use getters/setters)
    void move(int newX, int newY){
        x = newX;
        y = newY;
    }
    
    void const printWhere(){
        cout << name << "'s at " << x << ", " << y << endl;
    }

private:
    int x, y;  
};

int main()
{
    //instantiate Playerr class   object
    Playerr tomer;
    tomer.name = "Bob";

    tomer.printWhere();

    tomer.move(10, 10);
    tomer.printWhere();


    return 0;
}
