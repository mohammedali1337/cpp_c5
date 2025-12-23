#include <iostream>

using namespace std;

static int x = 0;

/**
 * Merges two sorted contiguous subarrays of an integer array into a single sorted segment.
 *
 * Preconditions:
 *  - arr[left..mid] and arr[mid+1..right] are individually sorted in non-decreasing order.
 *
 * Parameters:
 *  - arr   : array of integers that will be modified.
 *  - left  : starting index of the first sorted subarray (inclusive).
 *  - mid   : ending index of the first sorted subarray (inclusive); second subarray starts at mid+1.
 *  - right : ending index of the second sorted subarray (inclusive).
 *
 * Behavior:
 *  - Copies the two subarrays into temporary buffers L and R (sizes n1 = mid-left+1, n2 = right-mid).
 *  - Repeatedly selects the smaller next element from L or R and writes it back into arr[k],
 *    advancing indices accordingly, until one buffer is exhausted.
 *  - Copies any remaining elements from the non-exhausted buffer into arr.
 *
 * Side effects:
 *  - Overwrites arr[left..right] with the merged, sorted sequence.
 *  - Emits debug output to std::cout (merge call count and indices) and depends on a global counter `x`.
 *
 * Complexity:
 *  - Time: O(n1 + n2) = O(right - left + 1).
 *  - Extra space: O(n1 + n2) for the temporary buffers.
 *
 * Stability:
 *  - The merge is stable: when elements are equal, the element from the left subarray is taken first.
 *
 * Typical use:
 *  - Used as the merge step in a merge sort implementation.
 */
/**
 * @brief Merges two sorted subarrays into a single sorted array.
 * 
 * This function takes two adjacent sorted subarrays within an array and merges them
 * into a single sorted subarray. It is a key component of the merge sort algorithm.
 * 
 * @param arr[] The array containing the two sorted subarrays to be merged.
 * @param left The starting index of the first sorted subarray.
 * @param mid The ending index of the first sorted subarray (also marks the start of the second subarray at mid + 1).
 * @param right The ending index of the second sorted subarray.
 * 
 * @details
 * - Creates two temporary arrays L and R to hold the left and right subarrays.
 * - Copies elements from the original array into L and R.
 * - Compares elements from L and R, placing the smaller element into the original array.
 * - Copies any remaining elements from L or R back to the original array.
 * - Time Complexity: O(n) where n = right - left + 1
 * - Space Complexity: O(n) for the temporary arrays L and R
 * 
 * @note This function includes debug output that prints the merge count and index information.
 */
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    cout << "merge called " << ++x << " times" << endl;
    cout << "left: " << left << ", mid: " << mid << ", right: " << right << endl;

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

}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right) // base case: zero or one element
        return; // nothing to sort

    int mid = left + (right - left) / 2; // compute middle index to split array

    cout << "mergeSort called with left: " << left << ", right: " << right << endl;

    mergeSort(arr, left, mid); // sort left half
    mergeSort(arr, mid + 1, right); // sort right half

    merge(arr, left, mid, right); // merge the two sorted halves
}

int main(void)
{
    int ss[] = {5,2,8,7, 3, 11, 0};
    for (int i = 0; i < 7; i++)
    {
        cout << ss[i] << " " ;
    }
    cout << "after use mergeSort algorithm " << endl;
    mergeSort(ss, 0, 4 - 1);
    cout << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << ss[i] << " " ;
    }
}