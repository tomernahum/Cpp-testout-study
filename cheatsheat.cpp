#define print(x) std::cout << x << "\n"

#include <iostream>

class Voxel {
public:
    Voxel();
    Voxel(double x, double y, double z);
    double getX() const; //const means it doesn't modify anything in the object
    void setX(double x);
    void printInfo() const; 
    
    //Friend Functions/Classes
    friend void moveVoxelUp(Voxel vox);
    friend class HypotheticalClass;
    
protected:
    //means only this and classes that inherit from it can access it
    double x;
    double y;
    double z;
 
private:
    //only this class (and friend funcs/classes) can access it, not offspring or public


};
 
Voxel::Voxel()
    : x(0), y(0), z(0)
{
    print("called Voxel Short constuctor");
}
Voxel::Voxel(double x, double y, double z)
    : x(x), y(y), z(z)
{
    print("called Voxel long constructor");
}
double Voxel::getX() const {
    return this->x;
}
void Voxel::setX(double x) {
    this->x = x;
}
void Voxel::printInfo() const {
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << x << std::endl;
    std::cout << "Z: " << x << std::endl;
}

//Friend Functions/Classes can access private/protected members
void moveVoxelUp(Voxel vox) {
    print("Hi!");
    vox.y += 1;
}




//Inheritence
class Block: public Voxel
{
    //inherits public and protected properties from Voxel, Block is superset of Voxel
public:

    //need to include constructors if not using just default one I think
    Block () {}

    //constructors can be done like this
    Block(double x, double y, double z) : Voxel(x, y,z)
    {
        print("Called Sandblock Long Constructor");
    }

    // //or like this, dont do conflics though! (im not fully learned on this btw)
    // Block(double x, double y, double z) //implicitly calls Voxel() short constructor
    // {
    //     this->x = x; this->y = y; this->z = z;
    //     this->name = "unnamed Block";
    //     print("Called Sandblock Long Constructor");
    // }

    Block(double x, double y, double z, std::string name)
        : Voxel(x, y, z), name(name)
    {
    }

    

    //can override functions, need to mark parent funcs with virtual to overwrite w/ polymorphism
    // Can use override keyword on virtual funcs at end of overritten function declaration if you want
    // if not functions are the same as parent class
    void printInfo() const{
        Voxel::printInfo();    //call parent func
        std::cout << "name: " << name << std::endl;
    }

    //can add new functions and new data
    std::string getName() const{
        return this->name;
    }

protected:
    std::string name;
};




int main()
{
    //You can always use a child where a base class is expected
    //but dont count on funcs working right unless you do virtual funcs
    Voxel block = Block();

    Block block2(0,0,0, "Sand");
    moveVoxelUp(block2);
    block2.printInfo();

    Voxel myVoxel2;
    Voxel myVoxel2 = {1,0,1};
}
