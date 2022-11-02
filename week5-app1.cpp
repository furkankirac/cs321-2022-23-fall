// pointers, dereferencing, pointer arithmetic

// encapsulating functions:
//   functions themselves (with func pointers),
//   function objects
//   lambda functions

// iterators and range-for-loop
// introducing std::vector<T>
// "transform/map" algorithm with function pointers

// unified/universal construction:
//   stricter construction with {} instead of (),
//   designated initializers
//   initializer_list support for ctors

#include <iostream>

using namespace std;

struct Vector3d
{
    int x = -1;
    int y = -1;
    int z = -1;

    Vector3d() {

    }

    void operator() () {
        cout << "function call operator has been called" << endl;
        print();
    }

    void operator() (int n_times) {
        cout << "function call operator has been called" << endl;
        for(int i=0; i<n_times; i++)
            print();
    }


    void print() {
        cout << "x=" << x << " y=" << y << " z=" << z << endl;
    }
};


template<typename Container, typename BusinessLogic>
void transform(Container& v, BusinessLogic func)
{
    func(v);
}

struct IncrementByX
{
    int amount;
    IncrementByX(int amount) : amount(amount) { }

    template<typename T>
    void operator() (T& v) { v.x+=amount; v.y+=amount; v.z+=amount; }
};


struct MultiplyByX
{
    int amount;

    MultiplyByX(int amount) : amount(amount) { }

    template<typename T>
    void operator() (T& v) { v.x*=amount; v.y*=amount; v.z*=amount; }
};


int main(int argc, char* argv[])
{
    auto v = Vector3d();
    v.print();

    v();
    v(3);

    auto incrementBy1 = IncrementByX(1);

    auto incrementBy22 = [amount=22](auto& v) { v.x+=amount; v.y+=amount; v.z+=amount; };

    auto incrementBy111 = IncrementByX(111);
    auto multiplyBy2 = MultiplyByX(2);

    transform(v, multiplyBy2);
    v();
    transform(v, incrementBy22);
    v();

    return 0;
}
