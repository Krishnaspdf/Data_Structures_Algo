#include <stdio.h>

// Function to find the maximum product subarray
int maxProduct(int nums[], int n)
{
    // Maximum product ending at current position
    int maxProduct = nums[0];

    // Minimum product ending at current position
    // This is needed because a negative number
    // can turn the minimum into the maximum
    int minProduct = nums[0];

    // Store the overall maximum product
    int result = nums[0];

    // Traverse the array from the second element
    for (int i = 1; i < n; i++)
    {
        // If current number is negative,
        // swap maximum and minimum products
        if (nums[i] < 0)
        {
            int temp = maxProduct;
            maxProduct = minProduct;
            minProduct = temp;
        }

        // Either start a new subarray from the current element
        // or extend the previous subarray
        if (nums[i] > maxProduct * nums[i])
        {
            maxProduct = nums[i];
        }
        else
        {
            maxProduct = maxProduct * nums[i];
        }

        // Calculate the minimum product ending at current index
        if (nums[i] < minProduct * nums[i])
        {
            minProduct = nums[i];
        }
        else
        {
            minProduct = minProduct * nums[i];
        }

        // Update the overall maximum product
        if (maxProduct > result)
        {
            result = maxProduct;
        }
    }

    return result;
}

int main()
{
    // Input array
    int nums[] = {1, 2, 3, 4, 5, 0};

    // Calculate size of the array
    int n = sizeof(nums) / sizeof(nums[0]);

    // Find maximum product
    int result = maxProduct(nums, n);

    // Display the result
    printf("Maximum Product Subarray: %d\n", result);

    return 0;
}