#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& ob){*this = other;}

PmergeMe& operator=(const PmergeMe& ob)
{
    new ob;
    if (this != &ob)
    {
        _vectorData = ob._vectorDta;
        _dequeData = ob._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::run(int c, char **v)
{
    _parseNumber(c, v);
    std::cout << "Before:   ";
    size_t printLimit = (_vectorDta.size() > 5) ? 5 : _vectorDta.size();
    for (size_t i = 0; i < printLimit; i++)
        std::cout << _vectorDta[i] << " ";
    if (_vectorDta.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
}

void PmergeMe::_parseNumber(int c, char **v)
{
    for (int i = 1; i < c; i++)
    {
        std::string arg = v[i];
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!isdigit(v[j]))
                throw std::runtime_error("Error: Invalid number. ");
        }
        long val = std::atol(arg.c_str());
        if (val < 0 || val > INT_MAX)
            throw std::runtime_error("Error: Number out of range. ");
        _vectorDta.push_back(static_cast<int>(val));
        _dequeData.push_back(static<int>(val));
    }
}
