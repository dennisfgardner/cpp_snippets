#include "main.hpp"

auto int_adder(int num1, int num2) -> int
{
    return (num1 + num2);
}

#ifndef UNIT_TESTING
#include <iostream>
auto main() -> int
{
    std::cout << "Hello World!\n";
    const int num1{2};
    const int num2{3};
    const int sum = int_adder(num1, num2);
    std::cout << num1 << " + " << num2 << " = " << sum << "\n";
    return 0;
}
#endif