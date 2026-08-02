#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort()
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function to find the length of the longest consecutive sequence
int longestConsecutive(int nums[], int n)
{
    // If the array is empty
    if (n == 0)
    {
        return 0;
    }

    // Sort the array
    qsort(nums, n, sizeof(int), compare);

    // Variables to store current and longest sequence length
    int currentLength = 1;
    int longestLength = 1;

    // Traverse the sorted array
    for (int i = 1; i < n; i++)
    {
        // Ignore duplicate elements
        if (nums[i] == nums[i - 1])
        {
            continue;
        }

        // If current element is consecutive
        if (nums[i] == nums[i - 1] + 1)
        {
            currentLength++;
        }
        else
        {
            // Start a new sequence
            currentLength = 1;
        }

        // Update the longest sequence
        if (currentLength > longestLength)
        {
            longestLength = currentLength;
        }
    }

    // Return the answer
    return longestLength;
}

int main()
{
    // Input array
    int nums[] = {100, 4, 200, 1, 3, 2};

    // Calculate the size of the array
    int n = sizeof(nums) / sizeof(nums[0]);

    // Find the longest consecutive sequence
    int result = longestConsecutive(nums, n);

    // Display the result
    printf("Length of Longest Consecutive Sequence: %d\n", result);

    return 0;
}
