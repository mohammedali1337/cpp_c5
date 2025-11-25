#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;

    public:

        Bureaucrat();
        Bureaucrat(const std::string &n, int g);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat & ob);
        Bureaucrat &operator= (const Bureaucrat & ob);


        const std::string &getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &f);

        void executeForm(AForm const & Form) const;

        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif