// std::tuple, is_tuple, is_tuple_v
// std::get<T>, std::get<index>
// tuple_element_t<index, T>
// tuple_element<index, T>::type
// tuple_size_v<T>

#include <iostream>
#include <tuple>
#include <string>

using namespace std;

struct Foo
{
    int a;
    float whatever;
    string hello;
    int b;
};


template<typename T>      struct is_tuple                 { static const bool value = false; };
template<typename ... Ts> struct is_tuple<tuple<Ts...>>   { static const bool value = true; };

template<typename T>
const bool is_tuple_v = is_tuple<T>::value;

//auto is_tuple_v_int = false;
//auto is_tuple_v_float = false;
//auto is_tuple_v_Foo = false;
//auto is_tuple_v_Bar = true;

template<typename ...>
struct TypeDisplayer;


int main(int argc, char* argv[])
{
    auto f = Foo{10, 3.14f, "world"};
    f.a; // r-values, righthand values, temporary values, they don't have a memory address
    f.whatever;
    f.hello;

    cout << f.hello << endl;

    using Bar = tuple<int, float, string, int>;

//    using ItemType = std::tuple_element_t<3, Bar>;
//    auto a = TypeDisplayer<ItemType>{};

    cout << "Is Bar Tuple? " << is_tuple<Bar>::value << endl;
    cout << "Is Bar Tuple? " << is_tuple_v<Bar> << endl;
    cout << "Is Foo Tuple? " << is_tuple<Foo>::value << endl;

    auto b = Bar{10, 3.14f, "world", 20};

    cout << get<0>(b) << endl;
    cout << get<1>(b) << endl;
    cout << get<2>(b) << endl;
    cout << get<3>(b) << endl;
//    cout << get<int>(b) << endl;

    return 0;
}
