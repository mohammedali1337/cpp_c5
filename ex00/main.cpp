#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat ob1("ali", 50);
        std::cout << ob1 << std::endl;
        Bureaucrat ob2("simohammed", 0);
        std::cout << ob2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}
