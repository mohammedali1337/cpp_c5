#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include <ctime>
#include <cstdlib>

class AForm;

class RobotomyRequestForm: public AForm
{
    private:
        const std::string target;
        RobotomyRequestForm();
        virtual void performAction() const;
    public:
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm& ob);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& ob);
        virtual ~RobotomyRequestForm();
};

#endif