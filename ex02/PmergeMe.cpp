#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    _vectorContainer = copy._vectorContainer;
    _dequeContainer = copy._dequeContainer;

}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if(this != &copy)
    {
        _vectorContainer = copy._vectorContainer;
        _dequeContainer = copy._dequeContainer;
    }
    return *this;
}


PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseInput(std::string input)
{
    std::stringstream stream(input);
    int number = 0;
    if(!(stream >> number))
    {
        throw std::runtime_error("invalid argument, use a number");
    }
    char extra;
    if(stream >> extra)
    {
        throw std::runtime_error("invalid argument");
    }
    if(number <= 0)
    {
        throw std::runtime_error("must be a positiv number");
    }
    _dequeContainer.push_back(number);
    _vectorContainer.push_back(number);


}
 

void PmergeMe::validateArgs(int ac, char **av)
{
    for(int i = 1; i < ac; i ++)
    {
        parseInput(av[i]);
    }
}

void PmergeMe::sortDeque()
{



}
