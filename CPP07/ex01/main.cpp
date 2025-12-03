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
    return 0;
}