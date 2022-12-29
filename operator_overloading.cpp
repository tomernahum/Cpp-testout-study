#define print(x) std::cout << x << "\n"

#include <iostream>


class Example
{
public:
    Example(int primary, int secondary)
    {
        //m_primary = primary;
        //m_secondary = secondary;

        this->primary = primary;
        this->secondary = secondary;
    }

    // this > other
    bool isGreaterThan(Example other)
    {
        if (this->primary == other.primary)
        {
            return this->secondary > other.secondary;
        }
        else 
        {
            return this->primary > other.primary;
        }
    }

    //operator overloading
    bool operator>(Example other)
    {
        return isGreaterThan(other);
    }


private:
    int primary;
    int secondary;
};




int main(int argc, char const *argv[])
{
    /*
    A 2 thing operator eg X + Y
    is equivilent to X.operator+(Y) 
    (left operates on the right)
    */

    Example one(5, 0);
    Example two(5, 9);
    //(two is greater than one)

    print(one.isGreaterThan(two));
    print((one > two));
    print(one.operator>(two));

    print("");
    print(two.isGreaterThan(one));
    print((two > one));


    
    return 0;
}


