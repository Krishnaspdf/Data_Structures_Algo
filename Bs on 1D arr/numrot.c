#include <stdio.h>

// Function to find the number of rotations
int findRotations(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    // Index of the minimum element
    int minIndex = 0;

    while (low <= high)
    {
        // If the current range is already sorted,
        // the first element is the minimum.
        if (arr[low] <= arr[high])
        {
            if (arr[low] < arr[minIndex])
            {
                minIndex = low;
            }

            break;
        }

        // Find the middle element
        int mid = low + (high - low) / 2;

        // If mid element is smaller than current minimum,
        // update the minimum index.
        if (arr[mid] < arr[minIndex])
        {
            minIndex = mid;
        }

        // Check which half contains the minimum
        if (arr[mid] >= arr[low])
        {
            // Left half is sorted,
            // so minimum lies in the right half.
            low = mid + 1;
        }
        else
        {
            // Minimum lies in the left half.
            high = mid - 1;
        }
    }

    return minIndex;
}

int main()
{
    // Rotated sorted array
    int arr[] = {4, 5, 6, 7, 0, 1, 2, 3};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find number of rotations
    int rotations = findRotations(arr, n);

    // Display result
    printf("Number of rotations: %d\n", rotations);

    return 0;
}