#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& ob);
        ScalarConverter& operator=(const ScalarConverter& ob);
        ~ScalarConverter();

    public:
        static void convert(std::string literal);
};

#endif