// CPP code to illustrate using structure
// #include <stdc++.h>
#include <iostream>
using namespace std;

// creating structure mystruct
struct mystruct {
    int x;
    int y;
    char c;
    bool b;
};

int main()
{
    mystruct s;

    // Assigning values
    s.x = 5;
    s.y = 10;
    s.c = 'a';
    s.b = true;

    // data type must be same during casting
    // as that of original

    // converting the pointer of 's' to,
    // pointer of int type in 'p'.
    int* p = reinterpret_cast<int*>(&s);
    long *pLong = reinterpret_cast<long *>(&s);

    cout << "value of pLong : " << *pLong << endl;

    cout << "size of : " << sizeof(s) << endl;

    // printing the value currently pointed by *p
    cout << "value of p: " << *p << endl;

    // incrementing the pointer by 1
    p++;

    // printing the next integer value
    cout << "value of p after ++p: " << *p << endl;

    p++;

    // we are casting back char * pointed
    // by p using char *ch.
    char* ch = reinterpret_cast<char*>(p);

    // printing the character value
    // pointed by (*ch)
    cout << "value of ch after p++: " << *ch << endl;

    ch++;

    /* since, (*ch) now points to boolean value,
    so it is required to access the value using 
    same type conversion.so, we have used 
    data type of *n to be bool. */

    bool* n = reinterpret_cast<bool*>(ch);

    cout << "value of n after ch++: " << *n << endl;

    // we can also use this line of code to
    // print the value pointed by (*ch).
    cout << *(reinterpret_cast<bool*>(ch));

    return 0;
}