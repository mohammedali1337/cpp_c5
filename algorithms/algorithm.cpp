#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    {
        vector<string> cars = {"volvo", "bmw", "ford", "mazda"};
        
        cout << endl <<  "-----------------befor sort()--------------" << endl;
        
        for(auto it=cars.begin(); it < cars.end(); it++)
            cout <<*it << " " ;

        sort(cars.begin(), cars.end());

        cout << endl <<  "-----------------after sort()--------------" << endl;
        for(auto it=cars.begin(); it < cars.end(); it++)
            cout <<*it << " " ;
    }

    {
        
    }
}