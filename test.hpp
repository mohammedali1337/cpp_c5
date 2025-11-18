#include <iostream>
using namespace std;

class Test
{
    protected:
        int x;
    public:
        Test(int num);
        virtual ~Test();
         virtual void printzebi() ;
};


class draved_Test: public Test
{
    private:
        int ss;
    public:
        virtual void printzebi();
        draved_Test(int l);
       virtual ~draved_Test();
};