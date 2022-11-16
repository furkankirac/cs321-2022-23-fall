// Multiply, Divide, IsSame
// parameter packs, pack expansions

// constexpr, if constexpr, concepts
// Pair
// print_container

#include <iostream>

using namespace std;

// template specialization
template<int i, int j> struct Divide { static const int value = i / j; };
template<int k>        struct Divide<k, 0> { static const int value = 0; };

int main(int argc, char* argv[])
{
    int i1 = 20 / 3;
    cout << "i1 " << i1 << endl;

    int i2 = Divide<20, 3>::value;
    cout << "i2 " << i2 << endl;

    int i3 = Divide<20, 0>::value;
    cout << "i3 " << i3 << endl;

    return 0;
}
