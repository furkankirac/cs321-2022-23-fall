// IsSame

// constexpr, if constexpr, concepts
// Pair
// print_container

#include <iostream>
#include <tuple>
#include <map>

using namespace std;

template<typename T, typename U> struct IsSame       { static const bool value = false; };
template<typename K>             struct IsSame<K, K> { static const bool value = true; };


template<typename T> struct RemoveTypeModifiers          { using type = T; };
template<typename K> struct RemoveTypeModifiers<const K> { using type = K; };
template<typename K> struct RemoveTypeModifiers<K&> { using type = K; };
template<typename K> struct RemoveTypeModifiers<const K&> { using type = K; };

//struct RemoveTypeModifiers_constint
//{
//    using type = const int;
//};


template<typename ... Ts>
struct TypeDisplayer;


template<typename FIRST, typename SECOND>
struct Pair
{
    FIRST first;
    SECOND second;
};

//struct Pair_Int_Float
//{
//    int first = 10;
//    float second = 3.14f;
//};


int main(int argc, char* argv[])
{
    auto p = Pair<int, float>{10, 3.14f};

    auto is_same = IsSame<int, int>::value;
    cout << (is_same ? "true" : "false") << endl;


    using INTREF = int&;
    using CONSTINTREF = const int&;


    using T = RemoveTypeModifiers<int>::type;

    auto m = std::map<int, string>{
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
    };

    m[4] = "FOUR";
    cout << m[4] << endl;

    for(const auto& item : m) {
        cout << item.first << " = " << item.second << endl;
    }


//    auto a = TypeDisplayer<T, const int, float, double>{};

//    cout << IsSame<T, const int>::value << endl;

    return 0;
}
