#include <stdio.h>

// Function to find the index of a peak element
int findPeak(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    // Binary Search
    while (low < high)
    {
        // Find middle element
        int mid = low + (high - low) / 2;

        // If middle element is smaller than the next element,
        // a peak must exist on the right side.
        if (arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            // Otherwise, a peak exists at mid or
            // somewhere on the left side.
            high = mid;
        }
    }

    // low == high, so this is the peak index
    return low;
}

int main()
{
    // Input array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find peak element
    int peakIndex = findPeak(arr, n);

    // Display result
    printf("Peak element: %d\n", arr[peakIndex]);
    printf("Peak index: %d\n", peakIndex);

    return 0;
}