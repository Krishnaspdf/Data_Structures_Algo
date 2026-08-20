#include <stdio.h>

// Function to search for target using Binary Search
int binarySearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    // Continue searching while the range is valid
    while (low <= high)
    {
        // Find the middle index
        int mid = low + (high - low) / 2;

        // Target found
        if (arr[mid] == x)
        {
            return mid;
        }

        // If target is greater than middle element,
        // search in the right half
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }

        // If target is smaller than middle element,
        // search in the left half
        else
        {
            high = mid - 1;
        }
    }

    // Target not found
    return -1;
}

int main()
{
    // Sorted array of distinct values
    int arr[] = {1, 3, 5, 7, 9, 11, 13};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target value
    int x = 9;

    // Search for target
    int result = binarySearch(arr, n, x);

    // Display result
    if (result != -1)
    {
        printf("Target found at index: %d\n", result);
    }
    else
    {
        printf("Target not found\n");
    }

    return 0;
}