#include <iostream>
#include <list>

using namespace std;


void print_list(list<int> &aList)
{
    cout << endl << endl;
    for(list<int>::iterator it = aList.begin() ; it != aList.end(); it++)
        cout << *it << "    ";
    cout << endl << endl;
}

bool shouldBeRemoved(const int& value)
{
    if (value > 3)
    {
        return true;
    }
    return false;
}

int main(void)
{
    {
        list<int> myList;

        myList.assign({3, 4, 5});

        for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
            cout << *it << endl;


        myList.push_back(99);
        myList.push_front(8888);

        cout << endl << endl << "after use push back and push front " << endl << endl;
        
        for(list<int>::iterator it = myList.begin(); it != myList.end(); it++)
            cout << *it << endl;
        
        cout << endl << endl << "after use push back and push front " << endl << endl;
        
        myList.emplace_front(12);
        
        
        for(list<int>::iterator it = myList.begin(); it != myList.end(); it++)
            cout << *it << endl;
        
        cout << endl << endl << " " << endl << endl;









        cout << "emplace_front() like push_front()" << endl;

        

    }

    cout << endl << endl << endl << endl << endl << "-------------------------------------------------------------------" << endl << endl;
    
    {
        list<int> myList = {2, 55, 4 , 85, 6};
        
        cout << "List values" << endl;
        
        print_list(myList);
        
        myList.sort();
        
        print_list(myList);
        
        myList.reverse();
        
        print_list(myList);
    }

    cout << endl << endl << endl << endl << endl << "-------------------------------------------------------------------" << endl << endl;

    {
        list<int> list1 = {2, 4 , 6, 3};
        list<int> list2 = {22, 44, 66, 33};

        list1.merge(list2);

        print_list(list1);

        cout << "print list 2 " << endl;
        print_list(list2);
        cout << "is empty() " << (list2.empty()? "yes": "no") << endl;
    }

    {
        list<int> myLIst = {1, 222, 33, 4, 55, 6, 7, 4, 222};

        myLIst.sort();

        myLIst.unique();

        cout << "List values = " << endl;
        print_list(myLIst);
    }

    {
        list<int> myList = {1, 0, 3, 2, 0, 0, 4, 2, 5, 0, 1, 5};

        print_list(myList);
        cout << "use shouldBeRemoved() " << endl;
        myList.remove(5);
        print_list(myList);

        myList.remove_if(shouldBeRemoved);

        cout << "use remove if ()" << endl; 
        print_list(myList);
    }


    {
        // بالإضافة إلى أننا قمنا بإضافة 5 قيم فيه int يمكنه أن يحتوي على عناصر نوعها list هنا قمنا بتعريف كائن من الكلاس
        list<int> myList = {1, 2, 3, 4, 5};
        
        // pop_front() بواسطة الدالة myList هنا قمنا بحذف العنصر الأول من الكائن
        // {2, 3, 4, 5} أصبح فيه القيم التالية myList إذاً الكائن
        myList.pop_front();
        
        // pop_back() بواسطة الدالة myList هنا قمنا بحذف العنصر الأخير من الكائن
        // {2, 3, 4} أصبح فيه القيم التالية myList إذاً الكائن
        myList.pop_back();
        
        cout << "List values in descending order = ";

        // إبتداءاً من آخر عنصر وصولاً لأول عنصر فيه myList هنا قمنا بإنشاء حلقة تقوم في كل دورة بطباعة قيمة عنصر جديد من العناصر الموجودة في الكائن
        for (auto it = myList.rbegin(); it != myList.rend(); ++it)
        {
            cout << *it << " ";
        }
    }

    return 0;
}