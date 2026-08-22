#include <stdio.h>

// Function to find the last occurrence of target
int lastOccurrence(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    // Store the answer
    // -1 means target has not been found
    int ans = -1;

    // Binary Search
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Target found
        if (arr[mid] == target)
        {
            // Store the current index
            ans = mid;

            // Continue searching on the right side
            // to find a later occurrence
            low = mid + 1;
        }

        // Target is smaller than middle element
        else if (target < arr[mid])
        {
            // Search in the left half
            high = mid - 1;
        }

        // Target is greater than middle element
        else
        {
            // Search in the right half
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    // Sorted input array
    int arr[] = {3, 4, 13, 13, 13, 20, 40};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target element
    int target = 13;

    // Find last occurrence
    int result = lastOccurrence(arr, n, target);

    // Display result
    printf("Last occurrence of %d is at index: %d\n",
           target, result);

    return 0;
}
