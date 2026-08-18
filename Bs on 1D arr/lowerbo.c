#include <stdio.h>

// Function to find the lower bound of x
int lowerBound(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    // Store n as the default answer
    // if no element is greater than or equal to x
    int answer = n;

    // Binary search
    while (low <= high)
    {
        // Find the middle index
        int mid = low + (high - low) / 2;

        // If arr[mid] is greater than or equal to x,
        // it can be a possible lower bound
        if (arr[mid] >= x)
        {
            answer = mid;

            // Search for an earlier valid index
            high = mid - 1;
        }
        else
        {
            // arr[mid] is smaller than x,
            // so search in the right half
            low = mid + 1;
        }
    }

    return answer;
}

int main()
{
    // Sorted input array
    int arr[] = {1, 2, 2, 3};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target value
    int x = 2;

    // Find the lower bound
    int result = lowerBound(arr, n, x);

    // Display the result
    printf("Lower Bound Index: %d\n", result);

    return 0;
}
