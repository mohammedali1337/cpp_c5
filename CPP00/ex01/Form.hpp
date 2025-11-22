#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        Form();
        Form(std::string na, int sinG, int execG);
        Form(const Form& ob);
        ~Form();
        Form& operator= (const Form& ob);
        const std::string &getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getIsSigned() const;

        void beSigned(Bureaucrat &ob);
    
        class GradeTooHighException: public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            const char* what() const throw();
        };
    
};
std::ostream &operator<<(std::ostream &os, const Form &f);
#endif