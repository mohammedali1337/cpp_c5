#include <iostream>
#include <vector>


using namespace std;

int main(void)
{
    {vector<string> myVector;

    myVector.push_back("one");
    myVector.push_back("two");
    myVector.push_back("three");
    myVector.push_back("four");
    myVector.push_back("five");


    cout << "vector size = " << myVector.size() << endl;

    cout << "vectors capacity = " << myVector.capacity() << endl;

    cout << "vectors max size = " << myVector.max_size() << endl;

    if (!myVector.empty())
    {
        cout << "vector first element value = " << myVector.front() << endl;
        cout << "vector last element value = " << myVector.back() << endl;
    }

    for (int i = 0 ; i < myVector.size() ; i++)
        cout << myVector[i] << endl;}





    {
        vector<int> myVector = {1, 2, 3, 4, 5, 6, 7 ,8, 9};

        cout << std::endl << "all elemment of my vectors: "<< endl;
        for (int i = 0; i < myVector.size(); i++)
            cout << myVector[i] << endl;

        myVector.pop_back();
        cout << std::endl << "after pop_back(): "<< endl;
        for (int i = 0; i < myVector.size(); i++)
            cout << myVector[i] << endl;

        myVector.erase(myVector.begin() + 2);
        cout << std::endl << "--------------------------------after erase(): --------------------------"<< endl;
        for (int i = 0; i < myVector.size(); i++)
            cout << myVector[i] << endl;


    }



    {
        vector<int> myVector = {1, 4, 3, 4, 5};

        cout << endl << "begin(): " << *(myVector.rbegin() + 1) << endl;
        cout << endl << "end(): " << *(myVector.rend() - 1) << endl;

        cout << "vector value from begin to end = ";

        for (auto it = myVector.begin(); it < myVector.end(); it++)
            cout << *it << " " ;

        cout << "\nVector values from end to begin = ";

        for (auto it=myVector.rbegin(); it < myVector.rend(); it++)
            cout << *it << " ";
    }



    {
        vector<int> myVector;

        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);
        myVector.push_back(4);
        myVector.push_back(5);

        cout << "vector size = " << myVector.size() << endl;

        cout << "vector capacity = " << myVector.capacity() << endl;

        myVector.shrink_to_fit();

        cout << "--------------------------after shrinking the vector----------------------" << endl;

        cout << "vector size = " << myVector.size() << endl;

        cout << "vector capacity = " << myVector.capacity() << endl;


    }










    {
        vector<int> myVector = {1, 2, 3, 4, 5};

        myVector.insert(myVector.begin() + 2, 8);

        cout << "vector values = " ;
        for (size_t i = 0 ; i < myVector.size(); i++)
            cout << myVector[i] << " ";

        myVector.insert(myVector.begin() + 3, 111);
        for (size_t i = 0 ; i < myVector.size(); i++)
            cout << myVector[i] << " ";
    }
    return 0;







}