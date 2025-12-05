#pragma once
#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& ob);
        Array& operator=(const Array& ob);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const ;
        unsigned int size()const;

        class outOfBoundsException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

#include "Array.tpp"