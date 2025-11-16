#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"
class RobotomyRequestForm: public Form
{
    RobotomyRequestForm(std::string name);
    void execute(Bureaucrat const & executor) const;
};

#endif