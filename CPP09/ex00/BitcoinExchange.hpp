#pragma once 
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <exception>

class BitcoinExchange
{
    private:
        std::map<std::string, double> dataBase;
        void    loadDataBase();
        std::string trim(const std::string& str);
        bool isValidDate(const std::string& date);
        bool isValidValue(const std::string& valueStr);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& ob);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& ob);

        void run(const std::string& filename);
};