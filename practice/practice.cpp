#define print(x) std::cout << x << "\n"

#include <iostream>




class Voxel
{
public:
    Voxel();
    Voxel(double x, double y, double z);
    double getX() const; //const means it doesn't modify anything in the object
    double setX(double x);
protected:
    //means classes that inherit from it can access it
    double x;
    double y;
    double z;
private:
    //only this class (and friend funcs/classes) can access it, not offspring or public
};

Voxel::Voxel()
    : x(0), y(0), z(0)
{}
Voxel::Voxel(double x, double y, double z)
    : x(x), y(y), z(z)
{}
double Voxel::getX() const{
    return this->x;
}
double Voxel::setX(double x)
{
    this->x = x;
}



int main(int argc, char const *argv[])
{
    
    
    return 0;
}

