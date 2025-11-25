#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat ob1("ali", 50);
        std::cout << ob1 << std::endl;

        Bureaucrat ob2("simohammed", 1);
        std::cout << ob2 << std::endl;
        
        ob2.decrementGrade();
        std::cout << ob2 << std::endl;
        
        ob2.incrementGrade();
        std::cout << ob2 << std::endl;
    
        ob2.incrementGrade();
        std::cout << ob2 << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        try
        {
            Bureaucrat ob4("ob4", 149);
            std::cout << ob4 << std::endl;

            ob4.decrementGrade();
            std::cout << ob4 << std::endl;

            ob4.decrementGrade();
            std::cout << ob4 << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        Bureaucrat ob3("ob3", 151);

        std::cout << ob3 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
