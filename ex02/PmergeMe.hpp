#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <stdbool.h>
#include <climits>
#include <vector>
#include <deque>
#include <fstream>
#include <sstream>
#include <cctype>
#include <utility>
#include <cmath>

class PmergeMe 
{
    private:
        std::vector<int> _vectorContainer;
        std::deque<int> _dequeContainer;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();

        void parseInput(std::string numbers);
        void validateArgs(int ac, char **av);
        void sortVector();
        void sortDeque();
        void printTimer();



};

#endif