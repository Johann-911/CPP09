#include "RPN.hpp"


RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
    _stack = copy._stack;
}

RPN &RPN::operator=(const RPN &copy)
{
    if(this != &copy)
    {
        _stack = copy._stack;
    }
    return *this;
}

RPN::~RPN()
{
}

int RPN::evaluate(std::string input)
{
    while (!_stack.empty())
    {
        _stack.pop();
    }
    std::stringstream stream(input);
    std::string token;
    while(stream >> token)
    {
        if(token.size() == 1 && std::isdigit(token[0]))
        {
            int number = token[0] - '0';
            _stack.push(number);
        }
        else
        {
            if(token == "*" || token == "/" || token == "-" || token == "+")
            {
                char op = token[0];
                if(_stack.size() < 2)
                    throw std::runtime_error("wrong input");
                int right = _stack.top();
                _stack.pop();
                int left = _stack.top();
                _stack.pop();
                
                int result;
                switch(op)
                {
                    case '+':
                        result = left + right;
                        break;
                    case '-':
                        result = left - right;
                        break;
                    case '*':
                        result = left * right;
                        break;
                    case '/':
                        if(right == 0)
                            throw std::runtime_error("division by zero");
                        result = left / right;
                        break;
                }
                _stack.push(result);
            }
            else
            {
                throw std::runtime_error("wrong input");
            }
        }
    }
    if(_stack.size() != 1 )
        throw std::runtime_error("wrong input");
    return _stack.top();

}