#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("DefaultTarget"){}

RobotomyRequestForm::RobotomyRequestForm(std::string name): AForm("RobotomyRequestForm", 72, 45), target(name){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ob): AForm(ob), target(ob.target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ob)
{
    if (this != &ob)
    {
        AForm::operator=(ob);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::performAction() const
{
    srand(time(NULL));

    std::cout << "* FZzzzzzzzzzzzzzzz ta9smrmla9 .........................! *"<< std::endl;
    if (rand() % 2)
    {
        std::cout << this->target << "has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy on " << this->target << " has failded " << std::endl;
    }
}