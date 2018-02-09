/**
 creating Fibonacci series in compile time
 From https://stackoverflow.com/questions/908256/getting-template-metaprogramming-compile-time-constants-at-runtime
 **/
#include <iostream>
#include <vector>

using namespace std;

template <unsigned N>
struct Fibonacci
{
    enum
    {
        value = Fibonacci<N-1>::value + Fibonacci<N-2>::value
    };
};

template <>
struct Fibonacci<1>
{
    enum
    {
        value = 1
    };
};

template <>
struct Fibonacci<0>
{
    enum
    {
        value = 0
    };
};


int main(void)
{
    std::cout << "Fibonacci(10) = ";
    std::cout << Fibonacci<10>::value;
    std::cout << std::endl;
    
    return 0;
}

