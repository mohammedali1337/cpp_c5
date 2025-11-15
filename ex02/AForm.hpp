#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        AForm();
        AForm(std::string na, int sinG, int execG);
        AForm(const AForm& ob);
        virtual ~AForm();
        AForm& operator= (const AForm& ob);
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

        virtual void execute(Bureaucrat const & executor) const = 0;

};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif