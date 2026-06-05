#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _size = n;
    _array = new T[_size]();
}

template <typename T>
Array<T>::Array(const Array& other)
{
    this->_size = other._size;
    this->_array = new T[this->_size]();
    for (unsigned int i = 0; i < _size; i++)
        this->_array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _array;
        this->_size = other._size;
        this->_array = new T[this->_size]();
        for (unsigned int i = 0; i < _size; i++)
            this->_array[i] = other._array[i];
    }
    return (*this);
}
