#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error: could not open file" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange DB;
        DB.loadData("data.csv");
        DB.processInput(av[1]);
    }
    catch(std::exception &e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    }
    return 0;

}