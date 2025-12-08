#pragma once

#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _V;
    public: 
        Span();
        Span(unsigned int num);
        Span(const Span& ob);
        ~Span();
        Span& operator=(const Span& ob);

        void addNumber(int nb);

        int shortestSpan();
        int longestSpan();
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};