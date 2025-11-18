#include "test.hpp"

Test::Test(int num): x(num){
    cout << "constror for base class is called \n";
}

Test::~Test(){
    cout << "destructor for base class is called \n";
}

draved_Test::draved_Test(int l): Test(l){
    cout << "drived constructor " << endl;
}

draved_Test::~draved_Test(){
    cout << "drived destructor  " << endl;
}

void Test::printzebi()
{
    cout << "zebi from base" << endl;
}
void draved_Test::printzebi()
{
    cout << "zebi from drived class " << endl;
}

int main(void)
{
    Test *ob = new draved_Test(5);
    ob->printzebi();
    delete ob;
    return 0;
}