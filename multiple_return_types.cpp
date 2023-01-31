//ex from stackoverflow, weird huh. Id guess its better to define it outside the function? how does auto know??
auto divide(int dividend, int divisor) {
    struct result {int quotient; int remainder;};
    return result {dividend / divisor, dividend % divisor};
}

//my testing (incorrect code)
auto dividee(int dividend, int divisor) {
    struct result {int quotient; int remainder;};
    result actualresult = result {dividend / divisor, dividend % divisor};
    if (actualresult.remainder != 0)
    {
        return actualresult;
    }
    else
    {
        struct result2 {int quotientt;};
        return result2 {dividend/divisor}; //deduced return type result2 conflicts with previously deduced return type result 1
    }
}
\

/*
If you want to return multiple values, you can do like above
or create a struct above

or use std::tuple 
    type define with std::tuple<int, double, etc>
    create with std::make_tuple(val, val, etc)
    unpack into vars with std::tie(varname, varname) = the tuple   (need to declare vars first)
    or in c++17 use auto[varname, varname, etc] = the tuple then you don't have to declare them

or pass in the extra variables by reference
might be more methods

*/