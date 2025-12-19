#include "RPN.hpp"

int main(int c, char **v)
{
    if (c != 2)
    {
        std::cout << "Error: " << std::endl;
        return 1;
    }

    RPN mathEx;
    try
    {
        mathEx.run(v[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}