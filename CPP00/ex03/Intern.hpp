#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>

class AForm;

class Intern
{
    public:
    Intern();
    Intern(const Intern &ob);
    Intern& operator=(const Intern& ob);
    ~Intern();

    AForm* makeForm(std::string name, std::string target);
};

#endif