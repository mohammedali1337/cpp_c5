#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include <string>

class AForm;

class PresidentialPardonForm: public AForm
{
    private:
        std::string target;
        PresidentialPardonForm();
        virtual void performAction() const ;
    public:
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm& ob);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& ob);
        virtual ~PresidentialPardonForm();
};

#endif