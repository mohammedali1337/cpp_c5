#include <iostream>
#include <map>
#include <algorithm>


template <typename T, typename T2>
void printMap(std::map<T, T2> myMap)
{
    for (auto it = myMap.begin(); it != myMap.end(); it++)
        std::cout << it->first << " | " << it->second << std::endl;
}


int main(void)
{

    {
        std::map<std::string, std::string> myMap;

        myMap.emplace("1", "ali");
        myMap.emplace("2", "mohammed");
        myMap.emplace("-2", "mohammed");

        std::cout << "myMap size = " << myMap.size() << std::endl;
        
        printMap(myMap);

    }
    
    std::cout << "------------------------------------test2----------------------------------" << std::endl;
    {
        std::map<int, std::string> myMap;
        
        myMap[3] = "three";
        myMap[1] = "one";
        myMap[2] = "two";
        
        myMap.insert(std::pair<int, std::string>(5, "five"));
        
        std::cout << "myMap size = " << myMap.size() << std::endl;
        printMap(myMap);
        
        if(myMap.count(4))
        std::cout << "element with key 3 is exist and it's value : " << myMap.at(4) << std::endl;
        else
        std::cout << "there is no element with key 3";
        
    }
    
    std::cout << "------------------------------------test3----------------------------------" << std::endl;
    
    {
        std::map<int, std::string> myMap;
        
        myMap[3] = "three";
        myMap[1] = "one";
        myMap[2] = "two";
        
        printMap(myMap);
        
        myMap.erase(2);
        std::cout << std::endl << "efter use erase " << std::endl;
        
        printMap(myMap);
    }

    std::cout << "------------------------------------test3----------------------------------" << std::endl;

    {
        std::map<int, std::string> myMap;
        
        myMap[3] = "three";
        myMap[1] = "one";
        myMap[2] = "two";
        
        std::map<int, std::string>::iterator it;

        it = myMap.find(2);

        if (it != myMap.end())
        {
            std::cout << "Element with key " << it->first << " is removed from myMap" << std::endl << std::endl;
            myMap.erase(it);
        }

        std::cout << "myMap keys and values: " << std::endl;

        printMap(myMap);
    }

    std::cout << "------------------------------------------------test4----------------------------------------" << std::endl;

    {
        std::map<std::string, std::string> myMap;

        myMap.emplace("1", "ali");
        myMap.emplace("2", "mohammed");
        myMap.emplace("4", "ssss");
        myMap.emplace("8", "kkkkkkkk");
        myMap.emplace("9", "3s");
        myMap.emplace("-2", "mohammed");

        myMap.lower_bound("7");
        
    }
}