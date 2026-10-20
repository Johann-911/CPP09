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
        std::vector<int> sortVector();
        std::deque<int> sortDeque();        
        std::size_t jacobsthal(std::size_t n) const;
        std::deque<std::size_t> buildInsertionOrder(std::size_t count) const;
        void printTimer();
        
        template <typename Container>
        Container mergeInsertSort(const Container &values)
        {
            int rest = 0;
            bool hasRest = false;
            Container mainChain;
            std::size_t index = 0;
            std::vector< std::pair<int, int> > pairs;
            if (values.size() <= 1)
                return values;    
            while (index + 1 < values.size())
            {
                int first = values[index];
                int second = values[index + 1];
                int winner = first;
                int loser = second;

                if (winner < loser)
                {
                    winner = second;
                    loser = first;
                }
                mainChain.push_back(winner);
                pairs.push_back(std::make_pair(winner, loser));
                index += 2;
            }
            
            if (index < values.size())
            {
                rest = values[index];
                hasRest = true;
            }
            
            Container sortedChain = mergeInsertSort(mainChain);
            std::deque<std::size_t> order = buildInsertionOrder(pairs.size());

            for (std::size_t orderIndex = 0; orderIndex < order.size(); ++orderIndex)
            {
                std::size_t pairIndex = order[orderIndex];
                int winner = pairs[pairIndex].first;
                int loser = pairs[pairIndex].second;
            
                typename Container::iterator winnerPosition = sortedChain.begin();
                while (winnerPosition != sortedChain.end() && *winnerPosition != winner)
                {
                    ++winnerPosition;
                }
            
                typename Container::iterator first = sortedChain.begin();
                typename Container::iterator last = winnerPosition;
                while (first != last)
                {
                    typename Container::iterator middle = first + (last - first) / 2;
                    if(*middle < loser)
                        first = middle + 1;
                    else 
                        last = middle; 
                }
                sortedChain.insert(first, loser);
            }
            
            if (hasRest)
            {
                typename Container::iterator first = sortedChain.begin();
                typename Container::iterator last = sortedChain.end();
                while (first != last)
                {
                    
                    typename Container::iterator middle = first + (last - first) / 2;
                    if(*middle < rest)
                        first = middle + 1;
                    else
                        last = middle;
                }
                sortedChain.insert(first, rest);
            }
            return sortedChain;
        }
};
#endif