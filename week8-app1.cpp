#include <iostream>
#include <vector>
#include <list>
#include <string>

// in search of a simpler and more understandable generic way of writing code
//  the dance of OOP, FP and GP paradigms

// lifting a function (higher order functions):
//  a function returning a function object: delays function use
// lt, gt, get_name, ...

// composing functions

// extra generic transform algorithm

using namespace std;

//namespace Colors {
//    const int Red = 0;
//    const int Blue = 1;
//    const int Yellow = 2;
//}

enum class Color {
    Red,
    Blue,
    Yellow,
};

struct Painting {
    Color color;
    int year;
    string painter;
};

auto multiply_by(auto what) {
    return [what](auto k) { return k * what; };
}

bool greater_than_(int i, int j) { return i > j; }
bool greater_than_1900_(int i) { return i > 1900; }

auto greater_than(int i) {
    return [i](int j) {
        return j > i;
    };
}

auto get_painter_(const auto& p) {
    return p.painter;
}

auto get_painter() {
    return [](const auto& p) {
        return get_painter_(p);
    };
}

auto get_year_(const auto& p) {
    return p.year;
}

auto get_year() {
    return [](const auto& p) {
        return get_year_(p);
    };
}

//struct GreaterThan
//{
//    int i;
//    bool operator() (int j) { return i > j; }
//};

//auto GreaterThanLambda = [](int i, int j){ return i > j; };
//auto GreaterThanLambda = [i=1900](int j){ return i > j; };

//auto gt = GreaterThan{1900};
//gt(20);

template<typename T>
struct TypeDisplayer;

template<template<typename> typename ContainerTemplate, typename Item, typename Func>
auto transform(const ContainerTemplate<Item>& container, Func func)
{
    using T = decltype(func(*container.begin()));
    auto v = ContainerTemplate<T>{};

//    auto t = TypeDisplayer<T>{};

    for(const auto& item : container) {
        v.push_back(func(item));
    }

    return v;
}

auto compose(auto func1, auto func2)
{
    return [func1, func2](auto input) {
        return func2(func1(input));
    };
}

auto operator |(auto func1, auto func2) {
    return compose(func1, func2);
}


//auto operator<<(std::ostream& out, const Painting& p)
//{
//}

void print(const auto& container)
{
    for(const auto& item: container)
        cout << item << endl;
//        cout.operator<<(item);
//        operator<<(cout, item);
    cout << endl;
}

int main(int argc, char* argv[])
{
    auto gt1900 = greater_than(1900);
    cout << gt1900(1800) << endl;

    auto v = vector<Painting>{
        {Color::Red, 1950, "Picasso"},
        {Color::Yellow, 1975, "Dali"},
        {Color::Blue, 1530, "Da Vinci"},
    };

    auto p = Painting{Color::Red, 1950, "Picasso"};
    p.year > 1900;
    p.painter;

//    auto v_painter = vector<string>{
//        "Picasso",
//        "Dali",
//        "Monet",
//    };

    auto v_painter = transform(v, get_painter());
    print(v_painter);

    auto v_ifyearafter1900 = transform(
        v,
        get_year() | greater_than(1900) | multiply_by(1000)
        );
    print(v_ifyearafter1900);



    // let this be the homework
    auto v_year_after1900 = vector<int>{
        1950,
        1975,
    };


    //    int i = Color::Red;
//    cout << Color::Red << endl;

    return 0;
}
