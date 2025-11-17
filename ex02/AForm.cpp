#include "AForm.hpp"
#include "Bureaucrat.hpp" // Full include is needed here for getGrade()

/*
** ------------------------ Orthodox Canonical Form ------------------------
*/

// Private Default Constructor
AForm::AForm() : 
    _name("Default"), 
    _isSigned(false), 
    _signGrade(150), 
    _execGrade(150)
{
    // This private constructor shouldn't be called, 
    // but we initialize const members just in case.
}

// Parameterized Constructor
AForm::AForm(const std::string& name, int signGrade, int execGrade) :
    _name(name),
    _isSigned(false),
    _signGrade(signGrade),
    _execGrade(execGrade)
{
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw AForm::GradeTooHighException();
    if (this->_signGrade > 150 || this->_execGrade > 150)
        throw AForm::GradeTooLowException();
}

// Copy Constructor
AForm::AForm(const AForm& other) :
    _name(other._name),
    _signGrade(other._signGrade),
    _execGrade(other._execGrade)
{
    // We only copy the non-const member
    this->_isSigned = other._isSigned;
}

// Copy Assignment Operator
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        // We can't assign to const members (_name, _signGrade, _execGrade)
        // We can only assign the non-const members.
        this->_isSigned = other._isSigned;
    }
    return *this;
}

// Virtual Destructor (MUST have a body)
AForm::~AForm()
{
    // Destructor body
}

/*
** ------------------------------ Getters ------------------------------
*/

const std::string& AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getSignGrade() const
{
    return this->_signGrade;
}

int AForm::getExecGrade() const
{
    return this->_execGrade;
}

/*
** -------------------------- Member Functions ---------------------------
*/

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
    {
        throw AForm::GradeTooLowException();
    }
    this->_isSigned = true;
}

// The "elegant" execute function
void AForm::execute(const Bureaucrat& executor) const
{
    if (this->_isSigned == false)
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->_execGrade)
    {
        throw AForm::GradeTooLowException();
    }
    this->performAction();
}


/*
** ------------------------- Exception Functions -------------------------
*/

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

/*
** ---------------------- operator<< overload ----------------------
*/

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form \"" << form.getName() << "\":"
       << "\n  Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << "\n  Grade required to sign: " << form.getSignGrade()
       << "\n  Grade required to execute: " << form.getExecGrade();
    return os;
}