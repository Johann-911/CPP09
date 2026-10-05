#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <stdbool.h>
#include <climits>
#include <fstream>
#include <sstream>
#include <cctype>
#include <utility>
#include <map>
#include <cmath>

class BitcoinExchange 
{
    private:
        std::map<std::string, double> _database;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();

        void loadData(std::string database);
        void processInput(std::string database);
        bool isValidDate(std::string date);
    

};

#endif