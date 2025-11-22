#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

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