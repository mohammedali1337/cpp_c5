#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("default target"){}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm("PresidentialPardonForm", 25, 5), target(name)
{
    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ob):AForm(ob), target(ob.target){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ob)
{
    if (this != &ob)
    {
        AForm::operator=(ob);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::performAction() const
{
    std::cout << this->target << "has benn pardoned by Zaphod Beeblebrox. " << std::endl;
}
