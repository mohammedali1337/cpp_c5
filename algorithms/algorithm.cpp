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
        vector<string> name = {"mohammed ali", "mohammed", "zakaria"};

        cout << endl << "--------------------- before revsort()-------------------" << endl;
        
        for(auto it=name.begin(); it < name.end(); it++)
        cout << *it << " ";
        
        sort(name.rbegin(), name.rend());
        cout << endl << "--------------------- after revsort()-------------------" << endl;
            
        for(auto it=name.begin(); it < name.end(); it++)
            cout << *it << " ";
        
    }

    {

        cout << endl << endl << endl << "exemple 3 \n\n\n\n\n" ;

        vector<int> num = {11, 3, 22, 40, 6, 9};
        
        sort(num.begin() + 2, num.end());
        
        cout << "after use sort()" << endl;
        
        for (auto it = num.begin(); it < num.end(); it++)
            cout << *it << " " ;
    }
    cout << "\n\n\n\n\n\n";
    
    
    {
        vector<int> numbers = {1, 7, 2, 5, 9, 2};
        
        // Search for the number 3
        auto it = find(numbers.begin(), numbers.end(), 3);
        
        // numbers.shrink_to_fit();
        cout << *(it - 1) << endl;
        cout << *(numbers.end() - 1 )<< endl;
        
        // Check if the number 3 was found
        if (it != numbers.end()) {
            cout << "The number 3 was found!" << "\n";
        } else {
            cout << "The number 3 was not found." << "\n";
        }
        it = find(numbers.begin(), numbers.end(), 9);
        // Check if the number 3 was found
        if (it != numbers.end()) {
            cout << "The number 9 was found!" << "\n";
        } else {
            cout << "The number 9 was not found." << "\n";
        }
    }
    cout << endl << "--------------------ex3------------------" << endl;
    cout << endl << "--------------------ex3------------------" << endl;
    
    {
        vector<int> num = {11, 3, 22, 40, 6, 9};
        sort(num.begin(), num.end());
        
        auto it = upper_bound(num.begin(), num.end(), 27);
        
        cout << *it << endl;
        
        
    }
    cout << endl << "--------------------ex4------------------" << endl;
    
    {
        // Create a vector called numbers that will store integers
        vector<int> numbers = {1, 7, -3, 5, 9, 2};
        
        // Find the smallest number
        auto it = min_element(numbers.begin(), numbers.end());
        cout << *it << endl;
    }
    cout << endl << "--------------------ex5------------------" << endl;
    
    {
        // Create a vector called numbers that will store integers
        vector<int> numbers = {1, 7, 3, 5, 9, 2};
        
        // Find the largest number
        auto it = max_element(numbers.begin(), numbers.end());
        
        cout << *it << endl;
    }
    
    cout << endl << "--------------------ex6------------------" << endl;


    {
        // Create a vector called numbers that will store integers
        vector<int> numbers = {1, 7, 3, 5, 9, 2};

        // Create a vector called copiedNumbers that should store 6 integers
        vector<int> copiedNumbers(6);

        // Copy elements from numbers to copiedNumbers
        
        
        for (auto it = numbers.begin(); it < numbers.end(); it++)
        cout << *it << " " ;
        
        cout << endl << endl;
        
        for (auto it = copiedNumbers.begin(); it < copiedNumbers.end(); it++)
        cout << *it << " " ;
        
        copy(numbers.begin(), numbers.end(), copiedNumbers.begin());
        cout << endl << endl;
        
        for (auto it = copiedNumbers.begin(); it < copiedNumbers.end(); it++)
        cout << *it << " " ;
    }
    cout << endl << "-----------------------------------------" << endl;
    {
        // Create a vector called numbers that will store 6 integers
        vector<int> numbers(6);
        
        for (auto it = numbers.begin(); it < numbers.end(); it++)
        cout << *it << " " ;
        cout << endl;
        // Fill all elements in the numbers vector with the value 35
        fill(numbers.begin(), numbers.end(), 35);
        for (auto it = numbers.begin(); it < numbers.end(); it++)
        cout << *it << " " ;
    }
    
    
    return 0;
}
