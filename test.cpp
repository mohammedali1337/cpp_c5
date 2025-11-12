#include <iostream>
#include <stdexcept>
using namespace std;
// void func() {
//     try {
//         throw runtime_error("Something went wrong");
//     }
//     catch (...) {
//         cout << "Caught in func(), rethrowing..." << endl;
//         throw; // rethrow the same exception
//     }
// }
// int main(void)
// {
//     // try {
//     //     int age = -5;
//     //     if (age < 0)
//     //         throw invalid_argument("age cannot be negative \n");
//     // }
//     // catch (exception &e) {
//     //     cout << "error :" << e.what() << endl;
//     // }




//     //You can use multiple catch blocks to handle different exception types.
//     //     try {
//     //     throw 42;
//     // }
//     // catch (int n) {
//     //     cout << "Caught an int: " << n << endl;
//     // }
//     // catch (exception &e) {
//     //     cout << "Caught std::exception" << endl;
//     // }



//     try {
//         func();
//     }
//     catch (exception &e) {
//         cout << "Caught in main(): " << e.what() << endl;
//     }
// }






int main(void)
{
    int x, y;
    cout << "enter x : " << endl;
    cin >> x;
    cout << "enter y : " << endl;
    cin >> y;
    cout << endl << endl << endl;
    // cout << x / y << endl;
    try{
        if (!y)
        {
            // cout << "y is not valide " << endl;
            throw "division by zero !";
        }
        if (x > 100)
            throw "x older tha 100 !";
        if (y > 200)
            throw y / x;
        if (y < 0)
            throw exception();
        cout << x / y << endl;

    }
    catch(const char * e)
    {
        cout << e << endl;
        cout << "try to enter values other than 0!" << endl;
    }
    catch (int num)
    {

        cout <<" catch for num " << num << endl;
    }

    catch (...)
    {
        cout << "error , try again (random issue )" << endl;
    }

    cout << "hello world " << endl;
    return 0;
}