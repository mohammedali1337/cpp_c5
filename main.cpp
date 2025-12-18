#include <iostream>
#include <string>

using namespace std;

std::string trim(const std::string& str)
{
	std::string trimLine;


	trimLine = str.substr(0, str.find(','));
	return trimLine;
}

int main(void)
{
    // int x = static_cast<int>(3.9);
    // cout << x << endl;
    // return 0;




    std::cout << trim("2009-02-01,0") << std::endl;
}