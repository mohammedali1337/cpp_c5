#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int num): _N(num){}

Span::Span(const Span& ob): _N(ob._N)
{

}

Span::~Span(){}

Span& Span::operator=(const Span& ob)
{

}

void Span::addNumber(int nb)
{
    if (_V.size() => _N)
        throw std::runtime_error("size of vector is grad than n");
}