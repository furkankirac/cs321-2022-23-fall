#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<
    template<typename> typename DestTemplate,
    template<typename> typename SourceTemplate,
    typename ItemType
    >
auto convertContainerTo(const SourceTemplate<ItemType>& input)
{
    auto l = DestTemplate<ItemType>{};
    for(const auto& item : input)
        l.push_back(item);

    return l;
}

void print(const auto& container) {
    auto i = 0;
    for(const auto& item : container) {
        cout << "Index " << i++ << ": ";
        cout << item << endl;
    }
}


auto accumulate(const auto& container, auto init, auto func)
{
    auto a = init;
    for(const auto& item : container)
        a = func(a, item);

    return a;
}

template<typename Container>
auto filter2(const Container& container, auto func)
{
    using ItemType = decltype(*container.begin());
    auto C = Container{};

    auto it = container.begin();
    while(it != container.end()) {
        auto item1 = *it++;
        auto item2 = it == container.end() ? ItemType{} : *it;
        if(func(item1, item2))
            C.push_back(item1);
    }
    return C;
}

int main(int argc, char* argv[])
{
    auto v1 = vector<int>{10, 5, 15, 25, 5, 10};
    auto v2 = vector<int>{10, -5, 15, -25, 5, -10};
    auto businessLogic = [](auto i1, auto i2) { return i1 > i2; };
    auto v1_filtered = filter2(v1, businessLogic);
    auto v2_filtered = filter2(v2, businessLogic);
    print(v1_filtered);
    print(v2_filtered);
    return 0;
}
