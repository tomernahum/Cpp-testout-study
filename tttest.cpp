#define print(x) std::cout << x << "\n"

#include <iostream>

static int s_x = 5;
static int s_X()
{
    return 6;
}

int main(int argc, char const *argv[])
{
    
    print(x);
    print(X);
    print(X());
    return 0;
}
