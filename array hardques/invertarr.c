#include <stdio.h>

// Function to merge two sorted parts and count inversions
long long merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;       // Starting index of left subarray
    int j = mid + 1;    // Starting index of right subarray
    int k = left;       // Index for temporary array

    long long inversions = 0;

    // Compare elements of both subarrays
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            // arr[i] > arr[j]
            // All remaining elements from i to mid
            // will also form inversions with arr[j]
            temp[k++] = arr[j++];

            inversions += (mid - i + 1);
        }
    }

    // Copy remaining elements from left subarray
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right subarray
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back into original array
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inversions;
}

// Function to perform merge sort and count inversions
long long mergeSort(int arr[], int temp[], int left, int right)
{
    long long inversions = 0;

    // Continue only if more than one element exists
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Count inversions in the left half
        inversions += mergeSort(arr, temp, left, mid);

        // Count inversions in the right half
        inversions += mergeSort(arr, temp, mid + 1, right);

        // Count inversions while merging both halves
        inversions += merge(arr, temp, left, mid, right);
    }

    return inversions;
}

// Function to count total inversions
long long countInversions(int arr[], int n)
{
    // Temporary array required for merge sort
    int temp[n];

    return mergeSort(arr, temp, 0, n - 1);
}

int main()
{
    // Input array
    int arr[] = {5, 3, 2, 1, 4};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Count inversions
    long long result = countInversions(arr, n);

    // Display result
    printf("Number of Inversions: %lld\n", result);

    return 0;
}