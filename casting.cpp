// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

    int n = 10;

    // converting int to double
    double nd = static_cast<double>(n);

    // printing data type
    cout << typeid(n).name() << endl;
    
    // typecasting
    cout << typeid(static_cast<double>(n)).name() << endl;
    
    cout << typeid(static_cast<char>(n)).name() << endl;
    // Printing double type
    cout << typeid(nd).name() << endl;

    return 0;
}