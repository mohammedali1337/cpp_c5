#include "Span.hpp"
#include <iostream>
#include <vector>
#include <iterator>
int main(void)
{
    try
    {
        Span ob(3);

        ob.addNumber(100);
        ob.addNumber(1);
        ob.addNumber(98);

        std::cout << "longestSpan(): " << ob.longestSpan() << std::endl;
        ob.shorttestSpan();
        
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}