#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left; // initialize indices for L, R and merged array position

    while (i < n1 && j < n2) // while both subarrays have elements
    {
        if (L[i] <= R[j]) // choose smaller element from L or R
            arr[k++] = L[i++]; // place from L and advance L index and k
        else
            arr[k++] = R[j++]; // place from R and advance R index and k
    }

    while (i < n1) // copy any remaining elements from L
    {
        arr[k++] = L[i++]; // copy element and advance indices
    }
    while (j < n2)
    {
        /* code */
        arr[k++] = R[j++];
    }

    // delete[] L; // free temporary left array
    // delete[] R; // free temporary right array
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right) // base case: zero or one element
        return; // nothing to sort

    int mid = left + (right - left) / 2; // compute middle index to split array

    mergeSort(arr, left, mid); // sort left half
    mergeSort(arr, mid + 1, right); // sort right half

    merge(arr, left, mid, right); // merge the two sorted halves
}

int main(void)
{
    int ss[] = {5,2,8,7};
    for (int i = 0; i < 4; i++)
    {
        cout << ss[i] << " " ;
    }
    cout << "after use mergeSort algorithm " << endl;
    mergeSort(ss, 0, 4 - 1);
    for (int i = 0; i < 4; i++)
    {
        cout << ss[i] << " " ;
    }
}