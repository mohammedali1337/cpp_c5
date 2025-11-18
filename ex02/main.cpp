#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib> // For std::srand
#include <ctime>   // For std::time

int main()
{
    try 
    {
        Bureaucrat ali("ali", 50);
        Bureaucrat boss("boss", 1);

        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("bender");
        PresidentialPardonForm f3("marvin");

        std::cout << "\n --- before signing ---\n";

        std::cout << ali << std::endl;
        std::cout << f1 << std::endl;

        std::cout << "\n--- try sign form with low grade ---\n";

        ali.signForm(f1);

        std::cout << "\n--- execute with low grade ---\n";

        ali.executeForm(f1);

        std::cout << "\n--- sign and execute with hight grade ---\n";
        boss.signForm(f1);
        boss.executeForm(f2);

        std::cout << "\n--- robotomy test ---\n";
        boss.signForm(f2);
        boss.executeForm(f2);

        std::cout << "\n--- presidential pardon test ---\n";
        boss.signForm(f3);
        boss.executeForm(f3);
    }catch (std::exception &e){
        std::cout << "exception: " << e.what() << std::endl;
    }
    return 0;
}