#include "functions.hpp"

int main(void)
{
    Base *baseOb = generate();

    std::cout << "Identify using pointer: " ;
    identify(baseOb);
    
    std::cout << "Identify using reference: " ;
    identify(*baseOb);

    delete baseOb;
    return 0;
}