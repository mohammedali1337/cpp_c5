#include "Form.hpp"

Form::Form(): name("default"), isSigned(false), signGrade(150), execGrade(150) {}

Form::Form(std::string na, int sinG, int execG): name(na), isSigned(false), signGrade(sinG), execGrade(execG)
{
    if (sinG <= 0 || execG <= 0)
        throw GradeTooHighException();
    if (sinG > 150 || execG <= 150)
        throw GradeTooLowException();
}

Form::Form(const Form& ob): name(ob.name), isSigned(ob.isSigned), signGrade(ob.signGrade), execGrade(ob.execGrade){}

Form::~Form(){};

Form& Form::operator= (const Form& ob)
{
    if (&ob != this)
        this->isSigned = ob.isSigned;
    return (*this);
}

const std::string &Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }

void Form::beSigned(Bureaucrat &ob)
{
    
}