#include <iostream>
#include <deque>
#include <algorithm>


using namespace std;

int main(void)
{
    {

        deque<int> d1;

        deque<int> d2 = {10, 20, 30, 40};

        for (int val : d2)
        {
            cout << val << " ";
        }

        cout << endl;
    }

    {
            deque<int> d;
        
        // Adding elements at the front
        d.push_front(30);
        d.push_front(20);
        d.push_front(10);
        
        // Displaying elements
        cout << "Elements in deque (added using push_front): ";
        for (int val : d) {
            cout << val << " ";
        }
        cout << endl;

    }
    {
        deque<int> d = {10, 20, 30, 40};
        cout << "Original deque: ";
        for (int val : d) {
            cout << val << " ";
        }
        cout << endl;
        
        // Removing the last element
        d.pop_back();
        
        cout << "Deque after pop_back(): ";
        for (int val : d) {
            cout << val << " ";
        }
        cout << endl;

        return 0;
    }

    return 0;
}