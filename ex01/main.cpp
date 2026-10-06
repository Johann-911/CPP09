#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << " invalid usage" << std::endl;
        return 1;
    }
    RPN stack;
    try{

        std::cout << stack.evaluate(av[1]) << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;

}