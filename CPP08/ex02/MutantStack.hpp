#pragma once 

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack(){}
        MutantStack(const MutantStack& ob): std::stack<T>(ob){}
        MutantStack& operator=(const MutantStack& ob)
        {
            if (this != &ob)
                std::stack<T>::operator=(ob);
            return *this;
        }
        ~MutantStack(){}

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }
};