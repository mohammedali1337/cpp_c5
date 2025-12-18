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
    try{
        btc.run(v[1]);
    }
    catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    
    return 0;
}