#include <iostream>

/* 
    Namespaces are used to define custom scope 
    so your identifiers (var/func/class names) dont overlap

    std is standard namespace

    use namespace by writing:
        1) namespace_name::identifier   
        2) "using namespace namespace_name"
           then can use identifier from namespace without writing out its name
*/

namespace hello {
    int age = 10;
    char c = 'a';
}

namespace hello2 {
    std::string name = "Bobby";
    void print_name_and_age_and_grow_up() {
        std::cout << name << hello::age << std::endl;
        hello::age++;
    }

}


int main()
{
    std::cout << hello::age << std::endl;

    using namespace hello2;
    print_name_and_age_and_grow_up();
    print_name_and_age_and_grow_up();

    return 0;
}

/*
    - Namespaces must be above where they are used

    - you can also use nested namespaces
    - you can also use anonymous namespaces, 
    - (you can also use multiple of the same namespace and it will count toward the same namespace)
*/