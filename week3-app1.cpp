// C has malloc and free for dynamic memory handling.
// C++ has new/delete.
// static variables, static member variables
// Generic Programming = Templates in C++

// const keyword

// OOP:
// ctor/dtor
// copy-ctor, copy-assignment
// inheritance (later)

// function overloading
// operators and operator overloading
// function parameters: pass by value, pass by reference

// next week:
// function pointers
// for_each

// auto, AAA rule (almost always auto)

#include <iostream>

#include "week3-app1.hpp"

template<typename T>
void print(Vector<T>& v)
{
    for(int i=0; i<v.n_dims; i++)
        std::cout << v.content[i] << std::endl;
}

void print(int i)
{
    std::cout << "integer value is " << i << std::endl;
}


int func()
{
    return 30;
}

int main(int argc, char* argv[])
{
    print(1234);

    10 + 20;
//    operator+(10, 20);
//    30;
//    func();


    double v1_values[2] = {10.1, 20.2};
    auto v1 = Vector<double>(2, v1_values);
    print(v1);

    double v2_values[3] = {100.1, 200.2, 300.3};
    auto v2 = Vector<double>(2, v2_values);
    print(v2);

//    bool is_okay = addVectors(v1, v2);
//    bool is_okay = v1.addVectors(v2);
    auto is_okay = v1 + v2;
//    bool is_okay = v1.operator+(v2);


    if(is_okay) {
        std::cout << "Addition is done, here are new values of v1:" << std::endl;
        print(v1);
    } else {
        std::cout << "Addition cannot be done, dimensions don't match." << std::endl;
    }


    {
        auto* p = (int*)malloc(100 * sizeof(int));
        for(int i=0; i<100; i++)
            p[i] = i;

        free(p);
    }

    {
        auto* k = new int;
        delete k;

        auto* p = new int[100];
        for(int i=0; i<100; i++)
            p[i] = i;
        delete[] p;
    }




    return 0;
}
