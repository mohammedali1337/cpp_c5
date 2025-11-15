#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat b1("ali", 50);
        std::cout << "execute here " << std::endl;
        Form f1("topsecret", 30, 10);
        Form f2("topsecret", 120, 100);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        b1.signForm(f1);
        b1.signForm(f2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "exception : " << e.what() << std::endl;
    }

    return 0;
}
