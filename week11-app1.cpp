// nested for-loops in functional programming paradigm
// std::pair
// attaching two or more objects together for making them act as a single sequence
// min_of(...)

// std::tuple, is_tuple, is_tuple_v
// std::get<T>, std::get<index>
// tuple_element_t<index, T>
// tuple_size_v<T>

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <tuple>

using namespace std;

template<typename T>
concept IsContainer = requires(T t) {
    t.begin();
    t.end();
    t.size();
    t.begin()++;
};

auto cartesian_product(const auto& c1, const auto& c2, auto func) {
    for(const auto& i1 : c1)
        for(const auto& i2 : c2)
            func(i1, i2);
}

auto cartesian_product(const auto& c1, const auto& c2, const auto& c3, auto func) {
    for(const auto& i1 : c1)
        for(const auto& i2 : c2)
            for(const auto& i3 : c3)
                func(i1, i2, i3);
}

auto cartesian_product(const auto& c1, const auto& c2, const auto& c3, const auto& c4, auto func) {
    for(const auto& i1 : c1)
        for(const auto& i2 : c2)
            for(const auto& i3 : c3)
                for(const auto& i4 : c4)
                    func(i1, i2, i3, i4);
}


template<IsContainer T1, IsContainer T2>
auto zip(const T1& c1, const T2& c2) // T1 = vector<int>, T2 = vector<float>
{
    using ITEM1 = decltype(*c1.begin());
    using ITEM2 = decltype(*c2.begin());
    using ITEM_PAIR = pair<ITEM1, ITEM2>;

    auto new_container = vector<ITEM_PAIR>{};

    auto sz1 = c1.size(); // 5
    auto sz2 = c2.size(); // 4
    auto sz = sz1 < sz2 ? sz1 : sz2; // 4

    auto it1 = c1.begin();
    auto it2 = c2.begin();
    for(auto i=0; i<sz; ++i)
        new_container.push_back(ITEM_PAIR{*it1++, *it2++});

    return new_container;
}

template<typename T, typename ... Rest>
auto min_of(const T& first, const T& second, Rest ... rest)
{
    if constexpr(sizeof...(Rest) == 0)
        return first < second ? first : second;
    else
        return min_of(first < second ? first : second, rest...);
}


template<IsContainer T1, IsContainer T2, IsContainer T3>
auto zip(const T1& c1, const T2& c2, const T3& c3)
{
    using ITEM1 = decltype(*c1.begin());
    using ITEM2 = decltype(*c2.begin());
    using ITEM3 = decltype(*c3.begin());
    using ITEM_TUPLE = tuple<ITEM1, ITEM2, ITEM3>;

    auto new_container = vector<ITEM_TUPLE>{};

    auto sz = min_of(c1.size(), c2.size(), c3.size());
    auto it1 = c1.begin();
    auto it2 = c2.begin();
    auto it3 = c3.begin();
    for(auto i=0; i<sz; ++i)
        new_container.push_back(ITEM_TUPLE{*it1++, *it2++, *it3++});

    return new_container;
}

//operator<<(ostream& out,  auto item)
//{
//    ...
//}

void print_(const auto& c) {
    for(const auto& [i, j, k] : c) { // structured binding in C++ == destructuring/deconstructing
//        operator<<(operator<<(cout, item), endl);
        cout << i << ", " << j << ", " << k << endl;
    }
}


int main(int argc, char* argv[])
{
    auto v1 = vector<int>   {1,     2,      3,     4,    5}; // 5 element
    auto v2 = list<float>   {1.1,   2.2,    -3.3,  -4.4};     // 4 element
    auto v3 = vector<string>{"aaa", "bbb",  "ccc"};     // 3 element

//    auto v_zipped = zip<vector<int>, vector<float>>(v1, v2);
    auto v_zipped = zip(v1, v2, v3); // vector<pair<int, float>>
    print_(v_zipped);
//    auto v_zipped = vector<pair<int, float>>{
//        {1, 1.1, "aaa"},
//        {2, 2.2, "bbb"},
//        {3, -3.3, "ccc"},
//        {4, -4.4, "ddd"},
//        {5, 5.5, "eee"},
//    }

//    cartesian_product(v1, v2, [](const auto& i1, const auto& i2) {
//        cout << "[" << i1 << ", " << i2 << "]" << endl;
//    });

//    cartesian_product(v1, v2, v1, [](const auto& i1, const auto& i2, const auto& i3) {
//        cout << "[" << i1 << ", " << i2 << ", " << i3 << "]" << endl;
//    });

    // x axis, y axis, cartesian coordinates


    return 0;
}
