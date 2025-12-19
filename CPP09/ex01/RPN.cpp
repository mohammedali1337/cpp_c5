#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& ob):_stack(ob._stack){}

RPN& RPN::operator=(const RPN& ob){
    if (this != &ob)
        this->_stack = ob._stack;
    return *this;
}

RPN::~RPN(){}

void RPN::run(std::string input)
{
    for (int i = 0; input[i]; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            if (input[i + 1] != ' ')
                throw std::runtime_error("Error");
            int value = input[i] - '0';
            this->_stack.push(value);
        }
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            if (this->_stack.size() < 2)
                throw std::runtime_error("Error");
            double b = this->_stack.top();
            this->_stack.pop();
            double a = this->_stack.top();
            this->_stack.pop();
            double result;
            if (input[i] == '+')
                result = a + b;
            else if (input[i] == '-')
                result = a - b;
            else if (input[i] == '*')
                result = a * b;
            else if (input[i] == '/')
            {
                if (b == 0)
                    throw std::runtime_error("Error");
                result = a / b;
            }
            this->_stack.push(result);
        }
    }
    std::cout << this->_stack.top() << std::endl;
}