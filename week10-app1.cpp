#include <iostream>
#include <list>
#include <vector>

// higher-order-functions, lifting/currying, composing

using namespace std;

template<typename T>
concept IsContainer = requires(T t) {
    t.begin();
    t.end();
    t.size();
    t.begin()++;
};

//template<typename T>
//concept IsPushableContainer = requires(T t) {
//    t.begin();
//    t.end();
//    t.size();
//    t.begin()++;
//    t.push_back;
//};

auto compose(auto f, auto g)
{
    return [f, g](const auto& item) { return g(f(item)); };
}

auto operator|(auto f, auto g) { return compose(f, g); }

template<IsContainer T>
auto operator|(T input, auto f)
{
    return f(input);
}

auto print_(const IsContainer auto& container)
{
    for(const auto& item : container)
        cout << item << endl;
    cout << endl;
    return container;
}

auto print()
{
    return [](const IsContainer auto& container) {
        return print_(container);
    };
}


auto reverse_(const IsContainer auto& container)
{
    auto new_container = container;
    auto sz = new_container.size();
    auto it1 = new_container.begin();
    auto it2 = new_container.end();
    for(int i=0; i<sz/2; i++) {
//        auto t = *it1++;
//        *it1 = *--it2;
//        *it2 = t;
        swap(*it1++, *--it2);
    }
    return new_container;
}

auto reverse()
{
    return [](const IsContainer auto& container) {
        return reverse_(container);
    };
}

template<typename ... Preds>
auto all_of_(auto item, Preds ... preds)
{
    return (preds(item) && ...);
}

auto all_of(auto ... preds)
{
    return [=](auto item) {
        return all_of_(item, preds...);
    };
}


auto higher_than_(auto item, auto limit) { return item > limit; }
auto less_than_(auto item, auto limit) { return item < limit; }

auto higher_than(auto limit) {
    return [=](auto item) { return higher_than_(item, limit); };
}
auto less_than(auto limit) {
    return [=](auto item) { return less_than_(item, limit); };
}


int func()
{
    return 10, 20, 30;
}

template<typename CONTAINER>
auto filter_(const CONTAINER& container, auto lambda)
{
    auto new_container = CONTAINER{};
    for(const auto& item : container) {
        if(lambda(item))
            new_container.push_back(item);
    }
    return new_container;
}

auto filter(auto lambda)
{
    return [=](const auto& container) {
        return filter_(container, lambda);
    };
}


int main(int, char* [])
{
    cout << all_of(higher_than(0), less_than(60))(500) << endl;

    10; // rvalue
    (cout << "Hi"), (cout << " there"), 30;
    cout << func() << endl << endl;


//    using CONTAINER = std::array<int, 6>;
    using CONTAINER = std::vector<float>;

    auto PRINT = print();

//    print_(CONTAINER{1.1, 50.3, -3, 5, 10, 100}); // rvalue

    CONTAINER{1.1, 50.3, -3, 5, 10, 100}
        | PRINT
        | reverse() | PRINT
        | filter(all_of(higher_than(0), less_than(60))) | PRINT;
//        | take<2>() | PRINT
//        | transform(add(2)) | PRINT
//        | accumulator(1, multiplier) | PRINT;

    return 0;
}
