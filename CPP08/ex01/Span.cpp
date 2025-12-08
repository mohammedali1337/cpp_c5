#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int num): _N(num){}

Span::Span(const Span& ob): _N(ob._N)
{

}

Span::~Span(){}

Span& Span::operator=(const Span& ob)
{
    return *this;
}

void Span::addNumber(int nb)
{
    if (_V.size() >= _N)
        throw std::runtime_error("size of vector is grad than n");
    else 
        _V.push_back(nb);
}

int Span::shorttestSpan()
{
    if (_V.size() < 2)
        throw std::runtime_error("not enough numbers to find a span ")

    std::vector<int> tmp = std::sort(_V.begin(), _V.end());
    std::sort(_V.begin(), _V.end());

    for (std::vector<int>::iterator it = _V.begin(); it != _V.end(); ++it)
    {
        for(std::vector<int>::iterator it2 )
    }
    return 0;
}

int Span::longestSpan()
{
    return (*(std::max_element(_V.begin(), _V.end())) - *(std::min_element(_V.begin(), _V.end())));
}