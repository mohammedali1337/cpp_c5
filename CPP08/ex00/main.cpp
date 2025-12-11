#include "easyfind.hpp"
#include <list>

int main(void)
{
    std::vector<int> myVector;
    std::cout << sizeof(myVector) << std::endl;

    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    myVector.push_back(5);

    try{
        std::vector<int>::iterator it = easyfind(myVector, 3);
        std::cout << "found value: " << *it << std::endl;

        it = easyfind(myVector, 111);
        std::cout << "found value: " << *it << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}