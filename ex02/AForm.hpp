#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // Forward declaration

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;
        AForm(); // Private default constructor

    protected:
        // This is the new pure virtual function for the concrete classes
        virtual void performAction() const = 0; 

    public:
        // OCF
        AForm(const std::string& name, int signGrade, int execGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        // Getters
        const std::string&  getName() const;
        bool                getIsSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;

        // Member Functions
        void    beSigned(const Bureaucrat& bureaucrat);

        // This is the new public, NON-VIRTUAL execute function [cite: 207]
        void    execute(const Bureaucrat& executor) const;

        // --- Exceptions ---
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        
        // You need to add this new exception class
        class FormNotSignedException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif