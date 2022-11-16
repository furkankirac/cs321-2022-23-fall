// pure functions != free functions
// pure functions are better. eliminate state if possible.
// if state is definitely required, better use OOP to encapsulate it from the outside world in a lambda function

// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword.
// meta-programming trick in templates

// Multiply, Divide, IsSame
// parameter packs, pack expansions

// constexpr, if constexpr, concepts
// Pair
// print_container


#include <iostream>
#include <string>

using namespace std;

void func()
{
    static int i = 0;

    cout << i << endl;
    i++;
}


struct Func
{
    int i = 0;

    void operator() ()
    {
        cout << i << endl;
        i++;
    }

//    void print() { }
};

int main(int argc, char* argv[])
{
    func();
    func();
    func();

    auto func2 = Func{};
    func2();
    func2();
    func2();

    auto func3 = [i=0]() mutable
    {
        cout << i << endl;
        i++;
    };
    func3();
    func3();
    func3();

    return 0;
}
