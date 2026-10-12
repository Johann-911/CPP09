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
    int first, second, rest;
    std::deque<int> _winnersQue;
    std::deque<int> _losersQue;
    std::deque<int> mainChain;
    std::deque<int> pending;
    std::deque< std::pair<int, int> > pairs;
    int i = 0;

    while(i + 1 < _dequeContainer.size())
    {
        first = _dequeContainer[i];
        second = _dequeContainer[i + 1];
        if(first > second)
        {
            _winnersQue.push_back(first);
            _losersQue.push_back(second);
        }
        else
        {
            _winnersQue.push_back(second);
            _losersQue.push_back(first);
        }
        while()
        {
            for (std::deque< std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
            {
                pairs.first = _winnersQue[0];
                pairs.second = _losersQue[0];
            }

        }
        i += 2;
    }
    if(i < _dequeContainer.size())
    {
        rest = _dequeContainer[i];
    }
    i = 0;
    _winnersQue.sortDeque();
    while(i + 1 < _winnersQue.size())
    {
        mainChain[i] = _winnersQue[i];
    }
    _losersQue.sortDeque();
    while(i + 1 < _losersQue.size())
    {
        pending[i] = _losersQue[i];
    }



}

void PmergeMe::sortVector()
{



}

void PmergeMe::printTimer()
{


    
}