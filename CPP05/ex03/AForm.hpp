#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           signGrade;
        const int           execGrade;

    protected:
        virtual void performAction() const = 0; 

    public:
        AForm();
        AForm(const std::string& name, int signGrade, int execGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string&  getName() const;
        bool                getIsSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;

        void    beSigned(const Bureaucrat& bureaucrat);

        void    execute(const Bureaucrat& executor) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif