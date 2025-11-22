#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    try 
    {
        Bureaucrat ali("ali", 146);
        Bureaucrat boss("boss", 1);

        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("bender");
        PresidentialPardonForm f3("marvin");

        std::cout << ali << std::endl;
        std::cout << f1 << std::endl;

        ali.signForm(f1);

        ali.executeForm(f1);

        boss.executeForm(f1);

        boss.signForm(f2);
        boss.executeForm(f2);

        boss.signForm(f3);
        boss.executeForm(f3);
    }catch (std::exception &e){
        std::cout << "exception: " << e.what() << std::endl;
    }
    return 0;
}