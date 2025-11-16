#include "AForm.hpp"

AForm::AForm(): name("default"), isSigned(false), signGrade(150), execGrade(150) {}

AForm::AForm(std::string na, int sinG, int execG): name(na), isSigned(false), signGrade(sinG), execGrade(execG)
{
    if (sinG <= 0 || execG <= 0)
        throw GradeTooHighException();
    if (sinG > 150 || execG > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& ob): name(ob.name), isSigned(ob.isSigned), signGrade(ob.signGrade), execGrade(ob.execGrade){}

AForm::~AForm(){};

AForm& AForm::operator= (const AForm& ob)
{
    if (this != &ob)
        this->isSigned = ob.isSigned;
    return (*this);
}

const std::string &AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getSignGrade() const { return signGrade; }

int AForm::getExecGrade() const { return execGrade; }

void AForm::beSigned(Bureaucrat &ob)
{
    if (this->getSignGrade() < ob.getGrade())
        throw GradeTooLowException();
    this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high for Aform!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low for Aform!");
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "AForm " << f.getName() << "[signGrade: " << f.getSignGrade() << ", execGrade: " << f.getExecGrade()
    << ", isSigned: " << (f.getIsSigned() ? "true" : "false") << "]";
    return os;
}