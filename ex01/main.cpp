#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat b1("ali", 50);
        Form f1("topsecret", 30, 10);
        Form f1("topsecret", 120, 100);

        std::cout << b1 << std::endl;
        std::cout << 
    }
    catch (std::exception &e)
    {
        std::cout << "exception : " << e.what() << std::endl;
    }

    return 0;
}
