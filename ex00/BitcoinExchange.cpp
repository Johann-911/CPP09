#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    _database = copy._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    (void)copy;
    return *this;
}


BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadData(std::string database)
{
    std::ifstream file(database.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("could not open database");
    }
    std::string line;
    std::getline(file, line);
    while(std::getline(file, line))
    {   
        std::string::size_type comma = line.find(',');
        if(comma == std::string::npos)
            throw std::runtime_error(" corrupt database");
        std::string date = line.substr(0, comma);
        std::string rateText = line.substr(comma + 1);
        std::stringstream stream(rateText);
        double rate;
        stream >> rate;
        _database[date] = rate;
    }


}

void BitcoinExchange::processInput(std::string input)
{
    std::ifstream file(input.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("could not open input");
    }
    std::string line;
    std::getline(file, line);
    while(std::getline(file, line))
    {
        std::string::size_type pipe = line.find('|');
        if(pipe == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line <<  std::endl;
            continue;
        }
        std::string date = line.substr(0, pipe);
        std::stringstream dateStream(date);
        dateStream >> date;    
        std::string valueText = line.substr(pipe + 1);
        std::stringstream stream(valueText);
        double value;
        stream >> value;
        if(value < 0 )
        {
            std::cerr << "Error: not a positive number" << std::endl;
            continue;
        }
        if(value > 1000 )
        {
            std::cerr << "Error: too large number" << std::endl;
            continue;
        }
        if(!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }   
        std::map<std::string, double>::iterator iterator;
        iterator = _database.find(date);
        if(iterator != _database.end())
            std::cout << date << " => " << value << " = " << value * iterator->second << std::endl; 
        
        else
        {
            iterator = _database.lower_bound(date);
            if(iterator == _database.begin())
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            else
            {
                --iterator;
                std::cout << date << " => " << value << " = " << value * iterator->second << std::endl;
            }
        }
    }

}

bool BitcoinExchange::isValidDate(std::string date)
{
    if(date.length() != 10)
        return false;
    if(date[4] != '-' || date[7] != '-')
        return false;
    
    for(int i = 0; i <= 3;i++)
    {
        if(!std::isdigit(date[i]))
            return false;
    } 
    for(int i = 5; i <= 6;i++)
    {
        if(!std::isdigit(date[i]))
            return false;
    }
    for(int i = 8; i <= 9;i++)
    {
        if(!std::isdigit(date[i]))
            return false;
    }
    std::string yearText = date.substr(0, 4);
    std::stringstream yearStream(yearText);
    int year;
    yearStream >> year;
    std::string monthText = date.substr(5, 2);
    std::stringstream monthStream(monthText);
    int month;
    monthStream >> month;
    std::string dayText = date.substr(8, 2);
    std::stringstream dayStream(dayText);
    int day;
    dayStream >> day;
    if(month < 1 || month > 12)
        return false;

    int maxDays = 0;
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            maxDays = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            maxDays = 30;
            break;
        case 2:
            maxDays = 28;
            break;
    }
    if(day < 1 || day > maxDays)
        return false;
    return true;

}