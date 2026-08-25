#include <stdio.h>

// Function to search for target in rotated sorted array
int search(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    // Binary Search
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Target found
        if (arr[mid] == target)
        {
            return mid;
        }

        // Check if the left half is sorted
        if (arr[low] <= arr[mid])
        {
            // Check if target lies within the sorted left half
            if (arr[low] <= target && target < arr[mid])
            {
                // Search in the left half
                high = mid - 1;
            }
            else
            {
                // Search in the right half
                low = mid + 1;
            }
        }

        // Otherwise, the right half is sorted
        else
        {
            // Check if target lies within the sorted right half
            if (arr[mid] < target && target <= arr[high])
            {
                // Search in the right half
                low = mid + 1;
            }
            else
            {
                // Search in the left half
                high = mid - 1;
            }
        }
    }

    // Target not found
    return -1;
}

int main()
{
    // Rotated sorted array
    int arr[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target element
    int target = 3;

    // Search for target
    int result = search(arr, n, target);

    // Display result
    if (result != -1)
    {
        printf("Element %d found at index: %d\n",
               target, result);
    }
    else
    {
        printf("Element %d not found\n", target);
    }

    return 0;
}