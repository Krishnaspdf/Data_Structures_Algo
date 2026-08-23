#include <stdio.h>

// Function to find the first occurrence of x
int firstOccurrence(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            // Store the current index
            ans = mid;

            // Continue searching on the left
            // for an earlier occurrence
            high = mid - 1;
        }
        else if (arr[mid] < x)
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

    return ans;
}

// Function to find the last occurrence of x
int lastOccurrence(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            // Store the current index
            ans = mid;

            // Continue searching on the right
            // for a later occurrence
            low = mid + 1;
        }
        else if (arr[mid] < x)
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

    return ans;
}

// Function to count occurrences of x
int countOccurrences(int arr[], int n, int x)
{
    int first = firstOccurrence(arr, n, x);

    // If x is not present
    if (first == -1)
    {
        return 0;
    }

    int last = lastOccurrence(arr, n, x);

    // Number of occurrences
    return last - first + 1;
}

int main()
{
    // Sorted input array
    int arr[] = {2, 2, 3, 3, 3, 3, 4};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Element to search
    int x = 3;

    // Find number of occurrences
    int result = countOccurrences(arr, n, x);

    // Display result
    printf("Number of occurrences of %d: %d\n", x, result);

    return 0;
}
