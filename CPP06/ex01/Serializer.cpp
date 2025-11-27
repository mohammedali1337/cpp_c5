#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& ob)
{
    (void) ob;
}

Serializer& Serializer::operator=(const Serializer& ob)
{
    (void) ob;
    return *this;
}

Serializer::~Serializer(){}

