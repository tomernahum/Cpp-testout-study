#include <iostream>

using namespace std;

//making a class is like making a type (ie int, string)
class Playerr
{
public:
    string name; //badish practice to make variables public (should use getters/setters)
    void move(int newX, int newY){
        x = newX;
        y = newY;
    }
    
    void printWhere(){
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
