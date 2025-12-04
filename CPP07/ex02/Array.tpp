#pragma once 
#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(NULL), _size(0){}

template <typename T>
Array<T>::Array(unsigned int n): arr(new T[n]), _size(n){}

template <typename T>
Array<T>::Array(const Array& ob): arr(NULL), _size(0)
{
    if (ob._size > 0)
    {
        this->arr = new T[ob._size]();
        this->_size = ob._size;
        for (unsigned int i = 0; i < ob._size ; i++)
        {
            this->arr[i] = ob.arr[i];
        }
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &ob)
{
    if (this != &ob)
    {
        if (this->arr)
        delete[] this->arr;
        this->_size = ob._size;
        if (this->_size > 0)
        {
            this->arr = new T[ob._size]();
            for (unsigned int i = 0; i < ob._size ; i++)
            {
                this->arr[i] = ob.arr[i];
            }
        }
        else
        this->arr = NULL;
    }
    return *this;
}

template <typename T>
T& Array::operator[](unsigned int index)
{
    if (_size <= index)
    {
        throw outOfBoundsException();
    }
    return this.arr[index];
}

const T& Array::operator[](unsigned int index) const
{
    if (_size <= index)
    {
        throw outOfBoundsException();
    }
    return this.arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this._size;
}

template <typename T>
const char* Array<T>::outOfBoundsException::what() const throw()
{
    return "Error: index out of bounds";
}