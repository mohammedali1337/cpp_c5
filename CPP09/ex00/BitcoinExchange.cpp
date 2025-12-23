#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	try
	{
		loadDataBase();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
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

void BitcoinExchange::loadDataBase()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file. ");

	std::string line;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		dataBase[line.substr(0, pos)] = std::strtod(line.substr(pos + 1).c_str(), NULL);
	}

	file.close();
}

void BitcoinExchange::run(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	
	std::string line;

	std::getline(file, line);
	if (line !=  "date | value")
		throw std::runtime_error("Error: bad header. ");
	
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		
		size_t delimiterPos = line.find('|');
		if (delimiterPos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, delimiterPos));
		std::string valueStr = trim(line.substr(delimiterPos + 1));

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!isValidValue(valueStr))
			continue;
		
		double value = std::strtod(valueStr.c_str(), NULL);
		
		std::map<std::string, double>::const_iterator it = dataBase.lower_bound(date);

		if (it == dataBase.end() || it->first != date)
		{
			if (it == dataBase.begin())
			{
				std::cout << "Error: date too early => " << date << std::endl;
				continue;
			}
			it--;
		}
		double result = value * it->second;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	file.close();
}

std::string BitcoinExchange::trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t");
	if (std::string::npos == first)
		return str;
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidValue(const std::string& valueStr)
{
	if (valueStr.empty() || valueStr == ".")
	{
		std::cout << "Error: bad input => " << valueStr << std::endl;
		return false;
	}
	char* endptr;
	double value = std::strtod(valueStr.c_str(), &endptr);
	if (*endptr != '\0')
	{
		std::cout << "Error: bad input => " << valueStr << std::endl;
		return false;
	}
	if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() > 10)
		return false;
	size_t firstDash = date.find('-');
	size_t secondDash = date.find('-', firstDash + 1);
	std::string year(date.substr(0, firstDash));
	std::string month(date.substr(firstDash + 1, secondDash));
	std::string day(date.substr(secondDash + 1));
	int yearInt, monthInt, dayInt;

	yearInt = std::atoi(year.c_str());
	monthInt = std::atoi(month.c_str());
	dayInt = std::atoi(day.c_str());

	if (yearInt < 2009 || yearInt > 2025)
		return false;
	if (monthInt < 1 || monthInt > 12)
		return false;
	if (dayInt < 1 || dayInt > 31)
		return false;
    if (dayInt == 31 && (monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11))
		return false;
    if (monthInt == 2) {
        bool isLeap = (yearInt % 4 == 0 && yearInt % 100 != 0) || (yearInt % 400 == 0);
        if (dayInt > (isLeap ? 29 : 28))
			return false;
    }
	return true;
}