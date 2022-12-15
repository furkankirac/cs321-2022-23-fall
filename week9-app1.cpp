// some fancy value/type traits
//  is_integral<int>::value
//  conditional_type<boolean_value, T1, T2>::type
//  is_same<int, int>::value

// some fancy concepts (compile-time validation of types):
//  integral, same_as, ...

// accumulate algorithm, adder function
// lifted (higher order) accumulate algorithm, adder_lifed function

// comma operator
// fold expressions

#include <iostream>

using namespace std;

template<typename T> struct IsIntegral      { static const bool value = false; };
template<>           struct IsIntegral<int> { static const bool value = true; };
template<>           struct IsIntegral<short> { static const bool value = true; };
template<>           struct IsIntegral<char> { static const bool value = true; };
template<>           struct IsIntegral<long> { static const bool value = true; };

template<typename T>
const bool IsIntegral_v = IsIntegral<T>::value;

template<bool b, typename T1, typename T2> struct ConditionalType                   { using type = T1; };
template<typename U1, typename U2>         struct ConditionalType<false, U1, U2>    { using type = U2; };

template<bool b, typename T1, typename T2>
using ConditionalType_t = typename ConditionalType<b, T1, T2>::type;

//struct IsIntegral_int {
//    static const bool value = true;
//};

template<typename ...>
struct TypeDisplayer;

template<typename T1, typename T2>
void func()
{
    const bool same = std::is_same_v<T1, T2>;
    if constexpr(same)
        cout << "Types are the same" << endl;
    else
        cout << "Types are different" << endl;
}

void func_int_float()
{
    const bool same = false;
//    if constexpr(same)
//        cout << "Types are the same" << endl;
//    else
        cout << "Types are different" << endl;
}

void func_int_int()
{
        const bool same = true;
//        if constexpr(same)
            cout << "Types are the same" << endl;
//        else
//            cout << "Types are different" << endl;
}


void print(int)
{
    cout << "int" << endl;
}

void print(float)
{
    cout << "float" << endl;
}

template<typename T>
void generic_print(T)
{
    if constexpr(is_same_v<T, int>)
        cout << "int" << endl;
    else if constexpr(is_same_v<T, float>)
        cout << "float" << endl;
}


int main(int, char* [])
{
//    auto a = std::is_integral<float>::value;
    auto a = IsIntegral<float>::value;
    cout << a << endl;
    auto a2 = IsIntegral_v<float>;
    cout << a2 << endl;

//    using K = ConditionalType<false, int, float>::type;
    using K = ConditionalType_t<false, int, float>;
//    auto b = TypeDisplayer< K >{};

    func<int, float>();
    func_int_float();

    func<int, int>();
    func_int_int();

    print(5);
    print(5.3f);

    generic_print(5);
    generic_print(5.3f);

    return 0;
}
