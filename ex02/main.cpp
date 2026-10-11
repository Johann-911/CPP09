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
        // bank.sortDeque();
        // bank.sortVector();


    }
    catch(const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;

}