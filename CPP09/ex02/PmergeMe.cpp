#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& ob)
{
    *this = ob;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& ob)
{
    if (this != &ob)
    {
        _vectorData = ob._vectorData;
        _dequeData = ob._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::run(int c, char **v)
{
    _parseNumber(c, v);
    std::cout << "Before:   ";
    size_t printLimit = _vectorData.size();
    for (size_t i = 0; i < printLimit; i++)
        std::cout << _vectorData[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    _mergeInsertSortVector(_vectorData);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 10;

    clock_t startDeq = clock();
    _mergeInsertSortDeque(_dequeData);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 10;

    std::cout << "After:    ";
    for (size_t i = 0; i < printLimit; i++)
        std::cout << _vectorData[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;


}

void PmergeMe::_parseNumber(int c, char **v)
{
    for (int i = 1; i < c; i++)
    {
        std::string arg = v[i];
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!isdigit(arg[j]))
                throw std::runtime_error("Error: Invalid number. ");
        }
        long val = std::atol(arg.c_str());
        if (val < 0 || val > INT_MAX)
            throw std::runtime_error("Error: Number out of range. ");
        _vectorData.push_back(static_cast<int>(val));
        _dequeData.push_back(static_cast<int>(val));
    }
}

void PmergeMe::_mergeInsertSortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return ;
    
    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
    {
        straggler = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i+=2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));

    }

    std::vector<int> mainChain;
    for(size_t i = 0; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
    }

    _mergeInsertSortVector(mainChain);

    std::vector<int> pendChain;


    std::vector<int> reorderedPend;

    for (size_t i = 0; i < mainChain.size(); i++)
    {
        int winner = mainChain[i];
        for(size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == winner)
            {
                reorderedPend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), reorderedPend[0]);
    std::vector<int> finalPend;
    for(size_t i = 1; i < reorderedPend.size(); i++)
        finalPend.push_back(reorderedPend[i]);
    
    if (hasStraggler)
        finalPend.push_back(straggler);

    if (!finalPend.empty())
        _insertInVector(mainChain, finalPend);
    
    arr = mainChain;
}

int PmergeMe::_getJacobsthal(int n)
{
    if (!n) return 0;
    if (n == 1) return 1;

    int prev2 = 0;
    int prev1 = 1;
    int current = 0;

    for (int i = 2; i <= n; i++)
    {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

void PmergeMe::_insertInVector(std::vector<int>& mainChain, std::vector<int>& pendChain)
{
    size_t n_pend = pendChain.size();
    size_t inserted_count = 0;

    int jacobIdx = 1;
    size_t last_pos = 0;

    while (inserted_count < n_pend)
    {
        int idx = _getJacobsthal(++jacobIdx);
        size_t current_pos = idx - 1;

        if (current_pos >= n_pend)
            current_pos = n_pend - 1;

        size_t limit = last_pos;

        for (size_t i = current_pos; ; i--)
        {
            if (i < limit)
                break;
            
            int val = pendChain[i];

            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
            mainChain.insert(it, val);

            inserted_count++;
            if (i == 0)
                break;;
        }
        last_pos = current_pos + 1;
    }
}

void PmergeMe::_mergeInsertSortDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;

    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
    {
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].first);

    _mergeInsertSortDeque(mainChain);

    std::deque<int> reorderedPend;
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        int winner = mainChain[i];
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == winner)
            {
                reorderedPend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    mainChain.push_front(reorderedPend[0]);

    std::deque<int> finalPend;
    for (size_t i = 1; i < reorderedPend.size(); i++)
        finalPend.push_back(reorderedPend[i]);

    if (hasStraggler)
        finalPend.push_back(straggler);

    if (!finalPend.empty())
        _insertInDeque(mainChain, finalPend);

    arr = mainChain;
}

void PmergeMe::_insertInDeque(std::deque<int>& mainChain, std::deque<int>& pendChain)
{
    size_t n_pend = pendChain.size();
    size_t inserted_count = 0;
    int jacobIdx = 1;
    size_t last_pos = 0;

    while (inserted_count < n_pend)
    {
        int idx = _getJacobsthal(++jacobIdx);
        size_t current_pos = idx - 1;

        if (current_pos >= n_pend)
            current_pos = n_pend - 1;

        size_t limit = last_pos;

        for (size_t i = current_pos; ; i--)
        {
            if (i < limit)
                break;

            int val = pendChain[i];
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
            mainChain.insert(it, val);

            inserted_count++;
            
            if (i == 0)
                break;
        }
        last_pos = current_pos + 1;
    }
}