#include <iostream>

// Celsius/Fahrenheit example
// converting constructors

// pass by value, pass by reference, pass by constant reference

// operator== and operator+ overloads for Celsius/Fahrenheit
// static attributes and staticness. static variable initialization

using namespace std;

struct Fahrenheit; // forward decleration

struct Celcius
{
    double value;

    Celcius(double value) : value(value) { }
    Celcius(const Fahrenheit& f);
    void operator=(const Fahrenheit& f);
};

struct Fahrenheit
{
    double value;
    Fahrenheit(double value) : value(value) { }
};

Celcius::Celcius(const Fahrenheit& f) : value((f.value-32)/180*100) { }

void Celcius::operator=(const Fahrenheit& f)
{
    value = (f.value - 32) / 180 * 100;

    cout << "did nothing" << endl;
}


auto operator"" _c(long double value) { return Celcius(value); }
auto operator"" _f(long double value) { return Fahrenheit(value); }



void foo()
{
    static bool foo_initialized = false;

    if(!foo_initialized)
    {
        foo_initialized = true;
        // do slow calculations
    }

    // use the calculations
}

int main(int argc, char* argv[])
{
    auto c1 = Celcius(10.1);
    auto c2 = 10.1_c;

    auto f1 = Fahrenheit(30.3);
    auto f2 = 30.3_f;

    cout << "c1 = " << c1.value << endl;
    c1 = f1;
    cout << "c1 = " << c1.value << endl;

//    Celcius c3 = f1;
    auto c3 = Celcius(f1);


    return 0;
}
