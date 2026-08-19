#include <stdio.h>

// Function to find the upper bound of x
int upperBound(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    // Store n initially.
    // If no element is greater than x,
    // n will be returned.
    int ans = n;

    // Binary Search
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If arr[mid] is greater than x,
        // it can be a possible answer.
        if (arr[mid] > x)
        {
            ans = mid;

            // Search for a smaller index
            // in the left half.
            high = mid - 1;
        }
        else
        {
            // arr[mid] <= x, so this element
            // cannot be the upper bound.
            // Search in the right half.
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    // Sorted input array
    int arr[] = {1, 2, 4, 4, 5, 7};

    // Calculate size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Element whose upper bound is required
    int x = 4;

    // Find upper bound
    int result = upperBound(arr, n, x);

    // Display result
    printf("Upper Bound Index: %d\n", result);

    return 0;
}