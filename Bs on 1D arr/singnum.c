#include <stdio.h>

// Function to find the element that appears only once
int findSingle(int arr[], int n)
{
    int result = 0;

    // XOR all elements of the array
    for (int i = 0; i < n; i++)
    {
        result = result ^ arr[i];
    }

    // Duplicate elements cancel each other,
    // leaving only the single element
    return result;
}

int main()
{
    // Input array
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    // Calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the single number
    int result = findSingle(arr, n);

    // Display the result
    printf("The single number is: %d\n", result);

    return 0;
}