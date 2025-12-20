#include <iostream>


using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + 1];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0 ,j = 0, k = left;

    while (i < n1 && j < n2)
    {
        /* code */
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else   
            arr[k++] = R[j++];
    }

    while (i < n1)
    {
        /* code */
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        /* code */
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return ;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main(void)
{
    int ss[] = {4,5,2,8,9,33,22};
    for (int i = 0; i < 7; i++)
    {
        cout << ss[i] << " " ;
    }
    cout << "after use mergeSort algorithm " << endl;
    mergeSort(ss, 0, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << ss[i] << " " ;
    }
}