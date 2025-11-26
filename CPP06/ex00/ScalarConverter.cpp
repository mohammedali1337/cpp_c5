#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& ob)
{
    (void)ob;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ob)
{
    (void)ob;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

static void printChar(double val)
{
    std::cout << "char: ";

    if (std::isnan(val) || std::isinf(val))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }

    if (val < 0 || val > 127)
    {
        std::cout << "impossible" << std::endl;
        return ;
    }

    char c = static_cast<char>(val);

    if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

static void printInt(double val)
{
    std::cout << "int: ";

    if (std::isnan(val) || std::isinf(val) || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;
}

static void printFloat(double val)
{
    std::cout << "float: ";
    if (std::isnan(val))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(val))
        std::cout << (val > 0 ? "+inff" : "-inff") << std::endl;
    else
    {
        float f = static_cast<float>(val);
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }
}

static void printDouble(double val)
{
    std::cout << "double: ";
    if (std::isnan(val))
        std::cout << "nan" << std::endl;
    else if (std::isinf(val))
        std::cout << (val > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << val << std::endl;
}

static void printLiteral(double val)
{
    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}

void ScalarConverter::convert(std::string literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        return ;
    }
    char *end;
    double val = std::strtod(literal.c_str(), &end);
    std::string remainder(end);

    if (remainder != "f" && remainder != "")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }

    printLiteral(val);
}