// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword.
// meta-programming trick in templates

// Multiply, Divide, IsSame
// parameter packs, pack expansions

// constexpr, if constexpr, concepts
// Pair
// print_container

#include <iostream>

using namespace std;

int multiply_10_2 = 20;
int multiply_10_3 = 30;
int multiply_20_3 = 60;

struct Multiply_20_2 { static const int value = 20 * 2; };
struct Multiply_11_22 { static const int value = 11 * 22; };

//template<int i, int j> struct Multiply { static const int value = i * j; };

template<int first, int ... rest>
struct Multiply {
    static const int value = first * Multiply<rest...>::value;
};

template<int first, int second>
struct Multiply<first, second> {
    static const int value = first * second;
};

//auto i3 = Multiply<20, 2, 5, 3>::value;
//Multiply<20, Multiply<2, 5, 3>::value>::value;
//Multiply<20, Multiply<2, Multiply<5, 3>>::value>::value

int main(int argc, char* argv[])
{
    int i1 = 20 * 2 * 5 * 3;
    cout << "i1 " << i1 << endl;

    int i2 = Multiply_20_2::value;
    cout << "i2 " << i2 << endl;


    auto i3 = Multiply<20, 2, 5, 3>::value;
    cout << "i3 " << i3 << endl;

    auto i4 = Multiply<11, 22>::value;
    cout << "i4 " << i4 << endl;

    return 0;
}
