#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("Default Bureaucrat"), grade(150){}

Bureaucrat::Bureaucrat(const std::string &n, int g): name(n)
{
    if (g < 1)
        throw GradeTooHighException();
    else if (g > 150)
        throw GradeTooLowException();
    else 
        this->grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ob): name(ob.name), grade(ob.grade){}

Bureaucrat::~Bureaucrat(){}

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
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->getGrade() >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl; 
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat: grade to hight!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat: grade to low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}