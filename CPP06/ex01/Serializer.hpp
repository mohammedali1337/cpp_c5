#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer & ob);
        ~Serializer();
        Serializer& operator=(const Serializer & ob);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif