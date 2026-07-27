#include <stdio.h>

// Function to rearrange the array
void rearrangeArray(int nums[], int n)
{
    // Create an auxiliary array to store the result
    int ans[n];

    // Index for placing positive numbers
    int posIndex = 0;

    // Index for placing negative numbers
    int negIndex = 1;

    // Traverse the original array
    for (int i = 0; i < n; i++)
    {
        // If the element is positive,
        // place it at the next even index
        if (nums[i] > 0)
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
        // If the element is negative,
        // place it at the next odd index
        else
        {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }

    // Copy the rearranged elements back to the original array
    for (int i = 0; i < n; i++)
    {
        nums[i] = ans[i];
    }
}

int main()
{
    // Input array
    int nums[] = {3, 1, -2, -5, 2, -4};

    // Calculate the size of the array
    int n = sizeof(nums) / sizeof(nums[0]);

    // Rearrange the array
    rearrangeArray(nums, n);

    // Display the rearranged array
    printf("Rearranged Array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}