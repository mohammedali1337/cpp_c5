#pragma once

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

        int shorttestSpan();
        int longestSpan();

};