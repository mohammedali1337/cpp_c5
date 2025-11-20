#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(){}

Intern::Intern(const Intern& ob)
{
    (void)ob;
}

Intern& Intern::operator=(const Intern& ob)
{
    (void)ob;
    return  *this;
}

Intern::~Intern(){};

AForm* shrubberyForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}
AForm* robotForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}
AForm* pardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string strArray[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*func[3])(std::string) = {shrubberyForm, robotForm, pardonForm};
    for (int i = 0; i < 3; i++)
    {
        if (name == strArray[i])
        {
            std::cout << "Intern created " << name << std::endl;
            return (func[i](target));
        }
    }
    std::cout << "error the name does not exist " << std::endl;
    return NULL;
}