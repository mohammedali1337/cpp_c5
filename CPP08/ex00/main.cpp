#include "easyfind.hpp"
#include <list>

int main(void)
{
    std::vector<int> myVector;

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
    
    std::cout << "--------------------------list container test--------------------------" << std::endl;

    std::list<int> myList;

    myList.push_back(1);
    myList.push_back(3);
    myList.push_back(14);
    myList.push_back(13);
    
    try
    {
        std::list<int>::iterator it = easyfind(myList, 2);
        std::cout << "should throw exception " << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        try
        {
            std::list<int>::iterator it = easyfind(myList, 14);
            std::cout << "find value: " << *it << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    

    return 0;

}