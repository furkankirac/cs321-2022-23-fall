// accumulate algorithm, adder function
// lifted (higher order) accumulate algorithm, adder_lifed function

// comma operator
// fold expressions

#include <vector>
#include <list>
#include <iostream>

using namespace std;

template<typename T>
auto filter_(const T& container, auto func)
{
    auto new_container = T{};
    for(const auto& item : container)
        if(func(item))
            new_container.push_back(item);
    return new_container;
}

auto filter(auto func)
{
    return [func](const auto& container) {
        return filter_(container, func);
    };
}

template<typename T, typename Func, typename K>
auto accumulate_(const T& v, Func func, K initial_value)
{
    auto acc = initial_value;
    for(const auto& item : v)
        acc = func(acc, item); // sum + item;
    return acc;
}

auto accumulate(auto func, auto initial_value)
{
    return [func, initial_value](const auto& container) {
        return accumulate_(container, func, initial_value);
    };
}


auto adder_ = [](auto a, auto b) { return a + b; };
auto multiplier_ = [](auto a, auto b) { return a * b; };

auto adder = []() {
    return adder_;
};

auto multiplier = []() {
    return multiplier_;
};

auto compose(auto f, auto g)
{
    return [f, g](const auto& item) {
        return g(f(item));
    };
}

template<typename T>
concept IsContainer = requires(T t) {
    t.begin();
    t.end();
    t.size();
    t.begin()++;
};

auto operator|(auto f, auto g)
{
    return compose(f, g);
}

template<IsContainer T>
//requires(IsContainer<T> && IsPushable<T>)
auto operator|(T input, auto f)
{
    return f(input);
}


template<typename ...>
struct TypeDisplayer;


int main(int, char* [])
{
    auto v = vector<int>{10, 20, 30, 15, 25};

//    auto sum = 0;
//    for(const auto& item : v)
//        sum += item;

    auto sum_float = accumulate_(v, adder(), 0.0f);
    cout << sum_float << endl;

    auto product_int = accumulate_(v, multiplier(), 1);
    cout << product_int << endl;

    auto v_filtered = filter_(v, [](const auto& item) { return item > 20; });
    auto sum_filtered_float = accumulate_(v_filtered, adder(), 0.0f);
    cout << sum_filtered_float << endl;

    auto filter_rule = [](const auto& item) { return item > 20; };
    auto result = v | filter(filter_rule)
                       | filter(filter_rule)
                       | filter(filter_rule)
                       | filter(filter_rule)
                       | filter(filter_rule)
                       | accumulate(adder(), 0.0f);

//    auto x = TypeDisplayer<decltype(result)>{};
    cout << result << endl;

    return 0;
}
