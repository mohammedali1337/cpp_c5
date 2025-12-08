#include "Span.hpp"

Span::Span(): _N(0){}

Span::Span(unsigned int num): _N(num){}

Span::Span(const Span& ob): _N(ob._N)
{
    this->_V = ob._V;
}

Span::~Span(){}

Span& Span::operator=(const Span& ob)
{
    if (this != &ob)
    {
        _N = ob._N;
        _V = ob._V;
    }
    return *this;
}

void Span::addNumber(int nb)
{
    if (_V.size() >= _N)
        throw std::runtime_error("Span is already full");
    else 
        _V.push_back(nb);
}

int Span::shortestSpan()
{
    if (_V.size() < 2)
        throw std::runtime_error("not enough numbers to find a span ");

    std::vector<int> tmp = _V;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = INT_MAX;

    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (_V.size() < 2)
        throw std::runtime_error("not enough numbers to find a span ");
    return (*(std::max_element(_V.begin(), _V.end())) - *(std::min_element(_V.begin(), _V.end())));
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while (begin != end)
    {
        if (_V.size() >= _N)
            throw std::runtime_error("Span is full, cannot add more numbers");
        _V.push_back(*begin);
        ++begin;
    }
}