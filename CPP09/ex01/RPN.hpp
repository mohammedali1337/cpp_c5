#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class RPN
{
    private:
        std::stack<double> _stack;
    public:
        RPN();
        RPN(const RPN& ob);
        ~RPN();
        RPN& operator=(const RPN& ob);

        void run(std::string input);
};