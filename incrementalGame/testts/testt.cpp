
#include <functional>

void foo(std::function<void()> func)
{
    func();
}

void printHW()
{
    printf("Hello World\n");
}


int main(int argc, char const *argv[])
{
    foo(&printHW);
}
