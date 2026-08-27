#include <stdio.h>

// Function to find the minimum element
int findMinimum(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        // Find middle element
        int mid = low + (high - low) / 2;

        // If middle element is greater than the last element,
        // the minimum lies in the right half
        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else
        {
            // Minimum lies at mid or in the left half
            high = mid;
        }
    }

    // low and high point to the minimum element
    return arr[low];
}

int main()
{
    // Rotated sorted array
    int arr[] = {4, 5, 6, 7, 0, 1, 2, 3};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find minimum element
    int result = findMinimum(arr, n);

    // Display result
    printf("Minimum element: %d\n", result);

    return 0;
}