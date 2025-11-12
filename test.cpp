#include <iostream>
#include <stdexcept>
using namespace std;
void func() {
    try {
        throw runtime_error("Something went wrong");
    }
    catch (...) {
        cout << "Caught in func(), rethrowing..." << endl;
        throw; // rethrow the same exception
    }
}
int main(void)
{
    // try {
    //     int age = -5;
    //     if (age < 0)
    //         throw invalid_argument("age cannot be negative \n");
    // }
    // catch (exception &e) {
    //     cout << "error :" << e.what() << endl;
    // }




    //You can use multiple catch blocks to handle different exception types.
    //     try {
    //     throw 42;
    // }
    // catch (int n) {
    //     cout << "Caught an int: " << n << endl;
    // }
    // catch (exception &e) {
    //     cout << "Caught std::exception" << endl;
    // }



    try {
        func();
    }
    catch (exception &e) {
        cout << "Caught in main(): " << e.what() << endl;
    }
}
