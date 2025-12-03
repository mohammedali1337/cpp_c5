#include <iostream>
using namespace std;

// downcast
class Base{
    public: 
         void print()
        {
            cout << "Base" << endl;
        }
};

class Drived: public Base{
    public:
        void print()
        {
            cout << "drived" << endl;
        }
};

int main(void)
{
    Drived d1;

    Base *b1 = &d1;

    Drived *d2 = dynamic_cast<Drived*>(b1);

    if (d2 == nullptr)
        cout << "casting failed" << endl;
    else
        cout << "casting successful" << endl;
    return 0;
}