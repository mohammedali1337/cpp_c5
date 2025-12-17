#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    loadDataBase("data.csv");
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& ob)
{
    *this = ob;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ob)
{
    if (this != &ob)
        this->dataBase = ob.dataBase;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::loadDataBase(const std::string& fileName)
{
    std::istream nameData(fileName);
}