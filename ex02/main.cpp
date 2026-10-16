#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cerr << "invalid usage" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe bank;
        bank.validateArgs(ac, av);
        std::cout << "Before: ";
        for(int i = 1; i < ac; i++)
        {
            std::cout << av[i] << " ";
        }
        std::cout << std::endl;
   
        bank.printTimer();
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;

}



    // std::deque<std::size_t> testOrder = buildInsertionOrder(3);

    // std::cout << "Order: ";
    // for (std::deque<std::size_t>::size_type i = 0;
    //      i < testOrder.size();
    //      ++i)
    // {
    //     std::cout << testOrder[i] << " ";
    // }
    // std::cout << std::endl;