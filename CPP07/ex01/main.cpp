#include "iter.hpp"

void powOfTwo(int &a)
{
    a *= a;
}

template <typename T>
void printElemen(const T &x)
{
    std::cout << x << " " << std::endl;
}

int main(void)
{
    int s[] = {1, 2, 3, 4};
    std::cout << "before iter: " << std::endl;
    iter(s, 4, printElemen<int>);
    iter(s, 4, powOfTwo);
    std::cout << "after iter: " << std::endl;
    iter(s, 4, printElemen<int>);

    std::cout << "test2: const array (read only) " << std::endl;
    const std::string words[] = {"hello", "world", "fsfs"};

    iter(words, 3, printElemen<std::string>);
    return 0;
}