#include <stdio.h>

// Function to find the maximum subarray sum
int maxSubarraySum(int nums[], int n)
{
    // Initialize both variables with the first element
    int maxSum = nums[0];
    int currentSum = nums[0];

    // Traverse the array starting from the second element
    for (int i = 1; i < n; i++)
    {
        // Either extend the previous subarray
        // or start a new subarray from the current element
        if (currentSum + nums[i] > nums[i])
        {
            currentSum = currentSum + nums[i];
        }
        else
        {
            currentSum = nums[i];
        }

        // Update the maximum sum if a larger sum is found
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }

    // Return the maximum subarray sum
    return maxSum;
}

int main()
{
    // Input array
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Calculate the size of the array
    int n = sizeof(nums) / sizeof(nums[0]);

    // Find the maximum subarray sum
    int result = maxSubarraySum(nums, n);

    // Display the result
    printf("Maximum Subarray Sum: %d\n", result);

    return 0;
}