#include <iostream>
#include <string>


using namespace std;

int *insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i -1;
        while (j>=0 && arr[j] > key)
        {
            /* code */
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}


int main(int c, char **v)
{



    int ss[] = {4,5,2,8,9,33,22};
    for (int i = 0; i < 7; i++)
    {
        cout << ss[i] << " " ;
    }
    cout << "before sort" << endl;


    int *arr = insertionSort(ss, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;

    return 0;
    
}
