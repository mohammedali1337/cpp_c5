#include "Span.hpp"
#include <iostream>
#include <vector>
#include <iterator>
int main()
{
    try
    {
        std::cout << "===== Basic Test =====" << std::endl;
        
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Range Test =====" << std::endl;
    try
    {
        Span sp2(10);

        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(100);
        vec.push_back(50);
        vec.push_back(75);

        sp2.addRange(vec.begin(), vec.end());

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Exception Test (full) =====" << std::endl;
    try
    {
        Span sp3(2);
        sp3.addNumber(10);
        sp3.addNumber(20);

        // This should throw
        sp3.addNumber(30);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== Exception Test (not enough numbers) =====" << std::endl;
    try
    {
        Span sp4(5);
        sp4.addNumber(42);

        // Should throw (only 1 number)
        std::cout << sp4.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
