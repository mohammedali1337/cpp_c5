#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
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

        // exceptions

        class GradeTooHighException: public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            const char* what() const throw();
        };
};

#endif