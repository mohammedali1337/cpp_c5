#include "Bureaucrat.hpp"


int main()
{
    // 1️⃣ Test valid Bureaucrat
    try
    {
        Bureaucrat b1("Ali", 2);
        std::cout << b1 << std::endl;

        // 2️⃣ Test incrementGrade
        b1.incrementGrade(); // should work (2 → 1)
        std::cout << b1 << std::endl;

        // 3️⃣ Test exception (increment again: will go out of range)
        b1.incrementGrade(); // should throw GradeTooHighException
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    // 4️⃣ Test invalid Bureaucrat creation
    try
    {
        Bureaucrat b2("Omar", 151); // invalid → GradeTooLowException
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    // 5️⃣ Test decrementGrade
    try
    {
        Bureaucrat b3("Sara", 149);
        std::cout << b3 << std::endl;

        b3.decrementGrade(); // 149 → 150 ok
        std::cout << b3 << std::endl;

        b3.decrementGrade(); // 150 → error
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
