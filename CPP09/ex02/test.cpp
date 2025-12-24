#include "PmergeMe.hpp"
#include <sys/time.h> // For accurate microsecond timing
#include <cstdlib>

// --- Orthodox Canonical Form ---
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

// --- Jacobsthal Generator ---
// J(n) = J(n-1) + 2*J(n-2)
int PmergeMe::_getJacobsthal(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    int prev2 = 0;
    int prev1 = 1;
    int current = 0;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// ======================= VECTOR IMPLEMENTATION =======================

void PmergeMe::_insertInVector(std::vector<int>& mainChain, std::vector<int>& pendChain)
{
    // 1. Insert the first pending element immediately (it's smaller than the first main element)
    // Actually, in strict FJ, b1 is paired with a1. We insert b1.
    // However, for implementation simplicity with stragglers, we use binary search for all.
    
    // We generate Jacobsthal numbers to determine insertion order
    // Sequence: 1, 3, 5, 11, 21...
    // But we need to map them to indices: 0, 1, 2, 4, 10... (index = J(n) - 1)
    
    size_t n_pend = pendChain.size();
    size_t inserted_count = 0;
    
    int jacobIdx = 1; // Start from J(1)
    size_t last_pos = 0; // The last position we processed

    while (inserted_count < n_pend)
    {
        // Get next Jacobsthal number
        // We want to process the range (last_pos, current_jacob_pos] backwards
        int idx = _getJacobsthal(++jacobIdx); 
        size_t current_pos = idx - 1; // Convert to 0-based index

        if (current_pos >= n_pend)
            current_pos = n_pend - 1;

        // Iterate backwards from current_pos to last_pos
        size_t limit = last_pos;
        
        // We use a temporary variable to iterate backwards safely with size_t
        for (size_t i = current_pos; i > limit || (i == limit && limit == 0 && inserted_count == 0); i--) 
        {
             // Fix for size_t underflow loop condition specific logic
             if (i < limit) break; // Safety break
             
             int val = pendChain[i];
             
             // Binary Search: std::lower_bound
             // We search in mainChain.
             // Optimization: We only need to search up to a certain point (bound).
             // But std::lower_bound on the whole valid vector is O(log N) anyway.
             std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
             mainChain.insert(it, val);
             
             inserted_count++;
             if (i == 0) break; // Avoid infinite loop with size_t
        }
        last_pos = current_pos + 1;
    }
}

void PmergeMe::_mergeInsertSortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;

    // 1. Check for straggler (odd element)
    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    // 2. Pair creation & Comparison
    // We store pairs: first = winner (larger), second = loser (smaller)
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // 3. Recursive Sort of the "Main Chain" (Winners)
    // We extract the winners into a new vector to sort them recursively
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
    }

    _mergeInsertSortVector(mainChain);

    // 4. Re-associate Losers
    // The mainChain is now sorted. We need to find where the corresponding losers go.
    // We create the 'pend' chain (losers).
    // NOTE: This part is tricky. We need to know which loser belongs to which winner.
    // Since mainChain is sorted, we can't just take pairs[i].second.
    // We must look up the winner in the pairs list to find its loser.
    
    std::vector<int> pendChain;
    // We also need to insert the straggler into pending if it exists
    // The first loser (pairs[0].second) is always inserted at the start of MainChain in standard FJ,
    // but typically we just treat it as a pending element for simplicity in code.
    
    // Let's reorganize pairs to match the sorted mainChain order
    // This is O(N^2) naive, but for this exercise constraints (3000 elements), it's acceptable.
    // Ideally, we would have sorted pairs<int, int> directly in the recursive step.
    
    std::vector<int> reorderedPend;
    for (size_t i = 0; i < mainChain.size(); i++) {
        int winner = mainChain[i];
        // Find this winner in original pairs
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first == winner) {
                reorderedPend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j); // Optimization: remove found pair
                break;
            }
        }
    }

    // 5. Insertion using Jacobsthal
    // Before passing to insert, add straggler to pending if strictly needed,
    // OR just insert straggler at the very end. 
    // Usually, straggler is treated as just another element to binary insert.
    
    // First element of pending (b1) is always smaller than first element of main (a1).
    // So we can insert it at the beginning immediately to save 1 comparison.
    mainChain.insert(mainChain.begin(), reorderedPend[0]);
    
    // Remove b1 from pending list for the bulk insertion function
    std::vector<int> finalPend;
    for (size_t i = 1; i < reorderedPend.size(); i++)
        finalPend.push_back(reorderedPend[i]);
    
    if (hasStraggler)
        finalPend.push_back(straggler);

    // Run the Jacobsthal insertion for the rest
    if (!finalPend.empty())
        _insertInVector(mainChain, finalPend);

    arr = mainChain;
}

// ======================= DEQUE IMPLEMENTATION (Copy-Paste Logic) =======================

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
        if (current_pos >= n_pend) current_pos = n_pend - 1;

        size_t limit = last_pos;
        for (size_t i = current_pos; i > limit || (i == limit && limit == 0 && inserted_count == 0); i--) 
        {
             if (i < limit) break;
             int val = pendChain[i];
             std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
             mainChain.insert(it, val);
             inserted_count++;
             if (i == 0) break;
        }
        last_pos = current_pos + 1;
    }
}

void PmergeMe::_mergeInsertSortDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1) return;

    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler) {
        straggler = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++) mainChain.push_back(pairs[i].first);

    _mergeInsertSortDeque(mainChain);

    std::deque<int> reorderedPend;
    for (size_t i = 0; i < mainChain.size(); i++) {
        int winner = mainChain[i];
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first == winner) {
                reorderedPend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    mainChain.push_front(reorderedPend[0]);

    std::deque<int> finalPend;
    for (size_t i = 1; i < reorderedPend.size(); i++) finalPend.push_back(reorderedPend[i]);
    if (hasStraggler) finalPend.push_back(straggler);

    if (!finalPend.empty()) _insertInDeque(mainChain, finalPend);

    arr = mainChain;
}

// ======================= RUNNER =======================

void PmergeMe::run(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Error: No arguments provided." << std::endl;
        return;
    }

    // 1. Parsing
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); j++) {
            if (!isdigit(arg[j])) {
                std::cerr << "Error: Invalid number." << std::endl;
                return;
            }
        }
        long val = std::atol(arg.c_str());
        if (val < 0 || val > INT_MAX) {
            std::cerr << "Error: Number out of range." << std::endl;
            return;
        }
        _vectorData.push_back(static_cast<int>(val));
        _dequeData.push_back(static_cast<int>(val));
    }

    // 2. Display Before
    std::cout << "Before: ";
    size_t printLimit = (_vectorData.size() > 5) ? 5 : _vectorData.size();
    for (size_t i = 0; i < printLimit; i++) std::cout << _vectorData[i] << " ";
    if (_vectorData.size() > 5) std::cout << "[...]";
    std::cout << std::endl;

    // 3. Process Vector
    clock_t startVec = clock();
    _mergeInsertSortVector(_vectorData);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

    // 4. Process Deque
    clock_t startDeq = clock();
    _mergeInsertSortDeque(_dequeData);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    // 5. Display After
    std::cout << "After:  ";
    for (size_t i = 0; i < printLimit; i++) std::cout << _vectorData[i] << " ";
    if (_vectorData.size() > 5) std::cout << "[...]";
    std::cout << std::endl;

    // 6. Display Times
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}