// stack memory vs heap memory
// value semantics vs reference semantics

// global scope, local scope
// free-functions

// class/struct? object? ------> type? instance?
// typedef (C)

// c-tor of a primitive type
// c-tor of a complex type (struct)

// write a c-tor of a struct instance as a free function (imperative programming paradigm)
// write a c-tor of a struct instance as a member function (OOP paradigm)

// allocate memory at run-time (dynamic memory allocation)
// free memory at run-time

// write a dtor as a free function (imperative programming paradigm)
// write a dtor as a member function (OOP paradigm)

// member variables ~= attributes ~= properties (OOP)

#include <iostream>

int i;

struct Vector2d {
    int a;
    int b;
    char* c;

    Vector2d()
    {
        c = new char[1000];
        a = 0;
        b = 0;
    }

    ~Vector2d()
    {
    }


    Vector2d(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
};

void constructVector2d(Vector2d& v, int a, int b)
{
    v.a = a;
    v.b = b;
}


Vector2d addVectors(Vector2d& K, Vector2d& L)
{
    Vector2d M;
    M.a = K.a + L.a;
    M.b = K.b + L.b;
    return M;
}

void printVector(const Vector2d& v)
{
    std::cout << "Content of vector is [" << v.a << ", " << v.b << "]" << std::endl;
}

int main(int argc, char* argv[])
{
    Vector2d A(1, 5);
//    constructVector2d(A, 1, 5);
    printVector(A);

    Vector2d B(-1, 8);
//    constructVector2d(B, -1, 8);
    printVector(B);

    Vector2d C = addVectors(A, B);
    printVector(C);

    return 0; // 0 means everything is okay
}




