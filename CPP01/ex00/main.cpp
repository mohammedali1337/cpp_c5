#include "ScalarConverter.hpp"

int main(int c, char **v)
{
    if (c != 2)
    {
        std::cout << "Usage: ./convert <literal> " << std::endl;
        return 1;
    }

    ScalarConverter::convert(v[1]);
    return 0;
}