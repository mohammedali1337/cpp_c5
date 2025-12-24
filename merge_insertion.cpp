#include <iostream>
using namespace std;

/* Insertion Sort */
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* Merge two sorted parts */
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

/* Merge-Insertion Sort */
void mergeInsertionSort(int arr[], int left, int right)
{
    cout << "right - left : " << right - left << endl;
    if (right - left <= 10) // threshold
    {
        insertionSort(arr, left, right);
        return;
    }

    int mid = (left + right) / 2;
    mergeInsertionSort(arr, left, mid);
    mergeInsertionSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

/* Test */
int main()
{
    int arr[] = {9, 3, 7, 1, 5, 4, 8, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeInsertionSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
