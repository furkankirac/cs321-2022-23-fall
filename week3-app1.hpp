#pragma once

template<typename T>
struct Vector
{
    int n_dims;
    T* content; // lots of Ts (actually n_dims amount of Ts)

    Vector(int n_dims, T* content)
    {
        this->n_dims = n_dims;
        this->content = new T[n_dims];
        for(int i=0; i<n_dims; i++)
            this->content[i] = content[i];
    }

    ~Vector()
    {
        delete[] content;
    }

    bool operator+(Vector<T>& v2)
    {
        auto& v1 = *this;

        if(v1.n_dims != v2.n_dims)
            return false;

        for(int i=0; i<v1.n_dims; i++)
            v1.content[i] += v2.content[i];

        return true;
    }
};
