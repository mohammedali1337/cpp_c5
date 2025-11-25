#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	try 
	{
		Bureaucrat ali("ali", 146);
		Bureaucrat boss("boss", 1);

		ShrubberyCreationForm f1("home");
		RobotomyRequestForm f2("bender");
		PresidentialPardonForm f3("marvin");

		std::cout << ali << std::endl;
		std::cout << f1 << std::endl << std::endl;

		ali.signForm(f1);
		std::cout << f1 << std::endl << std::endl;
		ali.executeForm(f1);
		std::cout << std::endl << std::endl;

		boss.signForm(f1);
		std::cout << f1 << std::endl << std::endl;
		boss.executeForm(f1);

		std::cout << std::endl << std::endl;

		boss.signForm(f2);
		std::cout << f2 << std::endl << std::endl;
		boss.executeForm(f2);

		std::cout << std::endl << std::endl;

		boss.signForm(f3);
		std::cout << f3 << std::endl << std::endl;
		boss.executeForm(f3);

	}catch (std::exception &e){
		std::cout << "exception: " << e.what() << std::endl;
	}
	return 0;
}