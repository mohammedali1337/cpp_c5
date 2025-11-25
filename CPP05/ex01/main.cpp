#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat ob1("simo", 2);
        Form of2("form2", 3, 150);
        Form of1("form1", 1, 10);

        std::cout << of1 << std::endl;
        std::cout << of2 << std::endl;

        ob1.signForm(of1);
        ob1.signForm(of2);

        std::cout << of1 << std::endl;
        std::cout << of2 << std::endl;

        Form of3("form3", 151, 10);
    }
    catch (std::exception &e)
    {
        std::cout << "exception : " << e.what() << std::endl;
    }

    return 0;
}
