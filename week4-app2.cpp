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
using namespace std;

struct Fraction
{
    int n;
    int d;

    Fraction() : n(0), d(1) { }
    explicit Fraction(int n, int d) : n(n), d(d) { }
    explicit Fraction(int n) : n(n), d(1) { }
//    Fraction(int n, int d=1) : n(n), d(d) { }
    Fraction(const Fraction& other) : n(other.n), d(other.d) {
        std::cout << "I am being copy constructed!" << std::endl;
    }

    void operator=(Fraction& right)
    {
        std::cout << "I am being manipulated!" << std::endl;
        n = right.n;
        d = right.d;
    }

    operator double() {
        return value();
    }

    double value()
    {
        return (double)n / (double)d;
    }
};


void print(const Fraction& f)
{
    std::cout << f.n << '/' << f.d << std::endl;
}


auto operator"" _frac(long double value)
{
    return Fraction((int)value);
}

int main(int argc, char* argv[])
{
//    Fraction f(10, 3);
    auto f1 = Fraction(10, 3);
//    Fraction f1_ = 3.33;
//    print(f1_);
    auto f2 = Fraction(10);
    auto f3 = Fraction();

    std::cout << f1.value() << std::endl;
    std::cout << (double)f1 << std::endl;

    double d;
    d = f1;

    print(f1);
    print(f2);
    print(f3);

    f1 = f3; // assignment
//    auto f4 = Fraction();
//    f4 = f3;
    auto f4 = f3; // copy construction
    f4 = f1; // assignment
    auto f5 = Fraction(f3); // copy construction  // Fraction(f3.n, f3.d);

//    operator=(f1, f3);
    print(f1);
    print(f4);

//    auto x = 10lu;
    auto f6 = 10.0_frac;

    return 0;
}
