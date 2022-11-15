// generic programming:
//   transform algorithm (map in other languages)
//     inline version with side-effects vs pure version
//   filter algorithm
//   count_if algorithm

//   accumulate algorithm (reducer in other languages)

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T, typename FUNC>
void transform_inline(T& container, FUNC func)
{
    for(auto& item : container)
        func(item);
}

//template<typename T, typename FUNC>
//T transform(T& container, FUNC func)
auto transform(const auto& container, auto func)
{
    auto new_container = container;
    for(auto& item : new_container)
        func(item);
    return new_container;
}


template<typename T>
auto filter(const T& container, auto func) {
    auto new_container = T{};
    for(auto item : container) {
        if(func(item))
            new_container.push_back(item);
    }
    return new_container;
}

template<typename Container>
auto accumulate(const Container& container, auto init, auto func)
{
    auto sum = init;
    for(const auto& item : container)
        sum = func(sum, item);

    return sum;
}


void print(const auto& container)
{
    for(const auto& item : container)
        cout << item << ", ";
    cout << endl;
}


int main(int argc, char* argv[])
{
    auto v = list<int>{1, 2, 3, 4, 5};

    auto sum = accumulate(v, 1, [](auto sum, auto newitem) { return sum * newitem; });
    cout << "Sum = " << sum << endl;

//    auto sum = 0;
//    for(const auto& item : v)
//        sum += item;


//        auto sz = v.size();
//        for(int i=0; i<sz; i++)
//            v[i] += 10;

//        for(auto it=v.begin(); it != v.end(); it++)
//            (*it) += 10;

//        for(auto& item : v)
//            item += 10;

//        transform_inline(v, [](auto& item) { item += 10; });
        auto v_transformed = transform(v, [](auto& item) { item += 10; });
        print(v_transformed);

        auto v_filtered = filter(v_transformed, [](const auto& item) {
            return item > 12;
        });

        print(v_filtered);

        //        auto sz = v.size();
//        for(int i=0; i<sz; i++)
//            cout << v[i] << ' ';
//        cout << endl;


    return 0;
}
