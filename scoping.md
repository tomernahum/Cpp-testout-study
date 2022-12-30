a block is anything in between brace {}  //probably


local variables by default have **automatic duration**, meaning they are created at the line they are defined at, and destroyed when the block is exited {}


global variables have **static duration**.
local variables with the static keyword also have **static duration** (but they are not accessible outside of their scope/block)
Static duration means that the variale is created at the start of the program, and destroyed at the end of it. AKA you can reuse it:
```
void incrementAndPrint(){
    static int s_value = 0; //initializer is only executed once
    s_value++; //s_value will be the same as last time
    print(s_value); 
}
```

- duration/lifetime is seperate from scope


- static local variables can be a safer alternative to global varibles because they persist througout the entire program like globals but they are only visible in their block scope which makes them safer.

- https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/

**Naming Conventions:**
g_ for global variables
s_ for static local variables

