#include "PmergeMe.hpp"
#include <chrono>
#include <iomanip>

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

std::deque<int> PmergeMe::sortDeque()
{


    std::deque<int> sortedResult = mergeInsertSort(_dequeContainer);
   return sortedResult;
    
}
std::vector<int> PmergeMe::sortVector()
{
    std::vector<int> sortedResult = mergeInsertSort(_vectorContainer);
    return sortedResult;
}

std::size_t PmergeMe::jacobsthal(std::size_t n) const
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}


std::deque<std::size_t> PmergeMe::buildInsertionOrder(std::size_t count) const
{
    std::deque<std::size_t> order;
    if(count == 0)
        return order;
    order.push_back(0);

    std::size_t previous = 1;
    std::size_t current = 3;
    std::size_t jacobIndex = 4;

    while(previous < count)
    {
        std::size_t upper = current;

        if(upper > count)
            upper = count;
        std::size_t index = upper;
        while(index > previous)
        {
            --index;
            order.push_back(index);
        }
        previous = current;
        current = jacobsthal(jacobIndex);
        ++jacobIndex;
    }


    return order;
}

void PmergeMe::printTimer()
{
    std::chrono::high_resolution_clock::time_point dequeStart = std::chrono::high_resolution_clock::now();
    std::deque<int> sortedDeque = sortDeque();
    std::chrono::high_resolution_clock::time_point dequeEnd = std::chrono::high_resolution_clock::now();

    std::chrono::high_resolution_clock::time_point vectorStart = std::chrono::high_resolution_clock::now();
    std::vector<int> sortedVector = sortVector();
    std::chrono::high_resolution_clock::time_point vectorEnd = std::chrono::high_resolution_clock::now();
    std::cout << "After: ";
    for(std::vector<int>::size_type i = 0; i < sortedVector.size(); ++i)
    {
        std::cout << sortedVector[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for(std::deque<int>::size_type index = 0; index < sortedDeque.size(); ++index)
    {
        std::cout << sortedDeque[index] << " ";
    }
    std::cout << std::endl;
    double dequeTime = std::chrono::duration<double, std::micro>(dequeEnd - dequeStart).count();
    double vectorTime = std::chrono::duration<double, std::micro>(vectorEnd - vectorStart).count();

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << sortedDeque.size()
              << " elements with std::deque : "
              << dequeTime << " us" << std::endl;
    std::cout << "Time to process a range of " << sortedVector.size()
              << " elements with std::vector : "
              << vectorTime << " us" << std::endl;
}