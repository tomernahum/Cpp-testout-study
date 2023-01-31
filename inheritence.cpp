#define print(x) std::cout << x << "\n"

#include <iostream>



class Entity
{
public:
    float xpos, ypos;
};

class Player : public Entity
{
public:
    std::string name;
};

class Evildoer
{
};
//multiple inheritence, conflicts in base classes cause errors unless you rewrite the method and call Base1::method()
class EvilPlayer : public Player, public Evildoer {}; 




int main(int argc, char const *argv[])
{
    Player player()
}
