#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <stack>
#include <list>
#include <stdbool.h>
#include <climits>
#include <fstream>
#include <sstream>
#include <stack>
#include <cctype>
#include <utility>
#include <cmath>


class RPN 
{
    private:
        std::stack<int, std::list<int> > _stack;
    
    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN();

        int evaluate(std::string input);
};



#endif