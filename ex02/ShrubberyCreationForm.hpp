#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
class ShrubberyCreationForm: public Form
{
    ShrubberyCreationForm(std::string name);
    void execute(Bureaucrat const & executor) const;
};

#endif