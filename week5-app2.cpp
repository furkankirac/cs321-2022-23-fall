// pointers, dereferencing, pointer arithmetic
// OOP: unified/universal construction:
//   stricter construction with {} instead of (),
// iterators and range-for-loop
// introducing std::vector<T>
// encapsulating functions:
//   functions themselves (with func pointers),
//   function objects
//   lambda functions

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <list>

using namespace std;

template<typename Container, typename Func>
void transform(Container& container, Func func)
{
    for(auto& item : container)
        func(item);
}


int main(int argc, char* argv[])
{
    int x[3] = {10, 20, 30}; // C array
    auto y = array<int, 3>{10, 20, 30};
    auto z = vector<int>{10, 20, 30};
    auto l = list<int>{10, 20, 30};

    char* s = "hi there"; // null-terminated c string
    auto S = string("hi there");
//    auto v = vector<char>(9);

//    for(auto it = y.begin(); it != y.end(); it++)
//        cout << *it << endl;

    auto func = [](auto& item) { item++; };
    transform(y, func);

    for(auto value : y)
        cout << value << endl;


//    for(auto it = S.begin(); it != S.end(); it++)
//        cout << *it << endl;

    transform(S, func);

    for(auto value : S)
        cout << value << endl;


    return 0;
}
