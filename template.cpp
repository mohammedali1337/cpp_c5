// #include <iostream>

// using namespace std;

// template <class T>

// T Max(T a, T b)
// {
//     return (a < b ? b:a);
// }

// int main(void)
// {

//     cout << "Max: " << Max(1, 2) << endl;
//     cout << "Max: " << Max(1.5, 2.5) << endl;
//     return 0;

// }

#include <iostream>

using namespace std;

template <typename T> T myMax(T x, T y)
{
    return (x > y) ? x:y;
}

int main(void)
{
    cout << "Max of 3 and 7 is: " << myMax<int>(3, 7) << endl;
    cout << "Max of 3.5 and 7.5 is :" << myMax<double>(3.5, 7.5) << endl;
    cout << "Max of 'g' and 'e' is: " << myMax<char>('g', 'e') << endl;
    
    return 0;
}