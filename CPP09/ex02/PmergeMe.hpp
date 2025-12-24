#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int> _vectorDta;
        std::deque<int> _dequeData;

        void _parseNumber(int c, char **v);

        int _getJacobsthal(int n);
        
        void _mergeInsertSortVector(std::vector<int>& arr);
        void _insertInVector(std::vector<int>& mainChain, std::vector<int>& pendChain);

        void _mergeInsertSortDeque(std::deque<int>& arr);
        void _insertInDeque(std::deque<int>& mainChain, std::deque<int>& pendChain);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ob);
        PmergeMe& operator=(const PmergeMe& ob);
        ~PmergeMe();
        
        void run(int c, char **v);
};