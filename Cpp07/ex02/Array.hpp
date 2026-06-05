#pragma once

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](unsigned int i);
        T const& operator[](unsigned int i) const;
        unsigned int size() const;
};

#include "Array.tpp"
