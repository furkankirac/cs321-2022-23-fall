// function pointers
// for_each

// Fraction class: Want to represent rational numbers with a numerator and denominator

// OOP: (encapsulates all necessary tools in a box that communicates
//  with outside via c-tors, assignment operators, and casting
// ctor/dtor
// copy-ctor, copy-assignment
// casting
// inheritance (will discuss later)

// function overloading, overload set
// operators and operator overloading

// literals, types of constants (remember units in your Physics class: 9.8 m/s^2)
// user-defined literals (a special way to create your own literals)

// Celsius/Fahrenheit example
// converting constructors

// pass by value, pass by reference, pass by constant reference
// implicit/explicit constructors

// operator== and operator+ overloads for Celsius/Fahrenheit
// static attributes and staticness. static variable initialization

#include <iostream>
#include <vector>

using namespace std;

int dosmt1(int a, int b) { return a; }
int dosmt2(int a, int b) { return a+b; }
int dosmt3(int a, int b) { return a-b; }

//typedef int (*twointer)(int, int);
using twointer = int (*)(int, int);

using oneinter = int (*)(int);

int add_one(int i) { return i+1; }
int multiply_by10(int i) { return i*10; }


template<typename T>
void for_each(std::vector<T>& container, oneinter funcptr)
{
    auto sz = container.size();
    for(int i=0; i<sz; i++)
        container[i] = funcptr(container[i]);
}


int main(int argc, char* argv[])
{
    std::vector<int> v(10);
    for(int i=0; i<10; i++)
        v[i] = i;

    for_each(v, &multiply_by10);
    for(int i=0; i<10; i++)
        std::cout << v[i] << std::endl;

    twointer funcptr = &dosmt2;

    int retval = 0;
    retval = funcptr(1, 2);
//    if(choice == 0)
//        retval = dosmt1(1, 2);
//    else if(choice == 1)
//        retval = dosmt2(1, 2);
//    else if(choice == 2)
//        retval = dosmt3(1, 2);

    std::cout << retval << std::endl;

    return 0;
}
