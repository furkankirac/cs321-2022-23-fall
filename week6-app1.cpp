// overview of encapsulating functions (OOP):
//   functions themselves (with func pointers)
//   function objects (overloading the function call operator  "operator()"
//   lambda functions

// GENERATORS (Coroutines): for functional programming
// mutable lambdas: fibonacci generator

// generic programming:
//   transform algorithm (map in other languages)
//     inline version with side-effects vs pure version
//   accumulate algorithm (reducer in other languages)
//   filter algorithm
//   count_if algorithm

#include <iostream>
#include <vector>   // an array dynamically allocated contiguously in heap memory
#include <list>     // this is a linked-list implementation
#include <string>

using namespace std;

// 1, 1, 2, 3, 5, 8, 13, ...

struct FibonacciGenerator
{
    int a;
    int b;

//    FibonacciGenerator() : a{0}, b{1} { }
    FibonacciGenerator(int& a, int& b) : a{a}, b{b} { }

    int operator() () {
        auto retval = a + b;
        this->a = this->b;
        b = retval;
        return retval;
    }
};


int main(int argc, char* argv[])
{
    int k = 0;
    int l = 1;

//    auto fg = FibonacciGenerator{k, l};

    auto fg_lambda = [&a=k, &b=l]() mutable {
        auto retval = a + b;
        a = b;
        b = retval;
        return retval;
    };


//    for(int i=0; i<10; i++)
//        cout << fg() << ", ";
//    cout << endl;
    for(int i=0; i<10; i++)
        cout << fg_lambda() << ", ";
    cout << endl;

    cout << k << endl;
    cout << l << endl;
    cout << endl;

    return 0;
}
