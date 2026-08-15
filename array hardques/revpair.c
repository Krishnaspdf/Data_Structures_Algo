#include <stdio.h>

// Function to count reverse pairs across two sorted halves
long long countPairs(int arr[], int low, int mid, int high)
{
    int j = mid + 1;
    long long count = 0;

    // Count pairs where arr[i] > 2 * arr[j]
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && (long long)arr[i] > 2LL * arr[j])
        {
            j++;
        }

        // All elements from mid + 1 to j - 1
        // form a reverse pair with arr[i]
        count += (j - (mid + 1));
    }

    return count;
}

// Function to merge two sorted halves
void merge(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1];

    int i = low;
    int j = mid + 1;
    int k = 0;

    // Merge both sorted halves
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from left half
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right half
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back into original array
    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }
}

// Merge Sort function
long long mergeSort(int arr[], int low, int high)
{
    long long count = 0;

    // Base condition
    if (low >= high)
    {
        return 0;
    }

    int mid = low + (high - low) / 2;

    // Count reverse pairs in left half
    count += mergeSort(arr, low, mid);

    // Count reverse pairs in right half
    count += mergeSort(arr, mid + 1, high);

    // Count reverse pairs between the two halves
    count += countPairs(arr, low, mid, high);

    // Merge the two sorted halves
    merge(arr, low, mid, high);

    return count;
}

// Function to count total reverse pairs
long long reversePairs(int arr[], int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    // Input array
    int arr[] = {1, 3, 2, 3, 1};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Count reverse pairs
    long long result = reversePairs(arr, n);

    // Display the result
    printf("Number of Reverse Pairs: %lld\n", result);

    return 0;
}
