#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
        Intern someRandomIntern;
        Bureaucrat ali("ali", 100);
        Bureaucrat boss("boss", 1);
        Bureaucrat miniboos("miniboss", 140);

        AForm *f1 = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm *f2 = someRandomIntern.makeForm("robotomy request", "bender");
        AForm *f3 = someRandomIntern.makeForm("presidential pardon", "niza");
        AForm *invalidss = someRandomIntern.makeForm("invalid", "??");


        if (f1) std::cout << *f1 << std::endl;
        if (f2) std::cout << *f2 << std::endl;
        if (f3) std::cout << *f3 << std::endl;
        if (invalidss) std::cout << *invalidss << std::endl;
        
        if (f1) boss.signForm(*f1);
        if (f2) boss.signForm(*f2);
        if (f3) boss.signForm(*f3);
        if (invalidss) boss.signForm(*invalidss);
        
        if (f1) std::cout << *f1 << std::endl;
        if (f2) std::cout << *f2 << std::endl;
        if (f3) std::cout << *f3 << std::endl;
        
    }catch (std::exception &e){
        std::cout << "exception: " << e.what() << std::endl;
    }
    return 0;
}