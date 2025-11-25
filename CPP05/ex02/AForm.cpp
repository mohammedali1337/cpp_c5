#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : 
    name("Default"), 
    isSigned(false), 
    signGrade(150), 
    execGrade(150)
{

}

AForm::AForm(const std::string& name, int signGrade, int execGrade) :
    name(name),
    isSigned(false),
    signGrade(signGrade),
    execGrade(execGrade)
{
    if (this->signGrade < 1 || this->execGrade < 1)
        throw AForm::GradeTooHighException();
    if (this->signGrade > 150 || this->execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) :
    name(other.name),
    signGrade(other.signGrade),
    execGrade(other.execGrade)
{
    this->isSigned = other.isSigned;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm(){}

const std::string& AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecGrade() const
{
    return this->execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->signGrade)
    {
        throw AForm::GradeTooLowException();
    }
    this->isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (this->isSigned == false)
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->execGrade)
    {
        throw AForm::GradeTooLowException();
    }
    this->performAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm: Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form \"" << form.getName() << "\":"
       << "\n  Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << "\n  Grade required to sign: " << form.getSignGrade()
       << "\n  Grade required to execute: " << form.getExecGrade();
    return os;
}