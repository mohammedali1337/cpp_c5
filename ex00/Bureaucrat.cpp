#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string &n, int g): name(n)
{
    if (g <= 0)
        throw GradeTooLowException();
    else if (g > 150)
        throw GradeTooHighException();
    else 
        this->grade = g;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat &ob): name(ob.name)
{
    this->grade = ob.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ob)
{
    if (this != &ob)
        this->grade = ob.grade;
    return *this;
}

const std::string &Bureaucrat::getName()const{return (this->name);}
int Bureaucrat::getGrade()const{return (this->grade);}

void Bureaucrat::incrementGrade()
{
    if (this->getGrade() <= 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->getGrade() >= 150)
        throw GradeTooLowException();
    this->grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade to hight!");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("grade to low!");
}
