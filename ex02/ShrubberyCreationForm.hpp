#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>

class AForm;

class ShrubberyCreationForm: public AForm
{
    private:
        const std::string target;
        ShrubberyCreationForm();
        void performAction() const;
    public:
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(const ShrubberyCreationForm& ob);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ob);
        ~ShrubberyCreationForm();
};

#endif