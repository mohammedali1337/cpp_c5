#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // to avoid potential overflow
        cout << mid << " " << endl;

        if (arr[mid] == target)
            return mid; // target found at index mid
        else if (arr[mid] < target)
            left = mid + 1; // search in the right half
        else
            right = mid - 1; // search in the left half
            
    }

    return -1; // target not found
}
/// @brief 
/// @param arr 
/// @param left 
/// @param right 
/// @param target 
/// @return 
int binarySearchRecursive(int arr[], int left, int right, int target)
{
    if(left <= right)
    {
        int mid = right - (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] < target)
            return binarySearchRecursive(arr, mid, right, target);
        
        return binarySearch(arr, left, mid, target);
        return -1;
    }
}


int main()
{
    int arr[] = {2, 3, 4,5,7, 10, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "size: " <<  size << endl;
    int target = 3;
    int result = binarySearch(arr, size, target);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in array" << endl;
    return 0;
}