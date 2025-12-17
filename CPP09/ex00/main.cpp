#include "BitcoinExchange.hpp"
#include <fstream>


int main(int c, char **v)
{
    if (c != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    btc.run(v[1]);
    
    return 0;
}