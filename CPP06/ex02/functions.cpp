#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base * generate(void)
{
    std::srand(time(NULL));

    int randomNum = std::rand() % 3;
    if (randomNum == 0)
        return (new A());
    else if (randomNum == 1)
        return (new B());
    else 
        return (new C());
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try {
        A &ob = dynamic_cast<A&>(p);
        (void) ob;
        std::cout << "A" << std::endl;
    }
    catch(std::exception &e)
    {
        try {
            B &ob = dynamic_cast<B&>(p);
            (void) ob;
            std::cout << "B" << std::endl;
        }
        catch(std::exception &e)
        {
            try {
                C &ob = dynamic_cast<C&>(p);
                (void) ob;
                std::cout << "C" << std::endl;
            }
            catch(std::exception &e)
            {
                std::cout << "NONE" << std::endl;
            }
        }
    }
}