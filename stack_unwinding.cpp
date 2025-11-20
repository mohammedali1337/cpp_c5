#include <iostream>

using namespace std;

class test
{
    public:
        test(){
            cout << "constructor is called _________________\n";
        }
        ~test()
        {
            cout << "destructor for test is called ++++++++++++++++++\n";
        }
};

void f1()
{
    test ob;
    cout << "f1() start\n";
    throw 100;
    cout << "f1() end\n";
}

void f2()
{
    test ob;
    cout << "f2() start \n";
    f1();
    cout << "f2() end \n";
}

void f3()
{
    cout << "f3() start \n";
    try
    {
        f2();
    }
    catch(int i)
    {
        cout << "caught exception: " << '\n';
    }
    cout << "f3() endl";
}

int main(void)
{
    f3();
    return 0;
}